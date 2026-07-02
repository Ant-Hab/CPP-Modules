#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <utility>

/*
** Default Constructor: Initializes a default abstract form.
*/
AForm::AForm() : _name("default_form"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

/*
** Parameterized Constructor: Initializes with specific values.
*/
AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) 
	: _name(std::move(name)), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
}

/*
** Copy Constructor: Copies attributes from another form.
*/
AForm::AForm(const AForm& other) 
	: _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

/*
** Assignment Operator: Copies the signature status.
*/
AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
}

/*
** Destructor: Cleans up the AForm object.
*/
AForm::~AForm() {}

/*
** Getters implementation
*/
const std::string& AForm::getName() const { return _name; }
bool AForm::getIsSigned() const { return _isSigned; }
int AForm::getGradeToSign() const { return _gradeToSign; }
int AForm::getGradeToExecute() const { return _gradeToExecute; }

/*
** beSigned implementation: Changes status to signed if grade is high enough.
*/
void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

/*
** execute implementation: Elegant base class check before calling derived action.
*/
void AForm::execute(Bureaucrat const & executor) const
{
	if (!_isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
	
	this->executeAction(); // Call the derived class's specific action
}

/*
** Insertion Operator: Formats all form information for output.
*/
std::ostream& operator<<(std::ostream& out, const AForm& form)
{
	out << "Form: " << form.getName() 
		<< ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
		<< ", Sign Grade: " << form.getGradeToSign()
		<< ", Exec Grade: " << form.getGradeToExecute();
	return out;
}