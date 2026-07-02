#include "Bureaucrat.hpp"
#include <utility> 

/*
** Default Constructor: Picking some default values because the Bureaucrat always has to have a name and grade.
*/
Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {}

/*
** Parameterized Constructor: Assigns name and grade, throwing exceptions if the grade is out of the 1-150 range.
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
** Assignment Operator: We don't assign the name because it's const, so it's immutable.
*/
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		_grade = other._grade; 
	}
	return *this;
}

/*
** Destructor: Cleans up the Bureaucrat object.
*/
Bureaucrat::~Bureaucrat() {}

/*
** getName implementation: Returns the bureaucrat's immutable name.
*/
const std::string& Bureaucrat::getName() const { 
    return _name; 
}

/*
** getGrade implementation: Returns the bureaucrat's current grade.
*/
int Bureaucrat::getGrade() const { 
    return _grade; 
}

/*
** incrementGrade implementation: Increments the grade (moves it closer to 1), throws if it goes too high.
*/
void Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

/*
** decrementGrade implementation: Decrements the grade (moves it closer to 150), throws if it goes too low.
*/
void Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

/*
** Insertion Operator: Formats the bureaucrat's output.
*/
std::ostream& operator<<(std::ostream& out, const Bureaucrat& cog)
{
	out << cog.getName() << ", bureaucrat grade " << cog.getGrade();
	return out;
}