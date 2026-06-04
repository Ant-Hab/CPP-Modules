#include "PhoneBook.hpp"

/*
 * Initializes the phonebook, setting the total contact count
 * and the circular buffer index to 0.
 */
PhoneBook::PhoneBook() : _totalContacts(0), _nextIndex(0) {}

/*
 * Destructor.
 */
PhoneBook::~PhoneBook() {}

/*
 * Prompts the user for input and loops until a non-empty, non-whitespace 
 * string is provided. Handles EOF (Ctrl+D) gracefully.
 */
std::string PhoneBook::readRequiredField(const std::string& prompt)
{
	std::string input;

	while (true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, input))
			return "";
		if (!input.empty() && input.find_first_not_of(" \t\n\r") != std::string::npos)
			return input;
		std::cout << "Field can't be empty." << std::endl;
	}
}

/*
 * Collects contact information from the user and adds it to the phonebook.
 * If the maximum of 8 contacts is reached, replaces the oldest contact.
 */
void PhoneBook::addContact()
{
	Contact addedContact;
	std::string input;

	input = readRequiredField("First name: ");
	if (input.empty()) return;
	addedContact.setFirstName(input);

	input = readRequiredField("Last name: ");
	if (input.empty()) return;
	addedContact.setLastName(input);

	input = readRequiredField("Nickname: ");
	if (input.empty()) return;
	addedContact.setNickname(input);

	input = readRequiredField("Phone number: ");
	if (input.empty()) return;
	addedContact.setNum(input);

	input = readRequiredField("Darkest secret: ");
	if (input.empty()) return;
	addedContact.setSecret(input);

	_contacts[_nextIndex] = addedContact;
	std::cout << "Contact successfully added at index " << _nextIndex << std::endl;
	
	if (_totalContacts < 8)
	{
		_totalContacts++;
	}
	
	_nextIndex = (_nextIndex + 1) % 8;
}

/*
 * Formats a string to fit a 10-character column limit.
 * Truncates and appends a dot ('.') if the string exceeds 10 characters.
 */
std::string PhoneBook::formatTable(const std::string& str) const
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	else
		return str;
}

/*
 * Displays a formatted table of all saved contacts.
 * Prompts the user to enter an index to view a specific contact's full details.
 */
void PhoneBook::displayContact() const
{
	int index = 0;
	if (_totalContacts == 0)
	{
		std::cout << "Phonebook is empty. Please add some contacts." << std::endl;
		return;
	}
	
	for (int i = 0; i < _totalContacts; i++)
	{
		std::cout << std::setw(10) << i << '|'
				  << std::setw(10) << formatTable(_contacts[i].getFirstName()) << '|'
				  << std::setw(10) << formatTable(_contacts[i].getLastName()) << '|'
				  << std::setw(10) << formatTable(_contacts[i].getNickname())
				  << std::endl;
	}
	
	while (true)
	{
		std::cout << "Enter the index of the contact you want to see: ";
		std::cin >> index;
		
		if (std::cin.eof()) 
		{
			std::cin.clear();
			return;
		} 
		
		if (std::cin.fail()) 
		{
			std::cout << "Invalid index. Enter a number." << std::endl;
			std::cin.clear(); 
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
			continue;
		}
		
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
		
		if (index < 0 || index >= _totalContacts)
		{
			std::cout << "Invalid index. Try again." << std::endl;
			continue;
		}
		break;
	}

	std::cout << "First name: " << _contacts[index].getFirstName() << std::endl;
	std::cout << "Last name: " << _contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << _contacts[index].getNickname() << std::endl;
	std::cout << "Phone number: " << _contacts[index].getNum() << std::endl;
	std::cout << "Darkest secret: " << _contacts[index].getSecret() << std::endl;
}