#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat user1("Ant", 20);
		std::cout << user1 << '\n';
	} catch(const std::exception& e) {
		std::cerr << "This is wrong! " << e.what() << '\n';
	}

	try { Bureaucrat user2("Christi", -1); }
	catch(const std::exception& e) { std::cerr << "This is wrong! " << e.what() << '\n'; }

	try { Bureaucrat user3("Titi", 170); }
	catch(const std::exception& e) { std::cerr << "This is wrong! " << e.what() << '\n'; }

	try {
		Bureaucrat user4("Messi", 1);
		user4.incrementGrade();
	} catch(const std::exception& e) { 
		std::cerr << "This is wrong! " << e.what() << '\n'; 
	}

	try {
		Bureaucrat user5("Penaldo", 150);
		user5.decrementGrade();
	} catch(const std::exception& e) { 
		std::cerr << "This is wrong! " << e.what() << '\n'; 
	}

	return 0;
}