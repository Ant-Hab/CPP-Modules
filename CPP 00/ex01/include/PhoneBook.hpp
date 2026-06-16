#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <iomanip> // Required for std::setw
# include <limits>  // Required for std::numeric_limits
# include "Contact.hpp"

class PhoneBook {
private:
    Contact _contacts[8];
    int     _totalContacts;
    int     _nextIndex;

    std::string readRequiredField(const std::string& prompt);
    std::string formatTable(const std::string& str) const;

public:
    PhoneBook();
    ~PhoneBook();

    void addContact();
    void displayContact() const;
};

#endif