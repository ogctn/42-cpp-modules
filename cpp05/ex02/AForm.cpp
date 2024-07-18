#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _minSignGrade(150), _minExecGrade(150) {

}

AForm::AForm( const std::string &name, int grade, int execGrade ) : _name(name), _signed(false), _minSignGrade(grade), _minExecGrade(execGrade) {
	if (grade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (grade > 150 || execGrade > 150)
		throw GradeTooLowException();
}

AForm::AForm( const AForm &b ) : _name(b.getName()), _signed(b.isSigned()), _minSignGrade(b.getSignGrade()), _minExecGrade(b.getExecGrade()) {
}

AForm::~AForm() {
}

AForm &AForm::operator=( const AForm &copy ) {
	if (this != &copy)
		this->_signed = copy._signed;
	return (*this);
}

std::string AForm::getName() const {
	return (_name);
}

int AForm::getSignGrade() const {
	return (_minSignGrade);
}

int AForm::getExecGrade() const {
	return (_minExecGrade);
}

bool AForm::isSigned() const {
	return (_signed);
}

void AForm::setSigned(bool val) {
	_signed = val;
}

void AForm::beSigned( const Bureaucrat& b) {
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

void AForm::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() > _minExecGrade)
		throw PermissionError();
	if (!_signed)
		throw NotSigned();
	_do();
}

const char*	AForm::GradeTooLowException::what() const throw() {
	return ("Form: grade is too low!");
}

const char*	AForm::GradeTooHighException::what() const throw() {
	return ("Form: grade is too high!");
}

const char*	AForm::AlreadySignedException::what() const throw() {
	return (" is already signed!");
}

const char*	AForm::PermissionError::what() const throw() {
	return (" reqires higher grade to sign!");
}

const char*	AForm::NotSigned::what() const throw() {
	return (" is not signed!");
}

std::ostream &operator<<( std::ostream &os, const AForm &f ) {
	os << "Form " << f.getName() << " is " << (f.isSigned() ? "" : "not ") << "signed. Grade to sign is: " << f.getSignGrade() << ". Grade to execute is: " << f.getExecGrade();
	return (os);
}
