#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>

/**
 * Represents a single person in the PhoneBook.
 * Contains private data and public accessors.
 */
class Contact
{
private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _darkestSecret;

public:
    Contact();
    ~Contact();

    void        setInfo(std::string f, std::string l, std::string n, std::string p, std::string s);

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;
};

#endif