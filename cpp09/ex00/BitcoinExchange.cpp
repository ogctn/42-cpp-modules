#include "BitcoinExchange.hpp"
#include "utils.hpp"

BitcoinExchange::BitcoinExchange() { readData(DATA_CSV, ','); }
BitcoinExchange::BitcoinExchange(std::string dataset) { readData(dataset, ','); }

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	*this = other;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &other) {
	_priceData = other._priceData;
	_input = other._input;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

void	BitcoinExchange::printData(const std::vector<std::string> &vec) const {
	if (vec.empty()) {
		std::cerr << "No data to print." << std::endl;
		return;
	}
	for (std::vector<std::string>::const_iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << std::endl;
}

std::vector<std::string>	BitcoinExchange::getPriceData() const { return _priceData; }
std::vector<std::string>	BitcoinExchange::getInput() const { return _input; }
std::vector<std::string>	BitcoinExchange::getResult() const { return _result; }

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

std::string getError(std::string line, char delimiter) {
	float		val;
	std::string	tmp;
	size_t 		delim_pos, dash1, dash2;

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
	if (tmp.find_first_not_of("0123456789-", 0) != std::string::npos)
		return("# Bad format, check date format.");

	if (_dateToInt(line) < 19700101)
		return("# Date before 1970-01-01 is not supported.");
	if (!dateExists(line))
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

int	BitcoinExchange::fillData(std::vector<std::string> &data, char delimiter) {
	std::string res;
	size_t 		pos;

	pos = allEmptyControl(data, delimiter);
	if (pos > 0)
		return(pos);
	
	for (size_t i = 1; i < data.size(); ++i) {
		clear_wspace(data[i]);
		if (data[i].empty())
			continue;

		res = getError(data[i], delimiter);
		if (res.empty()) {
			editLine(data[i], delimiter);
			res = data[i].substr(0, data[i].find_first_of(delimiter)) + " => ";
			res += getAfterDelim(data[i], delimiter) + " = ";
		}
		else {
			if (delimiter == ',')
				return (std::cerr << res, i + 1);
			res.insert(1, "error: line \'" + _to_str(i + 1) + "\': ");
		}

		if (delimiter == '|')
			_result.push_back(res);
		else {
			_dateInt.push_back(_dateToInt(data[i]));
			if (std::count(_dateInt.begin(), _dateInt.end(), _dateInt.back()) > 1)
				return (std::cerr << "# Duplicated date found at line " << i + 1, i + 1);			
		}
	}

	return (0);
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

float BitcoinExchange::findClosestPrice(const std::string &line) {
	std::vector<int> sortedDates = _dateInt;
	std::sort(sortedDates.begin(), sortedDates.end());
	
	int dateIntToFind = _dateToInt(line);

	std::vector<int>::iterator itInt = std::lower_bound(sortedDates.begin(), sortedDates.end(), dateIntToFind);
	if (itInt != sortedDates.end() && *itInt == dateIntToFind)
		return (_stoval<float>(findAfterDelimByDate(_priceData, *itInt, ',')));
	else {
		if (itInt != sortedDates.begin())
			return (_stoval<float>(findAfterDelimByDate(_priceData, *(itInt - 1), ',')));
		else
			throw std::range_error("No equal or previous date found.");
	}
}

float	BitcoinExchange::findAndMultValues(std::string line) {
	clear_wspace(line);
	std::string tmp = getAfterDelim(line, '>');
	tmp = tmp.substr(0, tmp.find_first_of("="));

	float amount = _stoval<float>(tmp);
	float price = findClosestPrice(line);
	return (amount * price);
}

void	BitcoinExchange::calculate(const std::string &input_file) {

	float ret;

	readData(input_file, '|');

	std::vector<std::string>::iterator it;
	for (it = _result.begin(); it != _result.end(); ++it) {

		if ((*it).find_first_of("#") != std::string::npos)
			continue;

		try {
			ret = findAndMultValues(*it);
		} catch (std::range_error &e) {
			it->append("error: " + std::string(e.what()));
			continue;
		}

		it->append(_to_str(ret));
	}
}
