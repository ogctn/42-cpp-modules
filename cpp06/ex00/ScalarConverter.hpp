#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

enum specials {
	my_inf,
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

		class BadInputException: public std::exception {
			virtual const char*	what() const throw();
		};

	public:
		static void	convert(std::string input);

};


#endif
