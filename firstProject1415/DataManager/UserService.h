#pragma once
#include "../User/User.h"
#include "../List/List.h"

namespace Team4
{
	//Represents a service for reading and writing user info from/into a file
	class UserService
	{
		static bool alwaysTrue(const User& prod) { return true; }

	public:
		void save(const User& user); //Saves user info into a file
		List<User> readAll(); //Calls read(alwaysTrue)
		List<User> read(bool (*predicate)(const User& user)); //Returns a list of users that match a predicate
	};
}