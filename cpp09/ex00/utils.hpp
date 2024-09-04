#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>

bool	isEmptyOrWspace(const std::string &line);
bool	isEmptyOrWspace(const std::vector<std::string> &data, size_t begin);
int		allEmptyControl(std::vector<std::string> &data, char delimiter);

void	clear_wspace(std::string &s);
void	clearEmptyLines(std::vector<std::string> &data);
void	editLine(std::string &line, char delimiter);

int		_dateToInt(const std::string &line);
bool	dateExists(const std::string &date);

std::string getAfterDelim(const std::string &line, char delim);
std::string findAfterDelimByDate(std::vector<std::string> &data, int dateIntToFind, char delim);

# include "utils.tpp"

#endif
