#pragma once

#include "person_with_telephone.h"
#include "person_with_email.h"

// Additional comments written in person_with_telephone_and_email.cpp

// Overloaded output operator
std::ostream & operator<<(std::ostream &out, const person &p);

// Overloaded equal operator
bool operator==(const person &p1, const person &p2);

// Overloaded less than operator
bool operator<(const person &p1, const person &p2);

// A class that inherits from 2 classes: person with telephone and person with email
// So this class contains name, surname, telephone and an e-mail address
class person_with_telephone_and_email : public person_with_telephone, public person_with_email
{
public:

	// Constructor
	person_with_telephone_and_email(std::string n, std::string s, std::string t, std::string e); 

	// Get for attribute values
	bool has_telephone_p(); 
	bool has_email_p(); 

	// An output function
	void display() const;
	

};



