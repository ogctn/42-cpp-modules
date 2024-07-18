#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		std::string _target;
		virtual void _do() const;
	
	public:
		PresidentialPardonForm();
		PresidentialPardonForm( const std::string &target );
		PresidentialPardonForm( const PresidentialPardonForm &b );
		PresidentialPardonForm &operator=( const PresidentialPardonForm &b );
		~PresidentialPardonForm();
		
		std::string getTarget() const;
		void setTarget( const std::string &target );

};


#endif
