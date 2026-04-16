#include "Contact.hpp"

Contact::Contact() {}
Contact::~Contact() {}

/**
 * Updates all fields of a contact at once.
 */
void Contact::setInfo(std::string f, std::string l, std::string n, std::string p, std::string s) 
{
    _firstName = f;
    _lastName = l;
    _nickname = n;
    _phoneNumber = p;
    _darkestSecret = s;
}

/**
 * Getters to retrieve private member data.
 */
std::string Contact::getFirstName() const     { return (_firstName); }
std::string Contact::getLastName() const      { return (_lastName); }
std::string Contact::getNickname() const      { return (_nickname); }
std::string Contact::getPhoneNumber() const   { return (_phoneNumber); }
std::string Contact::getDarkestSecret() const { return (_darkestSecret); }