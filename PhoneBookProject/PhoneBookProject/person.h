#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

#include "stdafx.h"

// Additional comments are written in person.cpp

// it's better not to use namespace std in header files(use std:: instead)
//using namespace std;

class person 
{
protected:
	// A std::string type variable to store the person's name
	std::string _name;

	// A std::string type variable to store the person's surname
	std::string _surname;

public:

	// Constructors
	person();
	person(std::string n, std::string s); 

	// Set
	void set_name(std::string n);
	void set_surname(std::string s); 

	// Get
	const std::string name() const;
	const std::string surname() const;

	// Virtual boolean functions for the children classes
	// which will return an appropriate value based on
	// the type of class
	virtual bool has_telephone_p();
	virtual bool has_email_p();

	// Output functions
	virtual void display() const;
	void own_display() const;

};

