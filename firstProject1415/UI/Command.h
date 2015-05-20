#pragma once
#include <string>
#include "Message.h"

using std::string;

/* Access level specificators */
enum Access
{
	GUEST = 1, //001
	USER = 2,  //010
	ADMIN = 4  //100
};

/*Class Command, used to bind a string name to a function-executor*/
class Command
{
private:
	string name;
	Result (*executor)();
	string description;
	Access access;

public:
	Command() :
		name(""),
		executor(0),
		description(""),
		access(GUEST)
	{
	}

	Command(string _name, Result(*_executor)(), string _description = "", Access _access = GUEST) :
		name(_name),
		executor(_executor),
		description(_description),
		access(_access)
	{
	}

	string getName() const
	{
		return name;
	}

	string getDescription() const
	{
		return description;
	}

	Access getAccessLevel() const
	{
		return access;
	}

	DLL Result execute();
};

/*Array of all Command objects available*/
DLL extern Command commands[];

/*Number of available commands*/
DLL extern const int numOfCommands;
