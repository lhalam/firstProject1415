#pragma once
#include "UserService.h"
#include "ProductService.h"
#include "../User/User.h"
#include "../Products/Product.h"
#include "../List/List.h"
#include <functional>

//Represents a simle interface for user and product services
class DataManager
{
public:
	//Saves user info into a file
	void saveUser(const User& user);

	//Returns a list of all saved users
	List<User*> readAllUsers();

	//Returns a list of users that match a predicate
	List<User*> readUsers(function<bool(const User&)> predicate);
	

	//Saves product info into a file
	void saveProduct(const Product& prod);

	//Returns a list of all saved products
	List<Product*> readAllProducts();

	//Returns a list of products that match a predicate
	List<Product*> readProducts(function<bool(const Product&)> predicate);
};
