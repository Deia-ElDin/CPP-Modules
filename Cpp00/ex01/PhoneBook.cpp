#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contactCount(0), currentIndex(0) {};

PhoneBook::~PhoneBook() {
	std::cout << Nl Bold Green << "Goodbye!" << Reset Nl;
};

void	PhoneBook::addContact() {
	std::string	firstName = Printer::getUserInput("Enter First Name: ");
	std::string	lastName = Printer::getUserInput("Enter Last Name: ");
	std::string	nickName = Printer::getUserInput("Enter Nick Name: ");
	std::string	phoneNumber = Printer::getUserInput("Enter Phone Number: ");
	std::string	darkestSecret = Printer::getUserInput("Enter Darkest Secret: ");
	Contact 	newContact;
	bool		isValidContact;

	isValidContact = newContact.setContact(firstName, lastName, nickName, phoneNumber, darkestSecret);

	if (isValidContact) Printer::printSuccess("Contact added successfully.");
	else return (Printer::printErr("Invalid contact. Please try again."));

	if (contactCount < 8) {
		contacts[contactCount] = newContact;
		contactCount++;
	} else {
		Printer::printMsg("PhoneBook is full. Replacing the oldest contact.");
		contacts[currentIndex] = newContact;
		currentIndex = (currentIndex + 1) % 8;
	}
}

void	PhoneBook::searchContact() {
	std::string	searchQuery;
	int			index;

	if (contactCount == 0) return (Printer::printErr("PhoneBook is empty."));

	Printer::printTableHeader();
	for (int i = 0; i < contactCount; i++) {
		Printer::printTableBody(
			std::to_string(i + 1),
			this->contacts[i].getFirstName(),
			this->contacts[i].getLastName(),
			this->contacts[i].getNickName()
		);
	}	

	searchQuery = Printer::getUserInput("Enter the index of the contact you want to search: ");
	for (size_t i = 0; i < searchQuery.length(); i++) {
		if (!std::isdigit(searchQuery[i])) {
            Printer::printErr("Invalid search query. Must contain only digits.");
			return;
		}
	}
	
	index = std::atoi(searchQuery.c_str());  
	if (index < 1 || index > contactCount)
		return (Printer::printErr("Invalid contact index. Please try again."));

	Printer::printContact(
		this->contacts[index - 1].getFirstName(),
		this->contacts[index - 1].getLastName(),
		this->contacts[index - 1].getNickName(),
		this->contacts[index - 1].getPhoneNumber(),
		this->contacts[index - 1].getDarkestSecret()
	);
}

/*
	*	PhoneBook::PhoneBook() : contactCount(0), currentIndex(0) {};
		-	Member initializer list in C++: It is used to initialize class 
			member variables before the constructor's body is executed.

		-	PhoneBook::PhoneBook() :
			This is the constructor of the PhoneBook class. 
			It is the special function that gets called when you create 
			an object of the PhoneBook class.

			Example: When you do PhoneBook myPhoneBook;, this constructor gets invoked.

		-	contactCount(0), currentIndex(0) :
			These are the member initializer list. 
			They are used to initialize the member variables of the class.
			It means that before the constructor’s body {} is executed, the member 
			variables contactCount and currentIndex will be initialized to 0.
		
		-	{} :
			This is the body of the constructor. 
			It is where you can write the code that you want to execute when 
			the object is created.

		Why Use a Member Initializer List?
		-	Efficiency:
			For primitive types like int, char, float, etc., there isn't a big performance difference between initializing them in the initializer list and initializing them in the constructor body. But for non-primitive types (such as classes and objects), const members, and references, using the initializer list is often more efficient. Here's why:

			+	Without an Initializer List (Constructor Body Initialization):
				If you don't use a member initializer list and instead initialize variables in the constructor body, here's what happens:

				1-	Default Constructor is Called:

					When you create an object, its members are first default-initialized (using the default constructor). Even if you plan to assign a value in the constructor body, this default initialization happens first.

				2-	Assignment in the Constructor Body:

					After the default initialization, the constructor body runs. Here, the member variables are assigned new values.

				So for non-primitive types like std::string, if you initialize them in the constructor body, you're essentially doing two operations:
					.	Default initialization (empty string or default state).
					.	Assignment (replacing the default value).

			+	With a Member Initializer List:
					When you use a member initializer list, the initialization is done directly with the specified value without calling the default constructor. The member is initialized with the correct value right from the start, avoiding the overhead of first creating a default object and then re-assigning it.

		-	Const and Reference Members:
			If your class contains const or reference members, they must be initialized in the member initializer list because they cannot be assigned to later in the constructor body.

		-	Clarity:
			It makes it clear what the initial values of your member variables are, which can improve the readability of your code.
*/
