#include <iostream>
#include "../User/User.h"
using std::cout;

/*Command executors*/
Error help()
{
	for (int i = 0; i < numOfCommands; i++)
	{
		cout << Message("[" + commands[i].getName() + "] - " + commands[i].getDescription(), LOG_MSG);
	}
	return Error();
}
Error exit()
{
	return Error(EXIT);
}
Error logIn()
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
		return Error("Authentication successful\nWelcome, " + name + "!", SUCCESSFUL);
	}
	else
	{
		return Error("Authentication failed\nPlease, check your name, password and try again", NOT_SUCCESSFUL);
	}
}
Error logOut()
{
	/*Deletes data of global variable User*/
	return Error("You logged out successfully", SUCCESSFUL);
}
Error createUser()
{
	using std::cin;
	User newUser;
	cin >> newUser;
	/* Writing to the database */
	/* Writing user data into global variable 'User'*/

	return Error("Your account was successfully created\nWelcome, ", SUCCESSFUL);
}
Error changeRole()
{

}

/*Initialization of commands*/
Command commands[] = 
{
	Command("help", help, "provides you with the list of available commands and their description"),
	Command("exit", exit, "exits the program"),
	Command("log in", logIn, "performs user authentication"),
	Command("log out", logOut, "exits user profile"),
	Command("register", createUser, "create your account")
};
const int numOfCommands = sizeof(commands) / sizeof(commands[0]);

	/*void changePassword(string);
	void changeEmail(string);
	void changeRole(string);*/