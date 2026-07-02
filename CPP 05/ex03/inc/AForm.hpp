#pragma once
#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecute;

	public:
		AForm();
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm(); // Must be virtual for abstract base class

		class GradeTooHighException : public std::exception {
			public:
				[[nodiscard]] const char* what() const noexcept override { return "Form grade requirement is too high!"; }
		};
		class GradeTooLowException : public std::exception {
			public:
				[[nodiscard]] const char* what() const noexcept override { return "Bureaucrat grade is too low!"; }
		};
		class FormNotSignedException : public std::exception {
			public:
				[[nodiscard]] const char* what() const noexcept override { return "Form is not signed!"; }
		};

		[[nodiscard]] const std::string& getName() const;
		[[nodiscard]] bool getIsSigned() const;
		[[nodiscard]] int getGradeToSign() const;
		[[nodiscard]] int getGradeToExecute() const;

		void beSigned(const Bureaucrat& bureaucrat);
		
		// The template method for execution
		void execute(Bureaucrat const & executor) const;

		// The pure virtual function that makes this class abstract
		virtual void executeAction() const = 0;
};

std::ostream& operator<<(std::ostream& out, const AForm& form);