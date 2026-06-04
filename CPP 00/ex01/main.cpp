#include "PhoneBook.hpp"

/*
 * Main entry point for the PhoneBook program.
 * Initializes the PhoneBook and runs a loop to accept user commands:
 * ADD, SEARCH, or EXIT.
 */
int main()
{
	PhoneBook phoneBook;
	std::string command;

	std::cout << "Welcome to the PhoneBook." << std::endl;
	std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;

	while (true)
	{
		std::cout << "> ";
		if (!std::getline(std::cin, command))
		{
			break;
		}

		if (command == "ADD")
		{
			phoneBook.addContact();
		}
		else if (command == "SEARCH")
		{
			phoneBook.displayContact();
		}
		else if (command == "EXIT")
		{
			break;
		}
		else if (!command.empty())
		{
			std::cout << "Invalid command. Use ADD, SEARCH, or EXIT." << std::endl;
		}
	}

	return 0;
}