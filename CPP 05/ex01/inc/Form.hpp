#pragma once
#include <iostream>
#include <string>
#include <exception>

// Forward declaration to prevent circular dependency
class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecute;

	public:
		Form();
		Form(std::string name, int gradeToSign, int gradeToExecute);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		class GradeTooHighException : public std::exception {
			public:
				[[nodiscard]] const char* what() const noexcept override { return "Form grade is too high!"; }
		};
		class GradeTooLowException : public std::exception {
			public:
				[[nodiscard]] const char* what() const noexcept override { return "Form grade is too low!"; }
		};

		[[nodiscard]] const std::string& getName() const;
		[[nodiscard]] bool getIsSigned() const;
		[[nodiscard]] int getGradeToSign() const;
		[[nodiscard]] int getGradeToExecute() const;

		void beSigned(const Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& out, const Form& form);