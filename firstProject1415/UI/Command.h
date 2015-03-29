#pragma once
#include <string>
#include "Message.h"

using std::string;

/*Class Command, used to bind a string name to a function-executor*/
class Command
{
private:
	string name;
	Error (*executor)();
	string description;

public:
	Command() : name(""), executor(0), description("")
	{}
	Command(string _name, Error(*_executor)(), string _description = "") : name(_name), executor(_executor), description(_description)
	{}

	string getName() const
	{
		return name;
	}
	string getDescription() const
	{
		return description;
	}

	Error execute()
	{
		return executor();
	}
};

/*Array of all Command objects available*/
extern Command commands[];

/*Number of available commands*/
extern const int numOfCommands;