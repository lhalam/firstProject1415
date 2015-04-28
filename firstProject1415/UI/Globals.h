#pragma once
#include "../User/User.h"
#include "../List/List.h"
#include "../Products/Product.h"

/* Declarations of all global variables (all extern) */
extern User currentUser; // User that is using our program
extern List<Product*> cart; // Current session's shopping cart

/* Declarations of all global functions */
extern void toLowercase(string& line);

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
		}
		else if (cin.get() != '\n')
		{
			while (cin.get() != '\n')
			{
			}
			cout << warningMessage;
			cin >> obj;
		}
		else return;
	}
}
