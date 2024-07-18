#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private:
		std::string _target;
		virtual void _do() const;
	
	public:
		RobotomyRequestForm();
		RobotomyRequestForm( const std::string &target );
		RobotomyRequestForm( const RobotomyRequestForm &b );
		RobotomyRequestForm &operator=( const RobotomyRequestForm &b );
		~RobotomyRequestForm();

		std::string getTarget() const;
		void setTarget( const std::string &target );

		class Failed : public std::exception {
			virtual const char*	what() const throw();
		};
};

#endif
