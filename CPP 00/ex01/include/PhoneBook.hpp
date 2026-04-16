#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip>

/**
 * Manages an array of 8 contacts.
 * Handles the logic for adding, searching, and formatting output.
 */
class PhoneBook
{
private:
    Contact _contacts[8];
    int     _count;
    int     _oldestIndex;

    void    _formatColumn(std::string str) const;

public:
    PhoneBook();
    ~PhoneBook();

    void    addContact();
    void    searchContact();
};

#endif