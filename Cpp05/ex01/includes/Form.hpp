#ifndef __FORM_HPP__
#define __FORM_HPP__

#include "Utils.hpp"
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_executeGrade;

	public:
		Form();
		Form(
			const std::string& name,
			bool isSigned,
			const int signGrade,
			const int executeGrade
		);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		void    			beSigned(Bureaucrat &bureaucrat);
								
		const std::string	getName() const;
		bool				getIsSigned() const;
		int					getSignGrade() const;
		int					getExecuteGrade() const;

		void    			printSignedState();

		class SignedFormException : public std::exception {
			public:
				virtual const char* what() const _NOEXCEPT;
		};

		class EmptyNameException : public std::exception {
			public:
				virtual const char* what() const _NOEXCEPT;
		};

		class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const _NOEXCEPT;
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const _NOEXCEPT;
        };
};

// std::ostream& operator<<(stdLLostream& os, const Form& form);

#endif // __FORM_HPP__