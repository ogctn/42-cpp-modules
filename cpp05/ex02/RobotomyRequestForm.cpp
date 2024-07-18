#include "RobotomyRequestForm.hpp"		

static int _form_counter;

void RobotomyRequestForm::_do() const {
	std::cout << "Zzzz Bzzz Drilling Sound!" << std::endl;

	if ( ++_form_counter % 2 )
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	else
		throw Failed();
}

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default") {
}

RobotomyRequestForm::RobotomyRequestForm( const std::string &target ) : AForm("RobotomyRequestForm", 72, 45), _target(target) {

}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &b ) : AForm(b), _target(b._target) {
}

RobotomyRequestForm &RobotomyRequestForm::operator=( const RobotomyRequestForm &b )  {
	if ( this == &b ) {}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

std::string RobotomyRequestForm::getTarget() const {
	return (_target);
}

void RobotomyRequestForm::setTarget( const std::string &target ) {
	_target = target;
}

const char*	RobotomyRequestForm::Failed::what() const throw() {
	return ("RobotomyRequestForm failed to robotomize the target!");
}
