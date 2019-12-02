#include "stdafx.h"
#include"person_with_telephone_and_email.h"

// The output operator which takes in an
// output stream as a parameter and a referenced person object
std::ostream & operator<<(std::ostream &out, const person &p)
{
	// Calling the person's display function
	// which will be called appropriately
	p.display();
	return out;
}

// The compare operator which takes in two referenced
// person objects
bool operator==(const person &p1, const person &p2)
{
	// If both the surnames and the names of
	// the persons match, it returns true
	if (p1.surname() == p2.surname() && p1.name() == p2.name())
	{
		return true;
	}
	else
	{
		return false;
	}
}

// The less than operator which takes in two
// referenced person objects
bool operator<(const person &p1, const person &p2)
{
	// If the p1's surname is before p2's surname
	// alphabetically, then it returns true
	if (p1.surname() < p2.surname())
	{
		return true;
	}
	// If not, then check if their surnames
	// match
	else if (p1.surname() == p2.surname())
	{
		// Now it checks if p1's name is before
		// p2's name alphabetically and returns true
		// if it does
		if (p1.name() < p2.name())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}

}

// A constructor that takes in 4 parameters to initialise the
// values in the parent classes
person_with_telephone_and_email::person_with_telephone_and_email(std::string n, std::string s, std::string t, std::string e) : 
	person(n, s), person_with_telephone(t), person_with_email(e) {}

// Returns true in both methods because
// this class contains a telephone number
// an e-mail address
bool person_with_telephone_and_email::has_telephone_p() { return true; }
bool person_with_telephone_and_email::has_email_p() { return true; }

// An output function called from the operator<<
void person_with_telephone_and_email::display() const
{
	person::own_display();
	person_with_telephone::own_display();
	person_with_email::own_display();
	std::cout << " >" << "\n";
}
