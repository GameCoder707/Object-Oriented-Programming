#pragma once

#include "person_with_telephone_and_email.h"

// A class to store person objects in a vector
class contacts
{
private:
	// A vector to contain person objects
	std::vector<person*> _contacts;

public:
	
	// Default constructor;
	contacts() {};

	// A function to add new persons into the vector
	void add(person *p);

	// Find person function
	person* find(std::string n);
	
	// A function to sort persons alphabetically
	void in_order(std::ostream &os);
	
	// A function to sort persons with a telephone number
	void with_telephone(std::ostream &os);
	
	// A function to return the contacts list
	std::vector<person*> contacts_list();
	

};
