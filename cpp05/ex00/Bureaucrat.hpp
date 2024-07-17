#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>

class Bureaucrat {
	private:
		const std::string _name;
		int _grade;

	public:
		Bureaucrat();
		Bureaucrat( const std::string &name, int grade );
		Bureaucrat( const Bureaucrat &b );
		Bureaucrat &operator=( const Bureaucrat &b );
		~Bureaucrat();
		
		std::string getName() const;
		int getGrade() const;
		

		void incrementGrade();
		void incrementGrade( int val );
		void decrementGrade();
		void decrementGrade( int val );

		class GradeTooLowException: public std::exception {
			public:
				virtual const char*	what() const throw();
		};

		class GradeTooHighException: public std::exception {
			public:
				virtual const char*	what() const throw();
		};
};

std::ostream &operator<<( std::ostream &os, const Bureaucrat &b );

#endif
