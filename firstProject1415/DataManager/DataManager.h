#pragma once
#include "UserService.h"
#include "ProductService.h"
#include "../User/User.h"
#include "../Products/Product.h"
#include "../List/List.h"

namespace Team4
{
	//Represents a simle interface for user and product services
	class DataManager
	{
	public:
		void saveUser(const User& user); //Saves user info into a file
		List<User> readAllUsers(); //Returns a list of all saved users 
		List<User> readUsers(bool (*predicate)(const User& user)); //Returns a list of users that match a predicate

		void saveProduct(const Product& prod); //Saves product info into a file
		List<Product&> readAllProducts(); //Returns a list of all saved products
		List<Product&> readProducts(bool (*predicate)(const Product& user)); //Returns a list of products that match a predicate
	};
}