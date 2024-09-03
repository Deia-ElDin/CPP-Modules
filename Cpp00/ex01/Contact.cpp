#include "Contact.hpp"

// Default Constructor: Contact::Contact()
Contact::Contact()
{
   	firstName = "";
	lastName = "";
	nickName = "";
	phoneNumber = "";
	darkestSecret = "";
}

// Parameterized Constructor: Contact::Contact(...)
Contact::Contact(const std::string &first_name, 
				const std::string &last_name, 
				const std::string &nick_name, 
				const std::string &phone_number, 
				const std::string &darkest_secret)
{
	this->firstName = first_name;
	this->lastName = last_name;
	this->nickName = nick_name;
	this->phoneNumber = phone_number;
	this->darkestSecret = darkest_secret;
}

// Setters
void	Contact::setFirstName(const std::string &first_name) {
	this->firstName = first_name; // Assign the parameter to the member variable
}

void	Contact::setLastName(const std::string &last_name) {
	this->lastName = last_name;
}

void	Contact::setNickName(const std::string &nick_name) {
	this->nickName = nick_name;
}

void	Contact::setPhoneNumber(const std::string &phone_number) {
	this->phoneNumber = phone_number;
}

void	Contact::setDarkestSecret(const std::string &darkest_secret) {
	this->darkestSecret = darkest_secret;
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

	*   Parameterized Constructor: Contact::Contact(...)
		-   A parameterized constructor is a constructor that takes one or more 
			arguments and is used to initialize the object's data members with 
			the values passed as arguments.
		-   The parameterized constructor is called automatically when an object 
			is created with arguments, and it is used to initialize the object's 
			data members with the values passed as arguments.
		-   The parameterized constructor is used to create objects with specific 
			values for their data members.

	*   void	Contact::setFirstName(const std::string &first_name)
		{
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
