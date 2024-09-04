#include "BitcoinExchange.hpp"
#include "utils.hpp"

int _dateToInt(const std::string &line) {
	size_t	dash1 = line.find_first_of("-", 0);
	size_t	dash2 = line.find_first_of("-", dash1 + 1);
	size_t	day_len = line.find_first_of(",|", dash2 + 1);
	if (day_len != std::string::npos) 
		day_len = line.find_first_of(",|", dash2 + 1) - dash2 - 1;
	else
		day_len = line.size() - dash2 - 1;
	int		year = _stoval<int>(line.substr(0, dash1));
	int		month = _stoval<int>(line.substr(dash1 + 1, dash2 - dash1 - 1));
	int		day = _stoval<int>(line.substr(dash2 + 1, day_len));
	return (year * 10000 + month * 100 + day);
}

 std::string _IntToDate(int date) {
	std::string	res;
	int	year = date / 10000;
	int	month = date / 100 % 100;
	int	day = date % 100;
	res = _to_str(year) + "-";
	res += (month < 10 ? "0" : "") + _to_str(month) + "-";
	res += (day < 10 ? "0" : "") + _to_str(day);
	return (res);
}

void	clear_wspace(std::string &s) {
	size_t i = 0;
	while (i != std::string::npos) {
		i = s.find_first_of(" \t\n\v\f\r", i);
		if (i != std::string::npos)
			s.erase(i, 1);
	}
}

void	editLine(std::string &line, char delimiter) {

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

bool isLeapYear(int year) { return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)); }

bool dateExists(const std::string &date) {
	int dInt = _dateToInt(date);
	int year = dInt / 10000;
	int month = dInt / 100 % 100;
	int day = dInt % 100;
	int daysInMonth;

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

bool	isEmptyOrWspace(const std::string &line) {
	for (std::string::const_iterator it = line.begin(); it != line.end(); ++it)
		if (!std::isspace(*it))
			return (false);
	return (true);
}

bool	isEmptyOrWspace(const std::vector<std::string> &data, size_t begin) {
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

std::string getAfterDelim(const std::string &line, char delim) {
	size_t pos = line.find_first_of(delim) + 1;
	return (line.substr(pos, line.size() - pos));
}

std::string findAfterDelimByDate(std::vector<std::string> &data, int dateIntToFind, char delim) {
	std::vector<std::string>::iterator lineIt;
	for (lineIt = data.begin(); lineIt != data.end(); ++lineIt)
		if (_dateToInt(*lineIt) == dateIntToFind)
			break;
	return (getAfterDelim(*lineIt, delim));
}
