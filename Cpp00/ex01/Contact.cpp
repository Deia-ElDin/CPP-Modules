#include "Contact.hpp"

// Helpers Functions
bool	allAlpha(const std::string &str) {
	for(size_t i = 0; i < str.length(); i++) {
        if (!std::isalpha(str[i])) return false;
	}
	return true; 
}

bool	allDigits(const std::string &str) {
	for(size_t i = 0; i < str.length(); i++) {
		if (!std::isdigit(str[i])) return false;
	}
	return true; 
}

bool	validateField(
	const std::string &field, 
	const std::string &fieldName, 
	bool alphaOnly = false, 
	bool digitsOnly = false) {
	if (field.empty()) return false;
    if (alphaOnly && !allAlpha(field)) {
        Printer::printErr(fieldName + " must contain only alphabetic characters.");
        return false;
    }
    if (digitsOnly && !allDigits(field)) {
        Printer::printErr(fieldName + " must contain only numeric characters.");
        return false;
    }
    return true;
}

// Default Constructor: Contact::Contact(), Member Initializer List
Contact::Contact() 
    : firstName(""), 
      lastName(""), 
      nickName(""), 
      phoneNumber(""), 
      darkestSecret("") {}

// Setters
void	Contact::setFirstName(const std::string &firstName) {
    this->firstName = firstName; // Assign the first name if valid
}

void	Contact::setLastName(const std::string &lastName) {
	this->lastName = lastName;
}

void	Contact::setNickName(const std::string &nickName) {
	this->nickName = nickName;
}

void	Contact::setPhoneNumber(const std::string &phoneNumber) {
	this->phoneNumber = phoneNumber;
}

void	Contact::setDarkestSecret(const std::string &darkestSecret) {
	
	this->darkestSecret = darkestSecret;
}

bool	Contact::setContact(
	const std::string &firstName, 
    const std::string &lastName, 
    const std::string &nickName, 
    const std::string &phoneNumber, 
    const std::string &darkestSecret) {

	if (!validateField(firstName, "First Name", true)) return false;
	if (!validateField(lastName, "Last Name", true)) return false;
	if (!validateField(nickName, "Nick Name")) return false;
	if (!validateField(phoneNumber, "Phone Number", false, true)) return false;
	if (!validateField(darkestSecret, "Darkest Secret")) return false;
	
	setFirstName(firstName);
	setLastName(lastName);
	setNickName(nickName);
	setPhoneNumber(phoneNumber);
	setDarkestSecret(darkestSecret);
	return true;
}

// Getters
std::string	Contact::getFirstName() const {
	return (this->firstName);
}

std::string	Contact::getLastName() const {
	return (this->lastName);
}

std::string	Contact::getNickName() const {
	return (this->nickName);
}

std::string	Contact::getPhoneNumber() const {
	return (this->phoneNumber);
}

std::string	Contact::getDarkestSecret() const {
	return (this->darkestSecret);
}

/*
	*   Default Constructor: Contact::Contact()
		-   The default constructor is a constructor that is automatically 
			called when an object is created without any arguments.
		-   The default constructor does not take any arguments, and it is 
			used to initialize the object's data members to default values.
		-   The default constructor is called automatically when an object 
			is created, and it is used to initialize the object's data members to default values.

		1-	
			Contact::Contact()
			{
				firstName = "";
				lastName = "";
				nickName = "";
				phoneNumber = "";
				darkestSecret = "";
			}

		2-
			Contact::Contact()
				: firstName(""), 
				lastName(""), 
				nickName(""), 
				phoneNumber(""),
				darkestSecret("") {}

		3-
			Contact::Contact() {}

		-   The first constructor initializes the member variables in the constructor's
			body, while the second constructor uses the member initializer list to 
			initialize the member variables.

		1-   Here's what happen with the 1st constructor
			1-  Default Construction:
				.	When the Contact object is created, the member variables 
					(firstName, lastName, etc.) are default-constructed first.
				.	The default constructor of std::string initializes each string to an empty string ("").
				.	At this point, firstName, lastName, nickName, phoneNumber, 
					and darkestSecret are all already set to "".
			2-  Assignment in the Constructor Body:
				.	After the default construction, the constructor body runs.
				.	Here, the member variables are assigned new values.
				.	But since the default constructor already set them to "", 
					we're just replacing the default value with the same value.
				.	This is redundant and inefficient.

		2-  Here's what happen with the 2nd constructor
			The member variables directly, avoiding the default construction and assignment.
		
	
		3-  Here's what happen with the 3rd constructor
			This constructor will correctly initialize all std::string members to empty strings (""), 
			and you don't need to manually assign empty strings inside the constructor body.

		Why This Works:
			-	std::string members: They are automatically initialized to "" (empty string) when their default constructor is called.
			-	Empty constructor body: You don’t need to assign any values to std::string members because they are already initialized to empty strings by default.

	*   Parameterized Constructor: Contact::Contact(...), Member Initializer List:
		-   A parameterized constructor is a constructor that takes one or more 
			arguments and is used to initialize the object's data members with 
			the values passed as arguments.
		-   The parameterized constructor is called automatically when an object 
			is created with arguments, and it is used to initialize the object's 
			data members with the values passed as arguments.
		-   The parameterized constructor is used to create objects with specific 
			values for their data members.

		-	The member initializer list is used to initialize class member variables before the 
			constructor's body is executed.
		
		1-	
			Contact::Contact(
				const std::string &firstName, 
				const std::string &lastName, 
				const std::string &nickName, 
				const std::string &phoneNumber, 
				const std::string &darkestSecret) {
				this->firstName = firstName;
				this->lastName = lastName;
				this->nickName = nickName;
				this->phoneNumber = phoneNumber;
				this->darkestSecret = darkestSecret;
			}

		2-
			Contact::Contact(
				const std::string &firstName, 
				const std::string &lastName, 
				const std::string &nickName, 
				const std::string &phoneNumber, 
				const std::string &darkestSecret)
				: firstName(firstName), 
				lastName(lastName), 
				nickName(nickName), 
				phoneNumber(phoneNumber), 
				darkestSecret(darkestSecret) {}

		-   The first constructor initializes the member variables in the constructor's
			body, while the second constructor uses the member initializer list to 
			initialize the member variables.
		-   Using the member initializer list is more efficient for non-primitive types 
			and const members because it avoids the overhead of default initialization 
			and assignment.

	*   void	Contact::setFirstName(const std::string &firstName)
		{
			-	std::all_of(begin_iterator, end_iterator, predicate);
			-   The setFirstName method is a member function of the Contact class 
				that is used to set the value of the firstName data member.
			-   The setFirstName method takes a const reference to a string as an 
				argument and assigns the value of the argument to the firstName data member.
			-   The const keyword indicates that the argument is a constant reference, 
				which means that the argument cannot be modified inside the method.
		}

	*   std::string	Contact::getFirstName() const
		{
			-   The getFirstName method is a member function of the Contact class 
				that is used to get the value of the firstName data member.
			-   The getFirstName method returns the value of the firstName data member 
				as a string.
			-   The const keyword at the end of the method declaration indicates that 
				the method does not modify the object's data members.
		}
*/

/*
	*	Primitive Types (like int, char, float):
		-	Not initialized by default.
		-	You must explicitly initialize them, or they will contain garbage values.
		
	*	Non-Primitive Types (like std::string, std::vector):
		-	Automatically initialized by default.
		-	std::string is initialized to "", and std::vector is initialized to an empty vector.
*/
