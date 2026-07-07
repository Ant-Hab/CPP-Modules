#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

/*
** generate: Randomly instantiates A, B, or C and returns it as a Base pointer.
*/
Base* generate(void)
{
	int random = std::rand() % 3;

	if (random == 0)
		return new A();
	else if (random == 1)
		return new B();
	else
		return new C();
}

/*
** identify (pointer): Identifies type via pointer cast (returns nullptr on fail).
*/
void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "C\n";
	else
		std::cout << "Unknown\n";
}

/*
** identify (reference): Identifies type via reference cast (throws on fail).
*/
void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A\n";
		return;
	}
	catch (...) {}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B\n";
		return;
	}
	catch (...) {}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C\n";
		return;
	}
	catch (...) {}

	std::cout << "Unknown\n";
}

/*
** main: Tests the generation and identification functions.
*/
int main()
{
	std::srand(std::time(nullptr));

	std::cout << "--- Testing Generate & Identify ---\n\n";

	for (int i = 0; i < 5; i++)
	{
		std::cout << "Test " << i + 1 << ":\n";
		Base* ptr = generate();

		std::cout << "Pointer   identify: ";
		identify(ptr);

		std::cout << "Reference identify: ";
		identify(*ptr);
		
		std::cout << "\n";
		delete ptr;
	}

	return 0;
}