#include <iostream>
#include "../User/User.h"
using std::cout;

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
	return Result();
}

/*Initialization of commands*/
Command commands[] = 
{
	Command("help", help, "provides you with the list of available commands and their description", Access(GUEST | USER | ADMIN)),
	Command("exit", exit, "exits the program", Access(GUEST | USER | ADMIN)),
	Command("log in", logIn, "performs user authentication", Access::GUEST),
	Command("log out", logOut, "exits user profile", Access(USER | ADMIN)),
	Command("register", createUser, "create your account", Access::GUEST),
	Command("show all users", showUsers, "show the list of all users", Access::ADMIN)
};
const int numOfCommands = sizeof(commands) / sizeof(commands[0]);

	/*void changePassword(string);
	void changeEmail(string);
	void changeRole(string);*/