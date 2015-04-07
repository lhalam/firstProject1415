#include "CommandHandlers.h"
#include "../DataManager/DataManager.h"
#include "Globals.h"
/*Command executors*/
Result help()
{
	for (int i = 0; i < numOfCommands; i++)
	{
		cout << Message("[" + commands[i].getName() + "] - " + commands[i].getDescription(), LOG_MSG);
	}
	return Result();
}
Result exit()
{
	return Result(EXIT);
}
Result logIn()
{
	using std::cin;

	cout << Message("Name", CONTEXT_MSG);
	string name;
	getline(cin, name, '\n');
	cout << Message("Password", CONTEXT_MSG);
	string password;
	getline(cin, password, '\n');

	/* Checking the database */
	bool correct = true;

	if (correct)
	{
		/* Writing user data into global variable 'User'*/
		return Result("Authentication successful\nWelcome, " + name + "!", SUCCESSFUL);
	}
	else
	{
		return Result("Authentication failed\nPlease, check your name, password and try again", NOT_SUCCESSFUL);
	}
}
Result logOut()
{
	/*Deletes data of global variable User*/
	return Result("You logged out successfully", SUCCESSFUL);
}
Result createUser()
{
	using std::cin;
	User newUser;
	cin >> newUser;
	/* Writing to the database */
	/* Writing user data into global variable 'User'*/

	return Result("Your account was successfully created\nWelcome, ", SUCCESSFUL);
}
Result changeRole()
{
	return Result();
}

Result showUsers()
{
	DataManager manager;
	List<User*> list = (manager.readAllUsers());
	List<User*>::iterator iter = list.begin();
	while(iter != list.end())
	{
		int temp = 0;
		std::cout << (*iter);
		temp ++;
		iter ++;
		if((temp % 5) == 0)
		{
			cout << Message("Press Enter to continue... ", LOG_MSG);
			cin.get();
		}
	}
	return Result();
}

Result showCart()
{
	List<Product*>::iterator end = cart.end();
	for (List<Product*>::iterator iterator = cart.begin(); iterator != end; iterator++)
	{
		cout << *iterator;
	}
	cout << *cart.end();
	return Result("Listing completed.", SUCCESSFUL);
}
