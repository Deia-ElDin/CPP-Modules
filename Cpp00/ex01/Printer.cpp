#include "Printer.hpp"

// Helpers Functions
void	tableDecoration() {
	for (size_t i = 0; i < 45; i++) std::cout << "-";
	std::cout << Nl;
}

std::string formatField(const std::string &value) {
	if (value.length() > 10) return value.substr(0, 9) + ".";
	else return value;
}

std::string Printer::getUserInput(std::string prompt) {
	std::string input;

	// Prompting the User: You prompt the user to enter their first name.
	// Reading Input with std::getline:
	// std::getline to safely read a full line of input from the user.
	// std::cin to read input from the user.
	// std::ws to handle any leading whitespace.
	// store the input in the firstName variable.
	std::cout << Nl Bold Yellow << prompt << Reset;
	std::getline(std::cin >> std::ws, input);
	return std::cin.eof() ? "" : input;
}

void    Printer::printErr(const std::string &errMsg) {
	std::cerr << Nl Bold Red << "Error: " << errMsg << Reset << Nl;
}

void    Printer::printSuccess(const std::string &successMsg) {
	std::cout << Nl Bold Green << "Success: " << successMsg << Reset << Nl;
}

void    Printer::printUnderLine(const std::string &msg) {
	std::cout << Nl Bold Underline << msg << Reset << Nl;
}

void	Printer::printMsg(const std::string &msg) {
	std::cout << Nl Bold << msg << Reset << Nl;
}

void	Printer::printMenu() {
	std::cout << Nl Bold Blue << "Select an option:" << Reset << Nl;
	std::cout << "1. ADD" << Nl;
	std::cout << "2. SEARCH" << Nl;
	std::cout << "3. EXIT" << Nl;
}

void    Printer::printTableHeader() {
	std::cout << Nl;
	tableDecoration();
	std::cout << std::right << "|"
			<< std::setw(10) << "Index" << "|"
			<< std::setw(10) << "First Name" << "|"
			<< std::setw(10) << "Last Name" << "|"
			<< std::setw(10) << "Nick Name" << "|"
			<< Nl;
	tableDecoration();
}

void    Printer::printTableBody(
	const std::string &index, 
	const std::string &firstName, 
	const std::string &lastName, 
	const std::string &nickName) {
	std::cout << std::right << "|"
			<< std::setw(10) << formatField(index ) << "|"
			<< std::setw(10) << formatField(firstName) << "|"
			<< std::setw(10) << formatField(lastName) << "|"
			<< std::setw(10) << formatField(nickName) << "|"
			<< Nl;
	tableDecoration();
}

void    Printer::printContact(
	const std::string &firstName, 
	const std::string &lastName, 
	const std::string &nickName,
	const std::string &phoneNumber,
	const std::string &darkestSecret) {
	std::cout << Nl Bold Magenta << "Contact Details:" << Reset Nl;
	std::cout << "First Name: " << firstName + Nl;
	std::cout << "Last Name: " << lastName + Nl;
	std::cout << "Nick Name: " << nickName + Nl;
	std::cout << "Phone Number: " << phoneNumber + Nl;
	std::cout << "Darkest Secret: " << darkestSecret + Nl;
}
