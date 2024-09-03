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

int _dateToInt(const std::string &date) {
	size_t	dash1 = date.find_first_of("-", 0);
	size_t	dash2 = date.find_first_of("-", dash1 + 1);
	int		year = _stoval<int>(date.substr(0, dash1));
	int		month = _stoval<int>(date.substr(dash1 + 1, dash2 - dash1 - 1));
	int		day = _stoval<int>(date.substr(dash2 + 1, date.size() - dash2 - 1));
	return (year * 10000 + month * 100 + day);
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

std::string getPriceFromLine(const std::string &line) {
	size_t pos = line.find_first_of("=", line.find_first_of("=") + 1);
	return (line.substr(pos + 1, line.size() - pos - 1));
}	

void	clear_wspace(std::string &s) {
	size_t i = 0;
	while (i != std::string::npos) {
		i = s.find_first_of(" \t\n\v\f\r", i);
		if (i != std::string::npos)
			s.erase(i, 1);
	}
}

bool	isValidFloatFormat(std::string str) {
	size_t pos;

	if (str.find_first_not_of("0123456789+-.") != std::string::npos)
		return (false);

	if (str.find_first_not_of("+-.") == std::string::npos)
		return (false);

	pos = str.find_first_of("+-", 0);
	if ((pos != std::string::npos && pos > 0) || str.find_first_of("+-", pos + 1) != std::string::npos)
		return (false);

	pos = str.find_first_of(".", 0);
	if (str.find_first_of(".", pos + 1) != std::string::npos)
		return (false);

	if (str[0] == '+' || str[0] == '-') {
		if (str[1] == '.' && str.find_first_of("0123456789", 2) == std::string::npos)
			return (false);
		else if (str.find_first_of("0123456789", 1) == std::string::npos)
			return (false);
	}
	
	if (str[0] == '.' && str.find_first_of("0123456789", 1) == std::string::npos)
		return (false);

	return (true);
}

bool isLeapYear(int year) { return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)); }

