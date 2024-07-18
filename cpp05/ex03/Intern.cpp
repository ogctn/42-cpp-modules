#include "Intern.hpp"

Intern::Intern() {
}

Intern::Intern( const Intern &src ) {
	*this = src;
}

Intern::~Intern() {
}

Intern &Intern::operator=( const Intern &src ) {
	if ( this == &src) {}
	return (*this);
}

static AForm *makePresidentialPardon(const std::string &target) {
	return (new PresidentialPardonForm(target));
}

static AForm *makeRobotomyRequest(const std::string &target) {
	return (new RobotomyRequestForm(target));
}

static AForm *makeShrubberyCreation(const std::string &target) {
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(const std::string &form, const std::string &target) {
	std::string forms[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	AForm *(*form_makers[3])(const std::string &) = {&makePresidentialPardon, &makeRobotomyRequest, &makeShrubberyCreation};
	AForm *(*f)(const std::string &) = NULL;
	for (int i = 0; i < 3; i++) {
		if (form == forms[i]) {
			f = form_makers[i];
			break;
		}
	}
	if (f == NULL) {
		std::cerr << "Can't create a form " << form << ": unknown form name!" << std::endl;
		return (NULL);
	}
	std::cout << "Intern creates " << form << std::endl;
	return (f(target));
}
