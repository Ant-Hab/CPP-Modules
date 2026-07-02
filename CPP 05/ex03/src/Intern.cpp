#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

/*
** Default Constructor: The intern has no identity.
*/
Intern::Intern() {}

/*
** Copy Constructor: Nothing to copy, but required for Orthodox Canonical Form.
*/
Intern::Intern(const Intern& other)
{
	(void)other;
}

/*
** Assignment Operator: Nothing to assign.
*/
Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

/*
** Destructor: The intern is discarded.
*/
Intern::~Intern() {}

/*
** makeShrubbery implementation: Allocates a ShrubberyCreationForm.
*/
AForm* Intern::makeShrubbery(const std::string& target) const
{
	return new ShrubberyCreationForm(target);
}

/*
** makeRobotomy implementation: Allocates a RobotomyRequestForm.
*/
AForm* Intern::makeRobotomy(const std::string& target) const
{
	return new RobotomyRequestForm(target);
}

/*
** makePresidential implementation: Allocates a PresidentialPardonForm.
*/
AForm* Intern::makePresidential(const std::string& target) const
{
	return new PresidentialPardonForm(target);
}

/*
** makeForm implementation: Uses arrays of strings and member function pointers to avoid if/else chains.
*/
AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
	std::string formNames[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	// Array of pointers to Intern's member functions
	AForm* (Intern::*funcs[])(const std::string& target) const = {
		&Intern::makeShrubbery,
		&Intern::makeRobotomy,
		&Intern::makePresidential
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << '\n';
			return (this->*funcs[i])(target);
		}
	}

	std::cout << "Intern couldn't create '" << formName << "' because it doesn't exist.\n";
	return nullptr;
}