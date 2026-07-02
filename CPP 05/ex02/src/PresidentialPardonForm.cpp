#include "PresidentialPardonForm.hpp"
#include <iostream>

/*
** Default Constructor: Initializes base AForm with required grades.
*/
PresidentialPardonForm::PresidentialPardonForm() 
	: AForm("PresidentialPardonForm", 25, 5), _target("default") {}

/*
** Parameterized Constructor: Sets the target and base AForm requirements.
*/
PresidentialPardonForm::PresidentialPardonForm(const std::string& target) 
	: AForm("PresidentialPardonForm", 25, 5), _target(target) {}

/*
** Copy Constructor: Copies the target and base class attributes.
*/
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) 
	: AForm(other), _target(other._target) {}

/*
** Assignment Operator: Assigns the target.
*/
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

/*
** Destructor: Cleans up the PresidentialPardonForm object.
*/
PresidentialPardonForm::~PresidentialPardonForm() {}

/*
** executeAction implementation: Informs that target was pardoned by Zaphod Beeblebrox.
*/
void PresidentialPardonForm::executeAction() const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox.\n";
}