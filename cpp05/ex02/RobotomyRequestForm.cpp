#include "RobotomyRequestForm.hpp"		

void RobotomyRequestForm::_do() const {

}

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default") {
}

RobotomyRequestForm::RobotomyRequestForm( const std::string &target ) : AForm("RobotomyRequestForm", 72, 45), _target(target) {

}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &b ) : AForm(b), _target(b._target) {
}

RobotomyRequestForm &RobotomyRequestForm::operator=( const RobotomyRequestForm &b ) :  {

}

RobotomyRequestForm::~RobotomyRequestForm() {
}

std::string RobotomyRequestForm::getTarget() const {
	return (_target);
}

void RobotomyRequestForm::setTarget( const std::string &target ) {
	_target = target;
}

const char*	RobotomyRequestForm::LowLevel::what() const throw() {
	return ("");
}
