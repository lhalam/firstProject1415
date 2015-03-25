#include <iostream>
#include "Command.h"

using std::cout;

/*Command executors*/
Error help()
{
	/*Special exit command*/
	string msg = "[exit] - exits the program\n";

	for (int i = 0; i < numOfCommands-1; i++)
	{
		msg += "[" + commands[i].getName() + "] - " + commands[i].getDescription() + "\n";
	}
	msg += "[" + commands[numOfCommands - 1].getName() + "] - " + commands[numOfCommands - 1].getDescription();

	cout << Message(msg, LOG_MSG);
	return Error();
}
Error notAJoke()
{
	cout << Message("You are so damn right!!!", LOG_MSG);
	return Error();
}

/*Initialization of commands*/
Command commands[] =
{
	Command("help", help, "provides you with the list of available commands and their description"),
	Command("Slavko lox", notAJoke, "it's not a joke")
};
const int numOfCommands = sizeof(commands) / sizeof(commands[0]);

