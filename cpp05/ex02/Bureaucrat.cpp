#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {
}

Bureaucrat::Bureaucrat( const std::string &name, int grade) : _name(name), _grade(grade) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat( const Bureaucrat &b ) : _name(b.getName()), _grade(b.getGrade()) {
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat &Bureaucrat::operator=( const Bureaucrat &b ) {
	if (this != &b) 
		this->_grade = b.getGrade();
	return (*this);
}

std::string Bureaucrat::getName() const {
	return (_name);
}

int Bureaucrat::getGrade() const {
	return (_grade);
}

void Bureaucrat::incrementGrade() {
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::incrementGrade( int val ) {
	if (_grade - val < 1)
		throw GradeTooHighException();
	_grade -= val;
}

void Bureaucrat::decrementGrade() {
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade++;
}

void Bureaucrat::decrementGrade( int val ) {
	if (_grade + val > 150)
		throw GradeTooLowException();
	_grade += val;
}

std::ostream &operator<<( std::ostream &os, const Bureaucrat &b ) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (os);
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Bureaucrat: grade too low!");
}

const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Bureaucrat: grade too high!");
}

bool Bureaucrat::signForm( AForm &f ) {
	if (f.isSigned())
		throw AForm::AlreadySignedException();
	if (f.getSignGrade() < _grade)
		throw GradeTooLowException();
	f.setSigned(true);
	return (true);
}

void Bureaucrat::executeForm( AForm const & form ) {
	try {
		form.execute(*this);
	} catch (std::exception &e) {
		std::cout << getName() << " couldn't execute " << form.getName() << ", because form " << form.getName() << e.what() <<std::endl ;
		return;
	}
	std::cout << getName() << " executed " << form.getName() << std::endl;
}
