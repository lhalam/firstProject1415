#pragma once
#include "../User/User.h"
#include "../List/List.h"
#include "../Products/Products.h"

/* Declarations of all global variables (all extern) */

DLL extern User currentUser; // User that is using our program
DLL extern List<Product*> cart; // Current session's shopping cart

/* Declarations of all global functions */

//a variation of tolowercase function
//for whole string
DLL void toLowercase(string& line);

//predicate for correct command prompt input 
//or skipping entering a field when modifying
DLL bool ifValidString(const string& str);

//Creates and returns a product with a given type
DLL Product* identifyType(string type);

template <typename T>
void forInput(T &obj, const Message& warningMessage)
{
	cin >> obj;

	while (true)
	{
		if (cin.fail())
		{
			cin.clear();
			while (cin.get() != '\n')
			{
			}
			cout << warningMessage;
			cin >> obj;
		} else if (cin.get() != '\n')
		{
			while (cin.get() != '\n')
			{
			}
			cout << warningMessage;
			cin >> obj;
		} else return;
	}
}
