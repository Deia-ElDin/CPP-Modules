#ifndef __PRINTER_HPP__
# define __PRINTER_HPP__

#include <iostream>		// For input/output operations (e.g., std::cout).
#include <iomanip> 		// For std::setw and std::right
#include <string>     	// For string manipulation (std::string class).

#define Red "\033[31m"
#define Green "\033[32m"
#define Yellow "\033[33m"
#define Blue "\033[34m"
#define Magenta "\033[35m"
#define Bold "\033[1m"
#define Underline "\033[4m"
#define Reset "\033[0m"
#define Nl "\n"

class Printer 
{
	public:
		static std::string	getUserInput(std::string prompt); 
		static void 		printErr(const std::string &errMsg);
		static void 		printSuccess(const std::string &successMsg);
		static void 		printUnderLine(const std::string &msg);
		static void 		printMsg(const std::string &msg);
		static void 		printMenu();
		static void 		printTableHeader();
		static void			printTableBody(const std::string &index, 
										   const std::string &firstName, 
										   const std::string &lastName, 
										   const std::string &nickName);
		static void			printContact(const std::string &firstName, 
										 const std::string &lastName, 
										 const std::string &nickName,
										 const std::string &phoneNumber,
										 const std::string &darkestSecret);
};

#endif

/*
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

	*   What Does a Static Method Mean?
		-   A static method is a method that belongs to the class rather than to any specific instance of the class.
		-   You can call the static method directly on the class without needing to create an instance of the class.
		-   Examples:
					-> without static method:
						Printer printer;
						printer.printErr("Error message");
					-> with static method:
						Printer::printErr("Error message");
					
	*   Why Use Static Methods?
		1- No Need for Object Instantiation.
		2- Better for Utility Classes.
			Utility classes, like your Printer class, often don’t need to store state, and their functions simply perform actions (like printing or formatting). Making the functions static reflects that they don’t rely on any instance-specific data.
		3- Efficiency:
			Static functions live at the class level, not the object level, so no memory is allocated for creating instances, and you avoid unnecessary instantiations.


	*   Instance Members Vs Static Members:
		-   Instance Members:
			class MyClass 
			{
				public:
					int instanceVar;  // Instance variable (non-static)

					void instanceMethod() {
						std::cout << "Instance variable: " << instanceVar << std::endl;
					} // This method operates on this specific instance
			};
			In this case, every time you create an object of MyClass, 
			it has its own copy of instanceVar and instanceMethod() operates on that particular object.
		-   Static Members:
			class MyClass 
			{
				public:
					static int staticVar;  // Static variable

					static void staticMethod() {
						std::cout << "Static variable: " << staticVar << std::endl;
					} // This method operates on the class itself
			};
			In this case, staticVar is shared among all instances of MyClass, 
			and staticMethod() operates on the class itself, not on any specific object.
*/
