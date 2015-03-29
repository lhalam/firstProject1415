/*
UI v0.021
24.03.2015
Changes:
	-Added comands 'log in' 'log out' 'register' without proper executors
@Yaroslav Mykoliv
*/
#include <iostream>
#include "UI.h"

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

		bool foundCommand = false;
		for (int i = 0; i < numOfCommands; i++)
		{
			if (commands[i].getName() == userCommand)
			{
				foundCommand = true;
				Error executionResult = commands[i].execute();
				
				/* Error handling */
				switch (executionResult.getId())
				{
				case TOTAL_ERROR:
					cout << executionResult;
				case EXIT:
					cout << Message("Exiting...", LOG_MSG);
					exit(0);
					break;
				case SUCCESSFUL:
					cout << Message(executionResult.getMsg(), LOG_MSG);
					break;
				case NOT_SUCCESSFUL:
				case ACCESS_ERROR:
					cout << executionResult;
					break;
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