#include "CommandHandlers.h"
#include "../User/User.h"
#include "Globals.h"

using std::cout;

/*Command executors*/
Result help()
{
	for (int i = 0; i < numOfCommands; i++)
	{
		if (commands[i].getAccessLevel() & currentUser.getRole())
		{
			cout << Message("[" + commands[i].getName() + "] - " + commands[i].getDescription(), LOG_MSG);
		}
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
	currentUser = User();
	cout << Message("You logged out successfully", LOG_MSG);
	return Result();
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
	return Result();
}