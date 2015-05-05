#pragma once
#include "UserService.h"
#include "ProductService.h"
#include "HTMLService.h"
#include "XMLService.h"
#include "../User/User.h"
#include "../Products/Product.h"
#include "../List/List.h"
#include <functional>
#include <map>

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

	//Returnes a user with a given login and password
	//Returnes nullptr if there is no such user
	User *getUserByLogin(string login, string password);

	//Returnes a user with a diven id
	//Returns nullptr if there is no such user
	User* getUserById(int id);

	//Removes a user with a given id
	void removeUserById(int id);

	//Removes all users that match a predicate
	void removeUsers(function<bool(const User&)> predicate);
	
	//Saves product info into a file
	void saveProduct(const Product& prod);
	
	//Saves all products info into a file
	void saveAllProducts(List<Product*> list);

	//Saves a purchase history of each user in HTML 
	void writeInHTML(int id, const Date& start, const Date& end) const;

	//Returns a list of all products in XML
	List<Product*> readFromXML();

	//Returns a list of all saved products
	List<Product*> readAllProducts();

	//Returns a list of products that match a predicate
	List<Product*> readProducts(function<bool(const Product&)> predicate);

	//Returns a list of each user`s purchases
	List<pair<Product*, int>> getAllFromUserStory(int id);
	
	//Returns quantity of the product with a given id
	int getQuantity(int id);
	
	//Changes quantity of the product with a given id
	//Sets new quantity
	void setQuantity(int id, int newQuantity);
	
	//Changes quantity of the product with a given id
	//Adds to the current quantity
	void changeQuantity(int id, int add_quantity);

	//Returns a product with a given id
	//Returns nullptr is there is no such product
	Product* getProductById(int id);

	//Saves purchases of current user
	void saveToUserHistory(const Product& prod, unsigned quantity);

	//Removes a product with a given id
	void removeProductById(int id);

	//Removes all products that match a predicate
	void removeProducts(function<bool(const Product&)> predicate);

	//Saves information about purchases into a file
	void saveStatistics(unsigned quantity, int id);

	//Returns a list of purchased items and their quantity
	map<Product*, int> readStatistics();

	// Saves all products in XML
	void exportXML();
};
