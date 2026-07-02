#pragma once
#include "AForm.hpp"
#include <string>

class Intern
{
	private:
		// Helper functions to create specific forms
		AForm* makeShrubbery(const std::string& target) const;
		AForm* makeRobotomy(const std::string& target) const;
		AForm* makePresidential(const std::string& target) const;

	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();

		// The main factory method
		[[nodiscard]] AForm* makeForm(const std::string& formName, const std::string& target) const;
};