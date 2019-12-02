#include "stdafx.h"
#include"person_with_email.h"

// A constructor that takes in 3 parameters for
// name, surname and e-mail address
// Using constructor from parent class to initialise
// parent values
person_with_email::person_with_email(std::string n, std::string s, std::string e) : person(n, s), _email(e) {}

// A constuctor that takes in only 1 parameter
// for the e-mail std::string
// Used in children classes
person_with_email::person_with_email(std::string e) : _email(e) {}

// Set function for e-mail std::string
void person_with_email::set_email(std::string e) { _email = e; }

// Get function that returns the e-mail std::string
std::string person_with_email::email() const { return _email; }

// Returns false for telephone because this
// class does not have a telephone number
bool person_with_email::has_telephone_p() { return false; }

// Returns true because this class contains
// an e-mail address
bool person_with_email::has_email_p() { return true; }

// Output function to display ONLY
// this class's 
void person_with_email::own_display() const
{
	std::cout << " E " << email();
}

// An output function called
// from operator<<
void person_with_email::display() const
{
	// Display only the person's attributes
	person::own_display();
	own_display();
	std::cout << " >" << "\n";
}