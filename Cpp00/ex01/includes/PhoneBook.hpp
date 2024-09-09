#ifndef __PHONE_BOOK_HPP__
# define __PHONE_BOOK_HPP__

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact		contacts[2];
		int			contactCount;
		int			currentIndex;
	
	public:
		PhoneBook();
		~PhoneBook();

		// Member Functions
		void	addContact();
		void	searchContact();
};

#endif

/*
	-   #ifndef __PHONE_BOOK_HPP__, why __ at the beginning and end of the macro name?
			The __PHONE_BOOK_HPP__ is a macro name, and the __ at the beginning and end of the macro name
			is a convention to prevent the macro name from conflicting with other macro names. 

	-	Constructors in C++:
			A constructor is a special member function of a class that is automatically called when an object of that class is created.
			A constructor has the same name as the class and does not have a return type. 
			Constructors are called automatically when an object is created, and they can be used to initialize the object's data members.
*/
