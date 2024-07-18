#ifndef INTERN_HP
# define INTERN_HP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"		
#include "ShrubberyCreationForm.hpp"

class AForm;

class Intern {
    public:
        Intern();
		Intern( const Intern &src );
		~Intern();
		Intern &operator=( const Intern &src );
		
        AForm *makeForm(const std::string &form, const std::string &target);

        class FormNotFoundException: public std::exception {
			virtual const char*	what() const throw();
		};

};

#endif
