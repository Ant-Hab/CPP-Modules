#include "PhoneBook.hpp"

/**
 * Entry point for the PhoneBook application.
 * Continuously prompts for ADD, SEARCH, or EXIT commands.
 */
int main(void) 
{
    PhoneBook   phonebook;
    std::string command;

    while (true) 
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): " << std::flush;
        
        if (!std::getline(std::cin, command)) 
        {
            std::cout << std::endl;
            break;
        }

        if (command == "ADD") 
        {
            phonebook.addContact();
        }
        else if (command == "SEARCH") 
        {
            phonebook.searchContact();
        }
        else if (command == "EXIT") 
        {
            break;
        }
        else if (!command.empty()) 
        {
            std::cout << "Invalid command." << std::endl;
        }
    }

    return (0);
}