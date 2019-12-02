#include "stdafx.h"

#include "person_with_telephone.h"

// Default constructor initialising a reasonable value
person_with_telephone::person_with_telephone() { _telephone = "0"; }

// A constructor that takes in 3 parameters for
// name, surname and telephone number
// Using constructor from parent class to initialise
// parent values
person_with_telephone::person_with_telephone(std::string n, std::string s, std::string t) : person(n, s), _telephone(t) {}

// A constructor that takes in only 1 parameter to
// initialise the telephone number. Used in children classes
person_with_telephone::person_with_telephone(std::string t) : _telephone(t) {}

// Set function to set the the telephone number
void person_with_telephone::set_telephone(std::string t) { _telephone = t; }

// Get function to retrieve the telephone number;
std::string person_with_telephone::telephone() const { return _telephone; }

// Returns true because it has a telephone number
bool person_with_telephone::has_telephone_p() { return true; }
bool person_with_telephone::has_email_p() { return false; }

// An output function to display ONLY this class's
// attributes
void person_with_telephone::own_display() const
{
	std::cout << " T " << telephone();
}

// An output function called from the operator<<
void person_with_telephone::display() const
{
	// Display only the person class's attributes
	person::own_display();
	own_display();
	std::cout << " >" << "\n";
}