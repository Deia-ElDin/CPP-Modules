#include "Harl.hpp"

void	Harl::debug (void) {
	std::cout << "(DEBUG) I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info (void) {
	std::cout << "(INFO) I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning (void) {
	std::cout << "(WARNING) I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error (void) {
	std::cout << "(ERROR) This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level) {
	void (Harl::*functions[4])(void) = {
        &Harl::debug, 
        &Harl::info, 
        &Harl::warning, 
        &Harl::error
    };

	int levelNumber = getLevelNumber(level);

	if (levelNumber < 4)
		(this->*functions[levelNumber])();
	else
	 	std::cout << "Unknown complaint level: " << level << std::endl;
}

int	getLevelNumber(std::string level) {
	int i;
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	for (i = 0; i < 4; i++)
		if (levels[i] == level) break;
	return (i);
}

/*
    Function Pointer Array in complain()
        -   The complain() function uses an array of function pointers to call the appropriate function based on the complaint level. 
        -   The functions array contains pointers to the debug(), info(), warning(), and error() member functions of the Harl class.
        -   In the complain() method, you're using an array of pointers to member functions. This is a powerful technique in C++ that allows you to store member functions in an array and call them dynamically.

        -   void (Harl::*functions[4])(void) = {&Harl::debug, 
                                    &Harl::info, 
                                    &Harl::warning, 
                                    &Harl::error};
            .   void (Harl::*functions[4])(void):
                    > void is the return type of the functions.
                    > Harl::* indicates these are pointers to member functions of the Harl class.
                    > (void) indicates that the functions take no arguments.
                    > functions is now an array of pointers to the four Harl member functions.

    Dynamic Method Call Using a Function Pointer
        -   (this->*functions[levelNumber])()
            .   this->* is used to dereference a member function pointer.
            .   functions[levelNumber] accesses the appropriate function pointer from the array.
            .   The function is then called with ().
*/
