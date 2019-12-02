#pragma once

// Additional comments are written in person_with_email.cpp

#include "person.h"

// This class virtually inherits from person class
// to store a e-mail address along with the full name
// It's inherited virtually for this class's children classes 
class person_with_email : virtual public person
{
protected:
	// A std::string variable to store
	// the person
	std::string _email;

public:
	// Constructors
	person_with_email(std::string n, std::string s, std::string e);
	person_with_email(std::string e);

	// Set
	void set_email(std::string e);

	//Get
	std::string email() const;

	// Get for attributes
	bool has_telephone_p(); 
	bool has_email_p();

	// Output functions
	void own_display() const;
	void display() const;

	

};
