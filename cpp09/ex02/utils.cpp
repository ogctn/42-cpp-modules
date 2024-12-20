#include "utils.hpp"

int my_stoi(const std::string& str) {
    
	std::stringstream	ss(str);
    int					result;

    ss >> result;
    if (ss.fail() || !ss.eof()) {
        throw std::invalid_argument("Invalid format.");
    }

    if (result < 0 || result > std::numeric_limits<int>::max()) {
        throw std::out_of_range("Out of limits.");
    }
    return (result);
}
