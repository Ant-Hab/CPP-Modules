#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _count(0), _oldestIndex(0) 
{
}

PhoneBook::~PhoneBook() {}

/**
 * Prompts user for all contact information. 
 * Replaces the oldest contact if the phonebook is full (8 contacts).
 */
void PhoneBook::addContact() 
{
    std::string fields[5];
    std::string prompts[5] = {
        "First Name: ", "Last Name: ", "Nickname: ", 
        "Phone Number: ", "Darkest Secret: "
    };

    std::cout << "\n--- Adding New Contact ---" << std::endl;

    for (int i = 0; i < 5; i++) 
    {
        while (fields[i].empty()) 
        {
            std::cout << prompts[i] << std::flush;
            if (!std::getline(std::cin, fields[i])) 
            {
                return ;
            }
            if (fields[i].empty()) 
            {
                std::cout << "  (!) Field cannot be empty." << std::endl;
            }
        }
    }

    _contacts[_oldestIndex].setInfo(fields[0], fields[1], fields[2], fields[3], fields[4]);
    
    _oldestIndex = (_oldestIndex + 1) % 8;
    if (_count < 8) 
    {
        _count++;
    }

    std::cout << "Done! Contact saved.\n" << std::endl;
}

/**
 * Handles formatting for the SEARCH table.
 * Right-aligns text to 10 characters and truncates with a '.' if longer.
 */
void PhoneBook::_formatColumn(std::string str) const 
{
    if (str.length() > 10) 
    {
        std::cout << str.substr(0, 9) << ".";
    }
    else 
    {
        std::cout << std::setw(10) << std::right << str;
    }
}

/**
 * Displays a list of all saved contacts in a table.
 * Then prompts for an index to display full details of a specific contact.
 */
void PhoneBook::searchContact() 
{
    if (_count == 0) 
    {
        std::cout << "\nPhonebook is currently empty.\n" << std::endl;
        return;
    }

    std::cout << "\n|     Index|First Name| Last Name|  Nickname|" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;

    for (int i = 0; i < _count; i++) 
    {
        std::cout << "|         " << i << "|";
        _formatColumn(_contacts[i].getFirstName()); std::cout << "|";
        _formatColumn(_contacts[i].getLastName());  std::cout << "|";
        _formatColumn(_contacts[i].getNickname());  std::cout << "|" << std::endl;
    }

    std::string input;
    std::cout << "\nEnter index to view details: " << std::flush;
    if (!std::getline(std::cin, input)) 
    {
        return ;
    }

    if (input.length() == 1 && input[0] >= '0' && input[0] < '0' + _count) 
    {
        int idx = input[0] - '0';
        std::cout << "\n[ Contact #" << idx << " ]" << std::endl;
        std::cout << "First Name:     " << _contacts[idx].getFirstName() << std::endl;
        std::cout << "Last Name:      " << _contacts[idx].getLastName() << std::endl;
        std::cout << "Nickname:       " << _contacts[idx].getNickname() << std::endl;
        std::cout << "Phone Number:   " << _contacts[idx].getPhoneNumber() << std::endl;
        std::cout << "Darkest Secret: " << _contacts[idx].getDarkestSecret() << "\n" << std::endl;
    } 
    else 
    {
        std::cout << "Invalid index! Back to main menu.\n" << std::endl;
    }
}