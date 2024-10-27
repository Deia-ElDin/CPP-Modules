#ifndef __A_FORM_HPP__
#define __A_FORM_HPP__

#include "Utils.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_executeGrade;

	public:
		AForm();
		AForm(
			const std::string&	name,
			const int 			signGrade,
			const int 			executeGrade
		);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		~AForm();

		void    			beSigned(Bureaucrat &bureaucrat);
		const std::string	getName() const;
		bool				getIsSigned() const;
		int					getSignGrade() const;
		int					getExecuteGrade() const;

		virtual void		execute(const Bureaucrat& executor) const = 0; // Abstract the Class Abstract

		class EmptyNameException : public std::exception {
			public:
				virtual const char* what() const _NOEXCEPT;
		};

		class SignedFormException : public std::exception {
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

		class FormNotSignedException : public std::exception {
			public:
				virtual const char* what() const _NOEXCEPT;
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif // __A_FORM_HPP__