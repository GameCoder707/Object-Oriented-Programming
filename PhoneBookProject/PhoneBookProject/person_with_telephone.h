#pragma once

#include "person.h"

// Additional comments are written in person_with_telephone.cpp

// This class virtually inherits from person class
// to store a telephone number along with the full name
// It's inherited virtually for this class's children classes
class person_with_telephone : virtual public person
{
protected:
	// A std::string variable to store the telephone number
	// It's a std::string to store characters like '+' and '-'
	std::string _telephone;

public:
	// Constructors
	person_with_telephone();
	person_with_telephone(std::string n, std::string s, std::string t);
	person_with_telephone(std::string t);

	// Set
	void set_telephone(std::string t);

	// Get
	std::string telephone() const;

	// Get for attributes
	bool has_telephone_p();
	bool has_email_p(); 

	// Output functions
	void own_display() const;
	void display() const;
	

	
	

};
