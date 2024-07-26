#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cstdlib>		// std::strtod()
# include <limits>		// std::numeric_limits
# include <sstream>		// std::stringstream
# include <exception>

enum specials {
	my_inf,
	my_minus_inf,
	my_nan,
	smt_else
};

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &other);
		ScalarConverter &operator=(ScalarConverter const &other);
		~ScalarConverter();


	public:
		static void	convert(std::string input);

};

class BadInputException: public std::exception {
	virtual const char*	what() const throw();
};


#endif
