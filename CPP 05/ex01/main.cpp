#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "--- Testing Form Instantiation Limits ---\n";
	try {
		Form impossibleForm("TopSecret", 0, 50);
	} catch(const std::exception& e) {
		std::cerr << "Creation Failed: " << e.what() << '\n';
	}

	std::cout << "\n--- Testing Form Signing ---\n";
	Bureaucrat boss("Messi", 1);
	Bureaucrat intern("Ronaldo", 150);
	
	Form tpsReport("TPS Report", 50, 10);
	
	std::cout << tpsReport << '\n'; // Print initial state

	// Intern tries to sign (Should fail)
	intern.signForm(tpsReport);
	std::cout << tpsReport << '\n'; // Prove it is still not signed
	
	// Boss tries to sign (Should succeed)
	boss.signForm(tpsReport);
	std::cout << tpsReport << '\n'; // Prove it is now signed

	// Try signing an already signed form
	boss.signForm(tpsReport);

	return 0;
}