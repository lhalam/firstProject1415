#pragma once
#include "../Products/Product.h"
#include "../List/List.h"
#include <functional>
using std::function;

//Represents a service for reading and writing product info from/into a file
class ProductService
{
	//Returnes the product of the specified type
	Product *getProduct(string type);
public:
	//Saves product info into a file
	void save(const Product& prod);

	//Returns a product with a given id
	Product *getById(int id);

	//Removes the information about user by it`s ID
	void removeById(int id);

	//Calls read(always true)
	List<Product*> readAll();

	//Returns a list of products that match a predicate
	List<Product*> read(function<bool(const Product&)> predicate);
};
