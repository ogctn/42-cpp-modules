#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() { readData(DATA_CSV, _priceData, ','); }

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	*this = other;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &other) {
	_priceData = other._priceData;
	_input = other._input;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string dataset) { readData(dataset, _priceData, ','); }

std::vector<std::string>	BitcoinExchange::getPriceData() const { return _priceData; }
std::vector<std::string>	BitcoinExchange::getInput() const { return _input; }
std::vector<std::string>	BitcoinExchange::getResult() const { return _result; }

template <typename From, typename To>
To	_converter(const From &from) {
	std::stringstream ss(from);
	
	To converted;
	ss >> converted;
	if (ss.fail())
		throw std::invalid_argument("Invalid argument");
	return (converted);
}
void	clear_wspace(std::string &s) {
	size_t i = 0;

	while (i != std::string::npos) {
		i = s.find_first_of(" \t\n\v\f\r", i);
		if (i != std::string::npos)
			s.erase(i, 1);
	}
}

std::string	getDate() {
	time_t		raw = std::time(0);
	struct tm	tstruct = *std::localtime(&raw);
	char		buf[80];

	memset(buf, 0, sizeof(buf));
	std::strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct);

	return (buf);
}

bool	checkFloatFormat(std::string str) {
	size_t pos;

	if (str.find_first_not_of("0123456789+-.") != std::string::npos)
		return (true);

	if (str.find_first_not_of("+-.") == std::string::npos)
		return (true);

	pos = str.find_first_of("+-", 0);
	if ((pos != std::string::npos && pos > 0) || str.find_first_of("+-", pos + 1) != std::string::npos)
		return (true);

	pos = str.find_first_of(".", 0);
	if (str.find_first_of(".", pos + 1) != std::string::npos)
		return (true);

	if ((str[0] == '+' || str[0] == '-')) {
		if (str[1] == '.' && str.find_first_of("0123456789", 2) == std::string::npos) {
			return (true);
		}
		else if (str.find_first_of("0123456789", 1) == std::string::npos)
			return (true);
	}
	else {
		if (str[0] == '.' && str.find_first_of("0123456789", 1) == std::string::npos)
			return (true);
	}

	return (false);
}

bool isLeapYear(int year) { return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)); }

bool dateExists(const std::string& date) {
    int year, month, day;
    char dash;

    std::istringstream dateStream(date);
    dateStream >> year >> dash >> month >> dash >> day;

    if (month < 1 || month > 12)
        return (false);

    int daysInMonth;
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            daysInMonth = 31;
            break;
        case 4: case 6: case 9: case 11:
            daysInMonth = 30;
            break;
        case 2:
            daysInMonth = isLeapYear(year) ? 29 : 28;
            break;
        default:
            return (false);
    }
    return (day >= 1 && day <= daysInMonth);
}

std::string invalidFormat(std::string &line, char delimiter) {
		std::string tmp, res;
		size_t 		delim_pos;

		delim_pos = line.find_first_of(delimiter);
		if (delim_pos == std::string::npos)
			return("# Bad format, missing delimiter \"" + std::string(1, delimiter) + "\".");

		tmp = line.substr(0, delim_pos);
		std::tm d;
		if (strptime(tmp.c_str(), "%Y-%m-%d", &d) == NULL || !dateExists(tmp))
			return("# Date does not exist.");

		tmp = line.substr(delim_pos + 1, line.size() - delim_pos);
		if (checkFloatFormat(tmp))
			return("# Bad format, check after delimiter.");

		try {
			float value = _converter<std::string, float>(tmp);
			if (value < 0)
				return("# Value must be positive.");
			if (delimiter == '|' && value > 1000)
				return ("# Value must be in range [0 1000].");
		} catch (std::invalid_argument &e) {
			return ("# Bad format, check after delimiter.");
		}

		

		return ("");
}

int	fillData(std::vector<std::string> &data, char delimiter, std::vector<std::string> &result) {
	
	if (data.empty() || data.size() < 2)
		return (std::cout << "# No data to import\n", 1);

	if (delimiter == ',' && data[0] != "date,exchange_rate")
		return (std::cout << "# First line must be \"date,exchange_rate\"\n", 1);
	if (delimiter == '|' && data[0] != "date | value")
		return (std::cout << "# First line must be \"date | value\"\n", 1);

	std::string res;
	size_t 		delim_pos;
	for (size_t i = 1; i < data.size(); ++i) {

		res.clear();
		clear_wspace(data[i]);

		if (data[i].empty())
			continue;

		delim_pos = data[i].find_first_of(delimiter);
		res = invalidFormat(data[i], delimiter);
		if (!res.empty()) {
			if (delimiter == ',')
				return (std::cout << res, i + 1);
			res.insert(1, "error: line \'" + std::to_string(i + 1) + "\': ");
		}
		else
			res = data[i].substr(0, delim_pos) + " => " + data[i].substr(delim_pos + 1, data[i].size() - delim_pos - 1) + " = ";
		
		if (delimiter == '|')
			result.push_back(res);
		
	}
	return (0);
}

void	BitcoinExchange::readData(std::string src, std::vector<std::string> &dest, char delimiter) {
	std::ifstream src_file(src);
	if (!src_file.is_open()) {
		std::cerr << "error: " << strerror(errno) << std::endl;
		exit (1);
	}

	std::string	line;
	while (std::getline(src_file, line))
		dest.push_back(line);

	int error_at = fillData(dest, delimiter, _result);
	if (error_at == 1 || (error_at && delimiter == ',')) {
		std::cerr << "\nerror: invalid data. Check line \"" << error_at << "\" in file \"" << src << "\"." << std::endl;
		std::cerr << "Exiting..." << std::endl;
		exit (1);
	}
	src_file.close();

	dest.erase(dest.begin());
	std::vector<std::string>::iterator it = dest.begin();
	while (it != dest.end()) {
		if (it->empty())
			it = dest.erase(it);
		else
			++it;
	}	
}

void	BitcoinExchange::printData(const std::vector<std::string> &data) {
	if (data.empty()) {
		std::cerr << "error: no data to print." << std::endl;
		return;
	}
	for (std::vector<std::string>::const_iterator it = data.begin(); it != data.end(); it++) {
		std::cout << *it << std::endl;
	}
}

float BitcoinExchange::findClosest(const std::string &find) const {
	t_date		date;
	std::string	tmp;
	double		value;
	std::stringstream tmp_ss;

	float		closest = 0;
	// float		diff = 0;
	// float		tmp_diff = 0;

	std::tm d;
	memset(&d, 0, sizeof(d));
	if (strptime(find.substr(0, 10).c_str(), "%Y-%m-%d", &d) == NULL || !dateExists(find.substr(0, 10)))
		return (std::cerr << "error: invalid date format." << std::endl, -1);

	date.year = d.tm_year + 1900;
	date.month = d.tm_mon + 1;
	date.day = d.tm_mday;
	try {
		value = _converter<std::string, double>(find.substr(11, find.size() - 11));
	} catch (std::invalid_argument &e) {
		return (std::cerr << "error: invalid value format." << std::endl, -1);
	}


	
	for (size_t i = 0; i < getPriceData().size(); ++i) {
		
	}

	return (closest);
}

void	BitcoinExchange::calculate(const std::string &input_file) {
	std::vector<std::string>	result;
	float closest;

	readData(input_file, _input, '|');

	printData(getResult());
exit(1);
	closest = findClosest(_input[1]);

	for (size_t i = 0; i < _input.size(); ++i) {
		if (_input[i].empty())
			continue;
		closest = findClosest(_input[i]);

	}
}

