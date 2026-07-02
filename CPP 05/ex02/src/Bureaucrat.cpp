#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <utility>

/*
** Default Constructor: Initializes a default bureaucrat.
*/
Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {}

/*
** Parameterized Constructor: Assigns name and grade, throwing if out of bounds.
*/
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(std::move(name)), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

/*
** Copy Constructor: Creates a copy of another bureaucrat.
*/
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {}

/*
** Assignment Operator: Assigns grade (name is const).
*/
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		_grade = other._grade; 
	return *this;
}

/*
** Destructor: Cleans up the Bureaucrat object.
*/
Bureaucrat::~Bureaucrat() {}

/*
** getName implementation: Returns the bureaucrat's name.
*/
const std::string& Bureaucrat::getName() const { return _name; }

/*
** getGrade implementation: Returns the bureaucrat's current grade.
*/
int Bureaucrat::getGrade() const { return _grade; }

/*
** incrementGrade implementation: Increments the grade, throws if too high.
*/
void Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

/*
** decrementGrade implementation: Decrements the grade, throws if too low.
*/
void Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

/*
** signForm implementation: Attempts to sign a form and prints the outcome.
*/
void Bureaucrat::signForm(AForm& form)
{
	try 
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << '\n';
	}
	catch (const std::exception& e)
	{
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << '\n';
	}
}

/*
** executeForm implementation: Attempts to execute a form and prints the outcome.
*/
void Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << '\n';
	}
	catch(const std::exception& e)
	{
		std::cout << _name << " couldn't execute " << form.getName() << " because " << e.what() << '\n';
	}
}

/*
** Insertion Operator: Formats the bureaucrat's output.
*/
std::ostream& operator<<(std::ostream& out, const Bureaucrat& cog)
{
	out << cog.getName() << ", bureaucrat grade " << cog.getGrade();
	return out;
}