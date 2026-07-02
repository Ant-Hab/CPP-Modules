#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>
#include <cstdlib>

int main()
{
	// Seed random number generator for Robotomy
	std::srand(std::time(nullptr)); 

	std::cout << "\n--- CREATING BUREAUCRATS ---\n";
	Bureaucrat boss("Lumbergh", 1);
	Bureaucrat intern("Milton", 140);
	Bureaucrat midManager("Peter", 50);

	std::cout << boss << '\n' << midManager << '\n' << intern << '\n';

	std::cout << "\n--- SHRUBBERY FORM TEST ---\n";
	ShrubberyCreationForm shrub("Home");
	intern.executeForm(shrub); // Fails (not signed)
	intern.signForm(shrub);    // Succeeds (140 <= 145)
	intern.executeForm(shrub); // Fails (140 is not <= 137)
	midManager.executeForm(shrub); // Succeeds

	std::cout << "\n--- ROBOTOMY FORM TEST ---\n";
	RobotomyRequestForm robot("Bender");
	midManager.signForm(robot);    // Succeeds (50 <= 72)
	midManager.executeForm(robot); // Fails (50 is not <= 45)
	boss.executeForm(robot);       // Succeeds (1 <= 45)

	std::cout << "\n--- PRESIDENTIAL FORM TEST ---\n";
	PresidentialPardonForm pardon("Arthur Dent");
	boss.signForm(pardon);
	boss.executeForm(pardon);

	std::cout << '\n';
	return 0;
}