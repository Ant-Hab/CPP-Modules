#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact {
private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _num;
	std::string _secret;

public:
	Contact();
	~Contact();

	void setFirstName(const std::string& str);
	void setLastName(const std::string& str);
	void setNickname(const std::string& str);
	void setNum(const std::string& str);
	void setSecret(const std::string& str);

	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickname() const;
	std::string getNum() const;
	std::string getSecret() const;
};

#endif