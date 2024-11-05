#include <iostream>

bool	isOnlyDigits(const char *str) {
	if (!str)
		return (false);
	while (*str) {
		if (!std::isdigit(*str))
			return (false);
		++str;
	}
	return (true);
}
