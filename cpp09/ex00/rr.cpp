#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdexcept>

template <typename T>
T	_stoval(const std::string &from) {
	std::stringstream ss(from);
	
	T converted;
	ss >> converted;
	if (ss.fail())
		throw std::invalid_argument("Invalid argument");
	return (converted);
}

struct ContainsSubstring {
    std::string find;

    ContainsSubstring(const std::string& value) : find(value) {}

    bool operator()(const std::string& str) const {
        return (str.find(find) != std::string::npos);
    }
};

std::string getLineByFind(const std::vector<std::string> &vec, const std::string &find) {
	ContainsSubstring pred(find);

	std::vector<std::string>::const_iterator it = std::find_if(vec.cbegin(), vec.cend(), pred);
	if (it != vec.cend())
		return (*it);
	return ("");
}

std::string	parseDate(const std::string &line) {
	std::string tmp;
	size_t delim_pos;

	delim_pos = line.find_first_of("-", 0);
	delim_pos = line.find_first_of("-", delim_pos + 1);
	delim_pos = line.find_first_not_of("0123456789.+-", delim_pos + 1);
	tmp = line.substr(0, delim_pos);
	return (tmp);
}

float	parseVal(const std::string &line) {
return 3;
}



int main() {
	std::vector<std::string> vec;
	vec.push_back("132");
	vec.push_back("21231");
	vec.push_back("313423");
	vec.push_back("2007-01-01,123");
	vec.push_back("321313423");

	std::string str = "2007-01-01";
	
	str = getLineByFind(vec, str);
	std::cout << str << std::endl;

	std::cout << parseDate(str) << std::endl;
	std::cout << parseVal(str) << std::endl;

	

	return 0;
}
