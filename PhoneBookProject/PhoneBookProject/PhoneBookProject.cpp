// PhoneBookProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "person_with_telephone_and_email.h"
#include "contacts.h"

// A input stream function to read what the user inputs
// and takes a pointer to a referenced person object
std::istream & read_person(std::istream &in, person * &p)
{
	// A std::string variable to store "<person" from the input
	std::string str1;

	// A char variable to store "S" from the input
	char str2;

	// A char variable to store "N" from the input
	char str3;

	// std::string variables to store name and surname respectively
	// from the input
	std::string n, s;

	// A std::string variable to store the e-mail address from the input.
	// Initialised as null character if user decides
	// to create a person without e-mail address
	std::string e = "\0";

	// A std::string variable to store the telephone number from the input.
	// Initialised as null character if user decides to
	// create a person without telephone number.
	std::string t = "\0";

	// A std::string input to store values entered by user
	// after name
	std::string inp;

	// Storing the compulsory values from the input
	in >> str1 >> str2 >> s >> str3 >> n;

	// Loop to allow the user to enter
	// optional values
	while (1)
	{
		in >> inp;

		// If the user inputs this character,
		// then he/she is done with the input
		if (inp == ">")
		{
			break;
		}
		// If it's this character, then the user
		// wants to enter a telephone number
		else if (inp == "T")
		{
			in >> t;

		}
		// If it's this character, then the user
		// wants to enter an e-mail address
		else if (inp == "E")
		{
			in >> e;
		}

	}

	// If the telephone std::string has a value and
	// none for e-mail, then it's a person with telephone
	if (t != "\0" && e == "\0")
	{
		p = new person_with_telephone(n, s, t);
		
	}
	// If the e-mail std::string has a value and none for telephone,
	// then it's a person with e-mail
	else if (t == "\0" && e != "\0")
	{
		p = new person_with_email(n, s, e);
	}
	// If both have values, then it's a person
	// with a telephone number AND an e-mail address
	else if (t != "\0" && e != "\0")
	{
		p = new person_with_telephone_and_email(n, s, t, e);
	}
	// If all are null, then it's a generic person
	else
	{
		p = new person(n, s);
	}

	return in;

}

int main()
{
	// Declaring a contacts object
	contacts c;

	// Declaring objects of various classes
	// and adding them to the contacts vector
	// as a reference
	person p1("Kanaga", "Solaikannan");
	c.add(&p1);

	person_with_telephone t("Kanaga", "Solaikannan", "+44.7751.582.472");
	c.add(&t);

	person_with_email e("Adam", "Smith", "adam@hotmail.com");
	c.add(&e);

	person p2("John", "John");
	c.add(&p2);

	person_with_telephone_and_email pte("Nikolay", "Vaklinov", "+44.7759.278.912", "niko@gmail.com");
	c.add(&pte);

	std::cout << *c.find("Kanaga");	

	std::cout << "\n";

	c.in_order(std::cout);

	std::cout << "\n";

	c.with_telephone(std::cout);

	std::cout << "\n";	

	person *pp = 0;
	
	// It stays in loop until the person
	// is still in input and pp is a valid
	// pointer to a class object
	while (read_person(std::cin, pp) && pp)
	{
		std::cout << *pp;
	}


	system("pause");

	return 0;

}

