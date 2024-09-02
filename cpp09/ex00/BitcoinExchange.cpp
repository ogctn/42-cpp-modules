#include "BitcoinExchange.hpp"

struct ContainsSubstring {
    std::string find;

    ContainsSubstring(const std::string& value) : find(value) {}

    bool operator()(const std::string& str) const {
        return (str.find(find) != std::string::npos);
    }
};

BitcoinExchange::BitcoinExchange() { readData(DATA_CSV, ','); }

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	*this = other;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &other) {
	_priceData = other._priceData;
	_input = other._input;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string dataset) { readData(dataset, ','); }

void	BitcoinExchange::printData(const std::vector<std::string> &vec) const {
	if (vec.empty()) {
		std::cerr << "No data to print." << std::endl;
		return;
	}
	for (std::vector<std::string>::const_iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << std::endl;
}

template <typename T>
T	_stoval(const std::string &from) {
	std::stringstream ss(from);
	
	T converted;
	ss >> converted;
	return (converted);
}

template <typename T>
std::string _to_str(const T n) {
	std::stringstream ss;

	ss << n;
	return (ss.str());
}

long _dateToLong(const std::string &date) {
	std::istringstream iss(date);
	std::ostringstream oss;
	int year, month, day;
	char dash;

	iss >> year >> dash >> month >> dash >> day;
	oss << year << (month < 10 ? "0" : "") << month << (day < 10 ? "0" : "") << day;
	return (_stoval<long>(oss.str()));
}

std::vector<std::string>	BitcoinExchange::getPriceData() const { return _priceData; }
std::vector<std::string>	BitcoinExchange::getInput() const { return _input; }
std::vector<std::string>	BitcoinExchange::getResult() const { return _result; }


std::string BitcoinExchange::getLineByFind(const std::vector<std::string> &vec, const std::string &find) const {
	ContainsSubstring pred(find);

	std::vector<std::string>::const_iterator it = std::find_if(vec.begin(), vec.end(), pred);
	if (it != vec.end())
		return (*it);
	return (0);
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
	if (dateStream.eof() == false)
		return(false);

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
    return ((day >= 1 && day <= daysInMonth));
}

std::string invalidFormat(std::string &line, char delimiter) {
		std::istringstream iss(line);
		std::ostringstream oss;
		int		year, month, day;
		char	dash, delim;
		float	val;
		std::string	tmp;
		size_t 		delim_pos;

		delim_pos = line.find_first_of(delimiter);
		if (delim_pos == std::string::npos)
			return("# Bad format, missing delimiter \'" + std::string(1, delimiter) + "\'.");

		iss >> year >> dash >> month >> dash >> day >> delim >> val;
		if (iss.eof() == false)
			return("# Bad format, check before delimiter.");

		oss << year << "-" << (month < 10 ? "0" : "") << month << "-" 
						<< (day < 10 ? "0" : "") << day << delim << val;
		line = oss.str();
		delim_pos = line.find_first_of(delimiter);
	
		tmp = line.substr(0, delim_pos);
		if (!dateExists(tmp))
			return("# Date does not exist.");
		if (_dateToLong(tmp) < 19700101)
			return("# Date before 1970-01-01 is not supported.");

		tmp = line.substr(delim_pos + 1, line.size() - delim_pos);
		if (checkFloatFormat(tmp))
			return("# Bad format, check after delimiter.");

		val = _stoval<float>(tmp);
		if (val < 0)
			return("# Value must be positive.");
		if (delimiter == '|' && val > 1000)
			return ("# Value must be in range [0 1000].");

		return ("");
}

int	BitcoinExchange::fillData(std::vector<std::string> &data, char delimiter) {
	
	if (data.empty())
		return (std::cout << "# No data to import", 1);

	clear_wspace(data[0]);
	if (delimiter == ',' && data[0] != "date,exchange_rate")
		return (std::cout << "# First line must be \"date,exchange_rate\"", 1);
	if (delimiter == '|' && data[0] != "date|value")
		return (std::cout << "# First line must be \"date | value\"", 1);

	if (data.size() == 1 && data[1].empty())
		return (std::cout << "# No data to import", 1);


	std::string res;
	size_t 		delim_pos;
	for (size_t i = 1; i < data.size(); ++i) {

		res.clear();
		clear_wspace(data[i]);

		if (data[i].empty())
			continue;

		res = invalidFormat(data[i], delimiter);
		delim_pos = data[i].find_first_of(delimiter);
		if (!res.empty()) {
			if (delimiter == ',')
				return (std::cerr << res, i + 1);
			res.insert(1, "error: line \'" + _to_str(i + 1) + "\': ");
		}
		else
			res = data[i].substr(0, delim_pos) + " => " + data[i].substr(delim_pos + 1, data[i].size() - delim_pos - 1) + " = ";

		if (delimiter == '|')
			_result.push_back(res);

		if (delimiter == ',') {
			_dateLong.push_back(_dateToLong(data[i].substr(0, delim_pos)));
			if (std::count(_dateLong.begin(), _dateLong.end(), _dateLong.back()) > 1)
				return (std::cerr << "# Duplicated date found at line " << i + 1, i + 1);			
		}
	}

	return (0);
}

bool clear_empty(std::vector<std::string> &data) {
	bool is_empty = true;

	data.erase(data.begin());
	std::vector<std::string>::iterator it = data.begin();
	while (it != data.end()) {
		if (it->empty())
			it = data.erase(it);
		else {
			is_empty = false;
			++it;
		}
	}
	return (is_empty);

}

void	BitcoinExchange::readData(std::string src, char delimiter) {

	std::ifstream src_file;
	src_file.open(src.c_str());
	if (!src_file.is_open()) {
		std::cerr << "readData() error: \'" << src + "\', " << strerror(errno) << std::endl;
		exit (1);
	}

	std::string	line;
	while (std::getline(src_file, line))
		(delimiter == ',') ?_priceData.push_back(line) :_input.push_back(line);

	int error_at = (delimiter == ',') ? fillData(_priceData, delimiter) : fillData(_input, delimiter);
	if (error_at != 0) {
		src_file.close();
		std::cerr << "\nerror: invalid data. Check line \"" << error_at << "\" in file \"" << src << "\"." << std::endl;
		std::cerr << "Exiting program ..." << std::endl;
		exit (1);
	}
	src_file.close();

	bool is_empty = (delimiter == ',') ? clear_empty(_priceData) : clear_empty(_input);
	if (is_empty) {
		src_file.close();
		std::cerr << "\nerror: no data to import from file \"" << src << "\"." << std::endl;
		std::cerr << "Exiting program..." << std::endl;
		exit (1);
	}
}


float BitcoinExchange::findClosestPrice(const std::string &dateToFind) const {
	
	if (_dateLong.size() == 1) {
		return (_stoval<float>(_priceData[0].substr(_priceData[0].find_first_of(',') + 1)));
	}

	std::vector<long>::const_iterator it = std::find(_dateLong.begin(), _dateLong.end(), _dateToLong(dateToFind));
	if (it == _dateLong.end()) {
		// try to find the biggest date smaller than the dateToFind
		it = std::lower_bound(_dateLong.begin(), _dateLong.end(), _dateToLong(dateToFind));
		// if (it == _dateLong.begin())
			// if the dateToFind is smaller than the smallest date in the dataset
	}
		

	size_t index = std::distance(_dateLong.begin(), it);
	return (_stoval<float>(_priceData[index].substr(_priceData[index].find_first_of(',') + 1)));
}

void	BitcoinExchange::calculate(const std::string &input_file) {

	float res=0;

	readData(input_file, '|');

	std::vector<std::string>::iterator it;

	for (it = _result.begin(); it != _result.end(); ++it) {
		
		if ((*it).find_first_of("#error") != std::string::npos)
			continue;

		res = _stoval<float>(it->substr(14, it->size() - 14));
		res *= findClosestPrice(it->substr(0, 10));
		it->append(_to_str(res));
	}
}

