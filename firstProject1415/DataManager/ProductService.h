#pragma once
#include "../Products/Product.h"
#include "../List/List.h"

namespace Team4
{
	//Represents a service for reading and writing product info from/into a file
	class ProductService
	{
		static bool alwaysTrue(const Product& prod) { return true; }

	public:
		void save(const Product& prod); //Saves product info into a file
		List<Product&> readAll(); //Calls read(alwaysTrue)
		List<Product&> read(bool (*predicate)(const Product& prod)); //Returns a list of products that match a predicate
	};
}