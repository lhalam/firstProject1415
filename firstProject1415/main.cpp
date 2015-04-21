#include <iostream>
#include "UI/UI.h"

using std::cout;
using std::cerr;
using std::cin;
using std::endl;

int main()
{
	cout << "Welcome to our shop!" << endl;
	cout << "Type 'help' for list of available commands" << endl;
	cout << "________________________________________________________________________________" << endl;

	while (1)
	{
		cout << Message("Execute", CONTEXT_MSG);
		string userCommand;
		getline(cin, userCommand, '\n');

		if (userCommand == "exit")
		{
			break;
		}

		bool foundCommand = false;
		for (int i = 0; i < numOfCommands; i++)
		{
			if (commands[i].getName() == userCommand)
			{
				foundCommand = true;
				Result executionResult = commands[i].execute();
				if (executionResult.getId() != SUCCESSFUL)
				{
					cerr << executionResult;
					cin.get();
				}
			}
		}
		if (foundCommand == false)
		{
			cout << Message("Unknown command, please try again. You can type 'help' to see the list of available commands.", ALERT_MSG);
		}
	}

	return 0;
}