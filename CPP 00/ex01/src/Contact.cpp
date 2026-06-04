#include "Contact.hpp"

/*
 * Default constructor.
 */
Contact::Contact() {}

/*
 * Destructor.
 */
Contact::~Contact() {}

/*
 * Setters: Update the contact's details.
 * These void functions assign the provided strings to their respective private member variables.
 */
void Contact::setFirstName(const std::string& str) { _firstName = str; }
void Contact::setLastName(const std::string& str) { _lastName = str; }
void Contact::setNickname(const std::string& str) { _nickname = str; }
void Contact::setNum(const std::string& str) { _num = str; }
void Contact::setSecret(const std::string& str) { _secret = str; }

/*
 * Getters: Retrieve the contact's details.
 * These functions return the respective private member variables as std::strings.
 */
std::string Contact::getFirstName() const { return _firstName; }
std::string Contact::getLastName() const { return _lastName; }
std::string Contact::getNickname() const { return _nickname; }
std::string Contact::getNum() const { return _num; }
std::string Contact::getSecret() const { return _secret; }