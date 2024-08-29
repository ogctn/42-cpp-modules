#include "BitcoinExchange.hpp"

struct ContainsSubstring {
    std::string find;

    ContainsSubstring(const std::string& value) : find(value) {}

    bool operator()(const std::string& str) const {
        return (str.find(find) != std::string::npos);
    }
};

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

template <typename T>
T	_stoval(const std::string &from) {
	std::stringstream ss(from);
	
	T converted;
	ss >> converted;
	if (ss.fail())
		throw std::invalid_argument("Invalid argument");
	return (converted);
}

std::vector<std::string>	BitcoinExchange::getPriceData() const { return _priceData; }
std::vector<std::string>	BitcoinExchange::getInput() const { return _input; }
std::vector<std::string>	BitcoinExchange::getResult() const { return _result; }

std::string BitcoinExchange::getLineByFind(const std::vector<std::string> &vec, const std::string &find) const {
	ContainsSubstring pred(find);

	std::vector<std::string>::const_iterator it = std::find_if(vec.cbegin(), vec.cend(), pred);
	if (it != vec.cend())
		return (*it);
	return ("");
}

std::string	BitcoinExchange::parseDate(const std::string &line) const {

	std::string tmp;
	size_t delim_pos;

	std::tm d;
	memset(&d, 0, sizeof(d));
	delim_pos = line.find_first_of("-", 0);
	delim_pos = line.find_first_of("-", delim_pos + 1);
	delim_pos = line.find_first_not_of("0123456789", delim_pos + 1);

	tmp = line.substr(0, delim_pos);
	if (strptime(tmp.c_str(), "%Y-%m-%d", &d) == NULL)
		tmp = "";
	return (tmp);
}

float	BitcoinExchange::parseVal(const std::string &line) const {

	std::string tmp;
	size_t delim_pos;

	delim_pos = line.find_first_of("-", 0);
	delim_pos = line.find_first_of("-", delim_pos + 1);
	delim_pos = line.find_first_not_of("0123456789", delim_pos + 1);

	tmp = line.substr(delim_pos + 1, line.size() - delim_pos - 1);
	return (_stoval<float>(tmp));
}

void	clear_wspace(std::string &s) {
	size_t i = 0;

	while (i != std::string::npos) {
		i = s.find_first_of(" \t\n\v\f\r", i);
		if (i != std::string::npos)
			s.erase(i, 1);
	}
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
			float value = _stoval<float>(tmp);
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
		return (std::cout << "# No data to import", 1);

	if (delimiter == ',' && data[0] != "date,exchange_rate")
		return (std::cout << "# First line must be \"date,exchange_rate\"", 1);
	if (delimiter == '|' && data[0] != "date | value")
		return (std::cout << "# First line must be \"date | value\"", 1);

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
		std::cerr << "No data to print." << std::endl;
		return;
	}
	for (std::vector<std::string>::const_iterator it = data.begin(); it != data.end(); it++)
		std::cout << *it << std::endl;

}

float BitcoinExchange::findClosestPrice(const std::string &res_line) const {
return (2);
/* 	t_date		date;
	std::string	tmp;
	std::stringstream tmp_ss;
	float		value, closest=0;//, diff, tmp_diff;
	size_t 		p1, p2;

	tmp = parseDate(res_line);
	date.year = d.tm_year + 1900;	date.month = d.tm_mon + 1;	date.day = d.tm_mday;


	std::vector<std::string>::const_iterator it;
	it = std::find(_priceData.begin(), _priceData.end(), tmp);
	if (it != _priceData.end()) {
		p1 = it->find_first_of(",");
		tmp = it->substr(p1 + 1, it->size() - p1 - 1);
		closest = _stoval<float>(tmp);
	}

	try {
		p1 = res_line.find_first_of(">") + 2;
		p2 = res_line.find_first_of("=", 12) - 1;
		tmp = res_line.substr(p1, p2 - p1);;
		value = _stoval<double>(tmp);
		return (closest * value);
	} catch (std::invalid_argument &e) {
		return (std::cerr << "error: invalid value format." << std::endl, -1);
	}
	// for (size_t i = 0; i < getPriceData().size(); ++i) {
		
	// }

	return (closest); */
}

void	BitcoinExchange::calculate(const std::string &input_file) {

	float closest=0;
	size_t 		p1, p2;
	std::string str_val;

	readData(input_file, _input, '|');

	std::vector<std::string>::iterator it;
	for (it = _result.begin(); it != _result.end(); ++it) {
		
		if ((*it).find_first_of("#error") != std::string::npos)
			continue;

		closest = findClosestPrice(*it);
		if (closest != -1) {
			p1 = it->find_first_of(">") + 2;
			p2 = it->find_first_of("=", 12) - 1;
			str_val = it->substr(p1, p2 - p1);
			it->append(std::to_string(closest * _stoval<float>(str_val)));
		}
	}
	
}

