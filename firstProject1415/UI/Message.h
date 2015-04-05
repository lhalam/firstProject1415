#pragma once
#include <string>

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
	Message();
	Message(string _msg, MsgType _type = LOG_MSG);

	string getMsg() const;

	friend ostream& operator<<(ostream& stream, Message _msg);
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
	Result();
	Result(ResultId _id);
	Result(string _msg, ResultId _id);
	
	ResultId getId() const;

	friend ostream& operator<<(ostream& stream, const Result&);
};