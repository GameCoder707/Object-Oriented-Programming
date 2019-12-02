#include "stdafx.h"
#include "contacts.h"


// A function to check if dereferenced p1 is less
// than dereferenced p2
bool compare(const person *p1, const person *p2)
{
	return(*p1 < *p2);
}

void contacts::add(person *p)
{
	// Local boolean variable to
	// skip adding if it's the same person
	bool skip = false;

	// Using iterator, we loop through the contacts std::vector
	for (std::vector<person*>::iterator i = _contacts.begin(); i < _contacts.end(); ++i)
	{
		// Using overloaded operator==, we compare
		// their surnames AND names
		if (**i == *p)
		{
			// Replace the object
			*i = p;
			// and skip adding
			skip = true;
			break;
		}
	}

	// If the object replaced another object
	// then skip it
	if (skip == false)
	{
		_contacts.push_back(p);
	}

}

// A function that takes in a string parameter (name or surname)
// and find the person matching that name or surname
person* contacts::find(std::string n)
{
	// A temporary person object
	person* f = 0;

	// Looping through the contacts. Using an & symbol to reference
	// the std::string in a lambda function
	for_each(_contacts.begin(), _contacts.end(), [&](person* p)
	{
		// If the surname or name matches, set this person to return
		if (p->surname() == n || p->name() == n)
		{
			f = p;
			return;
		}

	});

	// Return the founded object
	return f;

}

// A function to order the list in alphabetical order
// by surname first and then by name.
// It takes an output stream as a parameter to print the
// contacts to the stream
void contacts::in_order(std::ostream &os)
{
	// Using sort algorithm to arrange them in alphabetical
	sort(_contacts.begin(), _contacts.end(), compare);

	for_each(_contacts.begin(), _contacts.end(), [&](person *p) { os << *p; });

}

// A function which sorts all persons in alphabetical order
// but prints only persons with a telephone.
// It also takes an output stream as a parameter to print the
// contacts to the stream
void contacts::with_telephone(std::ostream &os)
{
	sort(_contacts.begin(), _contacts.end(), compare);

	for_each(_contacts.begin(), _contacts.end(), [&](person *p)
	{
		if (p->has_telephone_p())
			os << *p;
	}

	);
}

// Returns the vector with person objects
std::vector<person*> contacts::contacts_list()
{
	return _contacts;
}