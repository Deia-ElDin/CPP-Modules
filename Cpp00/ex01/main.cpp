#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	myPhonebook;
	std::string	command;

	while (true)
	{
		Printer::printMenu();
		command	= Printer::getUserInput("Enter your choice: ");
		if (command.empty()) break ;

		if (command == "ADD") myPhonebook.addContact();
		else if (command == "SEARCH") myPhonebook.searchContact();
		else if (command == "EXIT") break;
		else Printer::printErr("Invalid command. Please try again.");
	}
    return 0;
}
