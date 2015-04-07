#pragma once
#include "../User/User.h"
#include "../List/List.h"
#include <functional>
#include <exception>
#include <fstream>
#include <cstdio>

using std::function;

//Represents a service for reading and writing user info from/into a file
class UserService
{
public:
	//Saves user info into a file
	void save(const User& user);

	//Calls read(always true)
	List<User*> readAll();

	//Removes the information about user by it`s ID
	void removeById(int);

	//Returns a list of users that match a predicate
	List<User*> read(function<bool(const User&)> predicate);
};
