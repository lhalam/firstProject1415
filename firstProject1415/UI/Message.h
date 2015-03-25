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

protected:
	string getMsg() const;

public:
	Message();
	Message(string _msg, MsgType _type = LOG_MSG);

	friend ostream& operator<<(ostream& stream, Message _msg);
};



//Possible error IDs
enum ErrorId
{
	SUCCESSFUL,
	TOTAL_ERROR,
	NOT_SUCCESSFUL
};

class Error : public Message
{
private:
	ErrorId id;

public:
	Error();
	Error(string _msg, ErrorId _id);
	
	ErrorId getId() const;

	friend ostream& operator<<(ostream& stream, const Error&);
};