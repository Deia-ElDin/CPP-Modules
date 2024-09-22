#ifndef __FORM_HPP__
#define __FORM_HPP__

#include "Utils.hpp"

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_executeGrade;

	public:
		Form(
			const std::string& name,
			bool isSigned,
			const int signGrade,
			const int executeGrade
		);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		void				setName(const std::string& name);
		void				setIsSigned(bool isSigned);
		void				setSignGrade(const int signGrade);
		void				setExecuteGrade(const int executeGrade);
		void				setForm(const std::string& name,
									bool isSigned,
									const int signGrade,
									const int executeGrade);
								
		const std::string	getName() const;
		bool				getIsSigned() const;
		const int			getSignGrade() const;
		const int			getExecuteGrade() const;

		class NameException: public std::exception {
			public:
				virtual const char* what() const _NOEXCEPT;
		}

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