#include "Globals.h"

/* Definition of all global variables */
User currentUser = User();
List<Product*> cart = List<Product*>();

/* Definition of all global functions */
void toLowercase(string& line)
{
	for(unsigned i = 0; i < line.length(); i++)
	{
		line[i] = tolower(line[i]);
	}
}

bool ifValidString(const string& str)
{
	if(str[0] == ' ' || str[0] == '\t'|| str[0] == '\n'|| 
	   str[0] == '\0'|| str[0] == '\a'|| str[0] == '.' || 
	   str[0] == ',' || str[0] == ':' || str[0] == ';' || 
	   str[0] == '`' || str[0] == '&' || str[0] == '@' )
	{
		return false;
	}
	return true;
}

