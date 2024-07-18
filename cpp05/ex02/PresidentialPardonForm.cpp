#include "PresidentialPardonForm.hpp"

void PresidentialPardonForm::_do() const {
	std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default") {
}

PresidentialPardonForm::PresidentialPardonForm( const std::string &target ) : AForm("PresidentialPardonForm", 25, 5), _target(target) {
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &copy ) : AForm(copy), _target(copy._target) {
}

PresidentialPardonForm &PresidentialPardonForm::operator=( const PresidentialPardonForm &b ) {
	if ( this == &b) {}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

std::string PresidentialPardonForm::getTarget() const {
	return (_target);
}

void PresidentialPardonForm::setTarget( const std::string &target ) {
	_target = target;
}
