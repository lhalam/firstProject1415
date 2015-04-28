#pragma once
#include "../User/User.h"
#include "../Products/Products.h"
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

	//Returns a list of bought (by users id) products
	List<Product*> getAllFromStory(int id) const;

	//Returns a list of users that match a predicate
	List<User*> read(function<bool(const User&)> predicate);

	//Returns a user with a given login and password
	//Returns nulltpr if there is no such user
	User *getByLogin(string login, string password);

	//Returns a user with a given id
	User *getById(int id);

	//Saves each product, bought by user
	void saveToHistory(int id, const Product& prod, unsigned quantity);

	//Removes a user from file ("Users.txt") if the predicate is true
	void removeByPredicate(function<bool(const User&)> predicate);

	//Removes a user with a given id
	void removeById(int id);
};
