#pragma once
#include <string>

#ifndef DLL_IMPORT
#define DLL __declspec(dllexport)
#else
#define DLL __declspec(dllimport)
#endif

using std::ostream;
using std::string;

//Type of the Message
enum MsgType
{
	INPUT_MSG,
	CONTEXT_MSG,
	LOG_MSG,
	ALERT_MSG
};

//Possible message colors
enum Color
{
	BLUE = 9,
	YELLOW = 6,
	WHITE = 7,
	RED = 4
};

class Message
{
private:
	string msg;
	MsgType type;

public:
	DLL Message();
	DLL Message(string _msg, MsgType _type = LOG_MSG);

	DLL string getMsg() const;

	friend DLL ostream& operator<<(ostream& stream, Message _msg);
};

//Possible Result IDs
enum ResultId
{
	EXIT,
	SUCCESSFUL,
	TOTAL_ERROR,
	NOT_SUCCESSFUL,
	ACCESS_ERROR
};

class Result : public Message
{
private:
	ResultId id;

public:
	DLL Result();
	DLL Result(ResultId _id);
	DLL Result(string _msg, ResultId _id);
	
	DLL ResultId getId() const;

	friend DLL ostream& operator<<(ostream& stream, const Result&);
};
