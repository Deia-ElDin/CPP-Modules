#ifndef __CONTACT_HPP__
# define __CONTACT_HPP__

#include "Printer.hpp"

class   Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;

	public:
		// Default Constructor
		Contact();

		// Setters
		void		setFirstName(const std::string &firstName);
		void		setLastName(const std::string &lastName);
		void		setNickName(const std::string &nickName);
		void		setPhoneNumber(const std::string &phoneNumber);
		void		setDarkestSecret(const std::string &darkestSecret);
		bool		setContact(const std::string &firstName, 
							   const std::string &lastName, 
							   const std::string &nickName, 
							   const std::string &phoneNumber, 
							   const std::string &darkestSecret);
		// Getters
		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getNickName() const;
		std::string	getPhoneNumber() const;
		std::string	getDarkestSecret() const;
};

#endif

/*
	*	void		setFirstName(const std::string &firstName);
		{
			Why Use & in const std::string &firstName:
			Efficiency: By passing firstName by reference, you avoid the potentially expensive operation of copying a large string. The function can directly access the original string without needing to create a duplicate.

			Safety: The const keyword ensures that even though you're passing by reference, the function can't modify the original string. This combines the efficiency of passing by reference with the safety of passing by value.

			What Happens Without &:
			If you wrote the function as void Contact::setFirstName(std::string firstName), it would still work, but:
			A Copy is Made: The firstName parameter would be a copy of the argument passed to the function. Inside the function, you'd be working with the copy, not the original string.
			Extra Overhead: Making this copy can introduce unnecessary overhead, particularly with large strings or in performance-critical applications.

			When to Use Which:
			Use const std::string &: When you want to pass a string (or any large object) to a function without modifying it and without incurring the cost of copying it.
			Use std::string: When you intentionally need a copy of the object within the function (for example, if the function is going to modify the string and you don't want those modifications to affect the original string).
		}
*/