bool dateExists(const std::string& date) {
	size_t	dash1 = date.find_first_of("-", 0);
	size_t	dash2 = date.find_first_of("-", dash1 + 1);
	int		year = _stoval<int>(date.substr(0, dash1));
	int		month = _stoval<int>(date.substr(dash1 + 1, dash2 - dash1 - 1));
	int		day = _stoval<int>(date.substr(dash2 + 1, date.size() - dash2 - 1));
    int		daysInMonth;

	if (month < 1 || month > 12)
        return (false);
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

void	reformLine(std::string &line, char delimiter) {

	clear_wspace(line);
	size_t	dash1 = line.find_first_of("-", 0);
	size_t	dash2 = line.find_first_of("-", dash1 + 1);
	size_t	del = line.find_first_of(delimiter);
	int		year = _stoval<int>(line.substr(0, dash1));
	int		month = _stoval<int>(line.substr(dash1 + 1, dash2 - dash1 - 1));
	int		day = _stoval<int>(line.substr(dash2 + 1, del - dash2 - 1));
	float	val = _stoval<float>(line.substr(del + 1, line.size() - del - 1));

	std::string tmp;
	tmp = _to_str(year) + "-";
	tmp += (month < 10 ? "0" : "") + _to_str(month) + "-";
	tmp += (day < 10 ? "0" : "") + _to_str(day);
	tmp += delimiter + _to_str(val);
	line = tmp;
}


std::string getError(std::string line, char delimiter) {
		float	val;
		std::string	tmp;
		size_t 		delim_pos, dash1, dash2;

		clear_wspace(line);
		delim_pos = line.find_first_of(delimiter);
		if (delim_pos == std::string::npos)
			return("# Bad format, missing delimiter \'" + std::string(1, delimiter) + "\'.");
		if (std::count(line.begin(), line.end(), delimiter) > 1)
			return("# Bad format, too many delimiters \'" + std::string(1, delimiter) + "\'.");

		dash1 = line.find_first_of("-", 0);
		dash2 = line.find_first_of("-", dash1 + 1);
		if (dash1 == std::string::npos || dash2 == std::string::npos)
			return("# Bad format, check date format.");

		tmp = line.substr(0, delim_pos);
		if (_dateToInt(tmp) < 19700101)
			return("# Date before 1970-01-01 is not supported.");
		if (!dateExists(tmp))
			return("# Date does not exist.");

		tmp = line.substr(delim_pos + 1, line.size() - delim_pos - 1);
		if (!isValidFloatFormat(tmp))
			return("# Bad format, check after delimiter.");
		if (tmp.size() > 38)
			return("# Value is too big.");

		val = _stoval<float>(tmp);
		if (val < 0)
			return("# Value must be positive.");
		if (delimiter == '|' && val > 1000)
			return ("# Value must be in range [0 1000].");

		return ("");
}

bool	isEmptyOrWspace(const std::string &line) {
	for (std::string::const_iterator it = line.begin(); it != line.end(); ++it)
		if (!std::isspace(*it))
			return (false);
	return (true);
}

bool	isEmptyOrWspace(const std::vector<std::string> &data, int begin) {
	for (std::vector<std::string>::const_iterator it = data.begin() + begin; it != data.end(); ++it)
		if (!isEmptyOrWspace(*it))
			return (false);
	return (true);
}

int	allEmptyControl(std::vector<std::string> &data, char delimiter) {
	if (data.empty())
		return (std::cout << "# No data to import", 1);
	clear_wspace(data[0]);
	if (isEmptyOrWspace(data[0]))
		return (std::cout << "# No data to import", 1);
	if (delimiter == ',' && data[0] != "date,exchange_rate")
		return (std::cout << "# First line must be \"date,exchange_rate\"", 1);
	if (delimiter == '|' && data[0] != "date|value")
		return (std::cout << "# First line must be \"date | value\"", 1);
	if (isEmptyOrWspace(data, 1))
		return (std::cout << "# No data to import", 2);
	return (0);
}

int	BitcoinExchange::fillData(std::vector<std::string> &data, char delimiter) {
	std::string res;
	size_t 		pos;

	pos = allEmptyControl(data, delimiter);
	if (pos > 0)
		return(pos);
	
	for (size_t i = 1; i < data.size(); ++i) {
		res.clear();
		clear_wspace(data[i]);
		if (data[i].empty())
			continue;

		res = getError(data[i], delimiter);
		if (res.empty()) {
			reformLine(data[i], delimiter);
			pos = data[i].find_first_of(delimiter);
			res = data[i].substr(0, pos) + " => " + data[i].substr(pos + 1, data[i].size() - pos - 1) + " = ";
		}
		else {
			if (delimiter == ',')
				return (std::cerr << res, i + 1);
			res.insert(1, "error: line \'" + _to_str(i + 1) + "\': ");
		}

		if (delimiter == '|')
			_result.push_back(res);
		else {
			_dateInt.push_back(_dateToInt(data[i].substr(0, pos)));
			if (std::count(_dateInt.begin(), _dateInt.end(), _dateInt.back()) > 1)
				return (std::cerr << "# Duplicated date found at line " << i + 1, i + 1);			
		}
	}

	return (0);
}

void clearEmptyLines(std::vector<std::string> &data) {
	if (data.empty())
		return;
	data.erase(data.begin());
	std::vector<std::string>::iterator it = data.begin();
	while (it != data.end()) {
		if (isEmptyOrWspace(*it))
			it = data.erase(it);
		else
			++it;
	}
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
	src_file.close();

	int error_at = (delimiter == ',') ? fillData(_priceData, delimiter) : fillData(_input, delimiter);
	if (error_at != 0) {
		std::cerr << "\nerror: invalid data. Check line \"" << error_at << "\" in file \"" << src << "\"." << std::endl;
		std::cerr << "Exiting program ..." << std::endl;
		exit (1);
	}

	(delimiter == ',') ? clearEmptyLines(_priceData) : clearEmptyLines(_input);
}


float BitcoinExchange::findClosestPrice(const std::string &dateToFind) {
// _priceData:
// 2000-12-21,5
// 2000-01-21,1
// 2000-02-01,12
// 2000-12-01,3.2
// 2000-03-11,0.2

	size_t	idx = 0;
	std::string strPrice;

	strPrice = getLineByFind(_priceData, dateToFind);


	float exchange_rate = _stoval<float>();
	if (_dateInt.size() == 1)
		return (exchange_rate);

	std::vector<int>::const_iterator it = std::find(_dateInt.begin(), _dateInt.end(), _dateToInt(dateToFind));
	if (it != _dateInt.end())
		return (9);
	else {
		std::sort(_dateInt.begin(), _dateInt.end());
		it = std::lower_bound(_dateInt.begin(), _dateInt.end(), _dateToInt(dateToFind)); ;
	}

	if (it == _dateInt.begin())
		return (0.1);
	


	return (100);
}

float	BitcoinExchange::getPrice(std::string line) {

	clear_wspace(line);
	size_t pos = line.find_first_of("=", line.find_first_of("=") + 1);
	std::string val = line.substr(line.find_first_of(">") + 1, pos - line.find_first_of(">") - 1);
	float amount = _stoval<float>(val);
	float price = findClosestPrice(line.substr(0, line.find_first_of("=")));
std::cout << "price: \'" << price << "\'" << std::endl;
	return (amount);
	// return (amount * price);
}

void	BitcoinExchange::calculate(const std::string &input_file) {

	float ret = 0;

	readData(input_file, '|');

	std::vector<std::string>::iterator it;
	for (it = _result.begin(); it != _result.end(); ++it) {

		if ((*it).find_first_of("#") != std::string::npos)
			continue;

		ret = getPrice(*it);
		it->append(_to_str(ret));
	}
}

