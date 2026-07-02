#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
	std::cout << "--- HIRING INTERN ---\n";
	Intern someRandomIntern;
	Bureaucrat boss("Lumbergh", 1);
	
	AForm* rrf = nullptr;
	AForm* scf = nullptr;
	AForm* ppf = nullptr;
	AForm* invalid = nullptr;

	std::cout << "\n--- INTERN MAKES FORMS ---\n";
	
	// Valid Forms
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	scf = someRandomIntern.makeForm("shrubbery creation", "Home");
	ppf = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
	
	// Invalid Form
	invalid = someRandomIntern.makeForm("coffee request", "Boss");

	std::cout << "\n--- BOSS PROCESSES FORMS ---\n";
	
	if (rrf)
	{
		boss.signForm(*rrf);
		boss.executeForm(*rrf);
	}
	if (scf)
	{
		boss.signForm(*scf);
		boss.executeForm(*scf);
	}
	if (ppf)
	{
		boss.signForm(*ppf);
		boss.executeForm(*ppf);
	}

	std::cout << "\n--- CLEANING UP MEMORY ---\n";
	delete rrf;
	delete scf;
	delete ppf;
	// invalid is nullptr, safe to delete but unnecessary

	return 0;
}