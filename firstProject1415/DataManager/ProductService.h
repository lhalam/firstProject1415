#pragma once
#include "../Products/Product.h"
#include "../List/List.h"
#include "../DataManager/UserService.h"
#include <functional>
#include <map>
using std::function;

//Represents a service for reading and writing product info from/into a file
class ProductService
{
	//Gives to UserService possibility
	//to take a product from file 
	friend class UserService;

	//Reads and returnes the product of the specified type
	Product *getProduct(string type, istream& stream);

	//Saves the product of the specified type
	void saveProduct(const Product& prod, ostream& stream);
public:
	//Saves product info into a file
	void save(const Product& prod);
	
	//Returnes a quantity of the product by given id
	int getQuantity(int id);
	
	//Changes a quantity of the product by given id
	//Sets new quantity
	void setQuantity(int id, int newQuantity);
	
	//Changes a quantity of the product by given id
	//Adds to the current quantity
	void changeQuantity(int id, int add_quantity);

	//Returns a product with a given id
	Product *getById(int id);

	//Removes a product with a given id
	void removeById(int id);

	//Removes a product from file ("Products.txt") if the predicate is true
	void removeByPredicate(function<bool(const Product&)> predicate);

	//Calls read(always true)
	List<Product*> readAll();

	//Returns a list of products that match a predicate
	List<Product*> read(function<bool(const Product&)> predicate);

	//Saves information about purchases into a file
	void saveStatistics(unsigned quantity, int id);

	//Returns a list of purchased items and their quantity
	map<Product*, int> readStatistics();
};
