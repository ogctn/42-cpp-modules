#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _minSignGrade(150), _minExecGrade(150) {

}

Form::Form( const std::string &name, int grade, int execGrade ) : _name(name), _signed(false), _minSignGrade(grade), _minExecGrade(execGrade) {
	if (grade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (grade > 150 || execGrade > 150)
		throw GradeTooLowException();
}

Form::Form( const Form &b ) : _name(b.getName()), _signed(b.isSigned()), _minSignGrade(b.getSignGrade()), _minExecGrade(b.getExecGrade()) {
}

Form::~Form() {
}

Form &Form::operator=( const Form &copy ) {
	if (this != &copy)
		this->_signed = copy._signed;
	return (*this);
}

std::string Form::getName() const {
	return (_name);
}

int Form::getSignGrade() const {
	return (_minSignGrade);
}

int Form::getExecGrade() const {
	return (_minExecGrade);
}

bool Form::isSigned() const {
	return (_signed);
}

void Form::setSigned(bool val) {
	_signed = val;
}

void Form::beSigned( const Bureaucrat& b) {
	try {
		if (b.getGrade() > _minSignGrade)
			throw PermissionError();
		if (_signed)
			throw AlreadySignedException();
	} catch (std::exception &e) {
		std::cout << b.getName() << " couldn't sign " << this->getName() << ", because form " << getName() << e.what() <<std::endl ;
		return;
	}		
	_signed = true;
	std::cout << b.getName() << " signed " << _name << std::endl;
	return;
}

const char*	Form::GradeTooLowException::what() const throw() {
	return ("Form: grade is too low!");
}

const char*	Form::GradeTooHighException::what() const throw() {
	return ("Form: grade is too high!");
}

const char*	Form::AlreadySignedException::what() const throw() {
	return (" is already signed!");
}

const char*	Form::PermissionError::what() const throw() {
	return (" reqires higher grade to sign!");
}

std::ostream &operator<<( std::ostream &os, const Form &f ) {
	os << "Form " << f.getName() << " is " << (f.isSigned() ? "" : "not ") 
		<< "signed. Grade to sign is: " << f.getSignGrade() 
		<< ". Grade to execute is: " << f.getExecGrade();
	return (os);
}
