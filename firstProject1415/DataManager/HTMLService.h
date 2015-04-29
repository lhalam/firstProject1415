#pragma once 
#include "../User/Date.h"

class HTMLService
{
public:
	//Saves a purchase history of each user
	void write(int id, const Date& start, const Date& end);
};