#pragma once
#include <iostream>
#include <string>
#include <exception>

class AForm; // Forward declaration

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		class GradeTooHighException : public std::exception {
			public:
				[[nodiscard]] const char* what() const noexcept override { return "Bureaucrat grade is too high!"; }
		};
		class GradeTooLowException : public std::exception {
			public:
				[[nodiscard]] const char* what() const noexcept override { return "Bureaucrat grade is too low!"; }
		};

		[[nodiscard]] const std::string& getName() const;
		[[nodiscard]] int getGrade() const;
		
		void incrementGrade();
		void decrementGrade();
		
		void signForm(AForm& form);
		void executeForm(AForm const & form);
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& cog);