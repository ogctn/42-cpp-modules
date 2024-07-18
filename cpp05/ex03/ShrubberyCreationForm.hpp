#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm {
	private:
		std::string _target;
		virtual void _do() const;
	
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm( const std::string &target );
		ShrubberyCreationForm( const ShrubberyCreationForm &b );
		ShrubberyCreationForm &operator=( const ShrubberyCreationForm &b );
		~ShrubberyCreationForm();
		
		std::string getTarget() const;
		void setTarget( const std::string &target );

		class Failed : public std::exception {
			virtual const char*	what() const throw();
		};
};


#endif
