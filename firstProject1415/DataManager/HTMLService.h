#pragma once 
#include "../User/Date.h"
#include "../List/List.h"

#include <string>
using namespace std;

class HTMLService
{
	//Formats every field name in the list
	void format(List<pair<string, string>>& list);

public:
	//Saves a purchase history of each user
	void write(int id, const Date& start, const Date& end);
};