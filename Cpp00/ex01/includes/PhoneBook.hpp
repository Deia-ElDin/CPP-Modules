#pragma once
#ifndef __PHONE_BOOK_HPP__
# define __PHONE_BOOK_HPP__

# include <iostream>
# include <iomanip>
# include <string>
# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	contacts[8];
		int		contact_count;
	
	public:
		PhoneBook();
		void	add_contact();
		void	search_contact();
		void	exit_phonebook();
};

#endif

/*
	-   #pragma once: 
			This is a non-standard preprocessor directive supported by most C++ compilers
			that prevents the current file from being included more than once in a single compilation.

	-   #ifndef __PHONE_BOOK_HPP__, why __ at the beginning and end of the macro name?
			The __PHONE_BOOK_HPP__ is a macro name, and the __ at the beginning and end of the macro name
			is a convention to prevent the macro name from conflicting with other macro names. 

	-   include <iostream>:
			The iostream is a header file in C++,
			that contains the declarations of the basic standard input-output library in C++.
			The iostream header file provides the basic input and output services for C++ programs.

	-   include <iomanip>:
			The iomanip is a header file in C++ that is used to manipulate the output of C++ programs. 
			The iomanip header file provides several manipulators that can be used to format the output of C++ programs.
		
	-   include <string>:
			The string is a header file in C++ that provides the string class, which is used to manipulate sequences of characters.
			The string class in C++ provides many built-in methods for string manipulation, such as concatenation, finding substrings, replacing parts of the string, etc.

	-	Constructors in C++:
			A constructor is a special member function of a class that is automatically called when an object of that class is created.
			A constructor has the same name as the class and does not have a return type. 
			Constructors are called automatically when an object is created, and they can be used to initialize the object's data members.
*/
