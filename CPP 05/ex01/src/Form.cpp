#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <utility>

/*
** Default Constructor: Initializes a default form with standard grades and not signed.
*/
Form::Form() : _name("default_form"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

/*
** Parameterized Constructor: Initializes with specific values. Throws if grades are out of bounds.
*/
Form::Form(std::string name, int gradeToSign, int gradeToExecute) 
	: _name(std::move(name)), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
}

/*
** Copy Constructor: Copies all attributes from another form.
*/
Form::Form(const Form& other) 
	: _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

/*
** Assignment Operator: We can only copy _isSigned since the other attributes are const.
*/
Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	return *this;
}

/*
** Destructor: Cleans up the Form object.
*/
Form::~Form() {}

/*
** getName implementation: Returns the form's name.
*/
const std::string& Form::getName() const { 
	return _name; 
}

/*
** getIsSigned implementation: Returns true if signed, false otherwise.
*/
bool Form::getIsSigned() const { 
	return _isSigned; 
}

/*
** getGradeToSign implementation: Returns the required grade to sign.
*/
int Form::getGradeToSign() const { 
	return _gradeToSign; 
}

/*
** getGradeToExecute implementation: Returns the required grade to execute.
*/
int Form::getGradeToExecute() const { 
	return _gradeToExecute; 
}

/*
** beSigned implementation: Changes the status to signed if the bureaucrat's grade is high enough.
*/
void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

/*
** Insertion Operator: Formats all form information for output.
*/
std::ostream& operator<<(std::ostream& out, const Form& form)
{
	out << "Form: " << form.getName() 
		<< ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
		<< ", Grade required to sign: " << form.getGradeToSign()
		<< ", Grade required to execute: " << form.getGradeToExecute();
	return out;
}