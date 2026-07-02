#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <utility>

/*
** Default Constructor: Initializes base AForm with required grades.
*/
ShrubberyCreationForm::ShrubberyCreationForm() 
	: AForm("ShrubberyCreationForm", 145, 137), _target("default") {}

/*
** Parameterized Constructor: Sets the target and base AForm requirements.
*/
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) 
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

/*
** Copy Constructor: Copies the target and base class attributes.
*/
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) 
	: AForm(other), _target(other._target) {}

/*
** Assignment Operator: Assigns the target.
*/
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

/*
** Destructor: Cleans up the ShrubberyCreationForm object.
*/
ShrubberyCreationForm::~ShrubberyCreationForm() {}

/*
** executeAction implementation: Creates a file and draws ASCII trees.
*/
void ShrubberyCreationForm::executeAction() const
{
	std::ofstream outFile(_target + "_shrubbery");
	if (outFile.is_open())
	{
		outFile << "       _-_" << '\n';
		outFile << "    /~~   ~~\\" << '\n';
		outFile << " /~~         ~~\\" << '\n';
		outFile << "{               }" << '\n';
		outFile << " \\  _-     -_  /" << '\n';
		outFile << "   ~  \\\\ //  ~" << '\n';
		outFile << "_- -   | | _- _" << '\n';
		outFile << "  _ -  | |   -_" << '\n';
		outFile << "      // \\\\" << '\n';
		outFile.close();
	}
	else
	{
		std::cerr << "Error: Could not open file for shrubbery creation." << '\n';
	}
}