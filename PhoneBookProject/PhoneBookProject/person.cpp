#include "stdafx.h"

#include "person.h"

// Default Constructor initialising
// reasonable values
person::person()
{
	if (name() != "" && surname() != "")
	{
		set_name("Name");
		set_surname("Surname");
	}
}

// Constructor that takes in two parameters
// for name and surname
person::person(std::string n, std::string s) : _name(n), _surname(s) {}

// Set functions for name and surname
void person::set_name(std::string n) { _name = n; }
void person::set_surname(std::string s) { _surname = s; }

// Get functions for name and surname
const std::string person::name() const { return _name; }
const std::string person::surname() const { return _surname; }

// This class has no values so returns false for both
bool person::has_telephone_p() { return false; }

bool person::has_email_p() { return false; }

// An output function called from operator<< to
// display this class's attributes in a format
void person::display() const
{
	own_display();
	std::cout << " >" << "\n";

}

// An output function to print ONLY
// this class's attributes
void person::own_display() const
{
	std::cout << "<person S " << surname() << " N " << name();
}