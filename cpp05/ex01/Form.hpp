#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string _name;
		bool _signed;
		const int _minSignGrade;
		const int _minExecGrade;
	
	public:
		Form();
		Form( const std::string &name, int grade, int execGrade);
		Form( const Form &b );
		Form &operator=( const Form &b );
		~Form();
		
		std::string getName() const;
		int getSignGrade() const;
		int getExecGrade() const;
		bool isSigned() const;

		void setSigned(bool val);
		void beSigned( const Bureaucrat& b);
		
		class GradeTooLowException : public std::exception {
			virtual const char*	what() const throw();
		};
		class GradeTooHighException : public std::exception {
			virtual const char*	what() const throw();
		};
		class AlreadySignedException : public std::exception {
			virtual const char*	what() const throw();
		};
		class PermissionError : public std::exception {
			virtual const char*	what() const throw();
		};
};

std::ostream &operator<<( std::ostream &os, const Form &f );

#endif
