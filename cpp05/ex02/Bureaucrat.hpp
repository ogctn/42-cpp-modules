#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
# include "AForm.hpp"

class AForm;

class Bureaucrat {
	private:
		const std::string _name;
		int _grade;

	public:
		Bureaucrat();
		Bureaucrat( const std::string &name, int grade );
		Bureaucrat( const Bureaucrat &b );
		~Bureaucrat();
		Bureaucrat &operator=( const Bureaucrat &b );
		
		std::string getName() const;
		int getGrade() const;
		

		void incrementGrade();
		void incrementGrade( int val );
		void decrementGrade();
		void decrementGrade( int val );

		bool signForm( AForm &f );

		void executeForm( AForm const & form );

		class GradeTooLowException: public std::exception {
			virtual const char*	what() const throw();
		};

		class GradeTooHighException: public std::exception {
			virtual const char*	what() const throw();
		};
};

std::ostream &operator<<( std::ostream &os, const Bureaucrat &b );

#endif
