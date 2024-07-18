#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string _name;
		bool _signed;
		const int _minSignGrade;
		const int _minExecGrade;
		virtual void _do() const = 0;
	
	public:
		AForm();
		AForm( const std::string &name, int grade, int execGrade);
		AForm( const AForm &b );
		~AForm();
		AForm &operator=( const AForm &b );
		
		std::string getName() const;
		int getSignGrade() const;
		int getExecGrade() const;
		bool isSigned() const;

		void setSigned(bool val);
		void beSigned( const Bureaucrat& b);
		
		void execute(Bureaucrat const & executor) const;

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
		class NotSigned : public std::exception {
			virtual const char*	what() const throw();
		};
};

std::ostream &operator<<( std::ostream &os, const AForm &f );

#endif
