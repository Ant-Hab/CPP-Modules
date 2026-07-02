#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

/*
** Default Constructor: Initializes base AForm with required grades.
*/
RobotomyRequestForm::RobotomyRequestForm() 
	: AForm("RobotomyRequestForm", 72, 45), _target("default") {}

/*
** Parameterized Constructor: Sets the target and base AForm requirements.
*/
RobotomyRequestForm::RobotomyRequestForm(const std::string& target) 
	: AForm("RobotomyRequestForm", 72, 45), _target(target) {}

/*
** Copy Constructor: Copies the target and base class attributes.
*/
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) 
	: AForm(other), _target(other._target) {}

/*
** Assignment Operator: Assigns the target.
*/
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

/*
** Destructor: Cleans up the RobotomyRequestForm object.
*/
RobotomyRequestForm::~RobotomyRequestForm() {}

/*
** executeAction implementation: Makes drilling noises and works 50% of the time.
*/
void RobotomyRequestForm::executeAction() const
{
	std::cout << "* VRRRRRRR... BZZZZZZT... DRILLING NOISES *\n";
	if (std::rand() % 2 == 0)
		std::cout << _target << " has been robotomized successfully!\n";
	else
		std::cout << "The robotomy on " << _target << " failed.\n";
}