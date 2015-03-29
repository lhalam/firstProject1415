#include <iostream>
#include "System.h"
#include "Message.h"

using std::ostream;
using std::cerr;

HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

Message::Message() : msg(""), type(LOG_MSG)
{}
Message::Message(string _msg, MsgType _type) : msg(_msg), type(_type)
{}

string Message::getMsg() const
{
	return msg;
}

ostream& operator<<(ostream& stream, Message _msg)
{
	int color;
	string specialEnd = "\n";
	switch (_msg.type)
	{
	case INPUT_MSG:
		color = WHITE;
		break;
	case CONTEXT_MSG:
		specialEnd = " -> ";
		color = BLUE;
		break;
	case LOG_MSG:
		color = YELLOW;
		break;
	case ALERT_MSG:
		color = RED;
	}

	SetConsoleTextAttribute(hConsole, color);
	stream << _msg.msg << specialEnd;
	SetConsoleTextAttribute(hConsole, WHITE);

	return stream;
}



Error::Error() : Message("", ALERT_MSG), id(SUCCESSFUL)
{}
Error::Error(string _msg, ErrorId _id) : Message(_msg, ALERT_MSG), id(_id)
{}

ErrorId Error::getId() const
{
	return id;
}

ostream& operator<<(ostream& stream, const Error& error)
{
	SetConsoleTextAttribute(hConsole, RED);
	stream << "Alert: id=" << error.id << " -> " << error.getMsg();
	SetConsoleTextAttribute(hConsole, WHITE);
	return stream;
}