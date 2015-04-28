#include "Globals.h"

/* Definition of all global variables */
User currentUser = User();
List<Product*> cart = List<Product*>();

/* Definition of all global functions */
void toLowercase(string& line)
{
	for(int i = 0; i < line.length(); i++)
	{
		line[i] = tolower(line[i]);
	}
}

