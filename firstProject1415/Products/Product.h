#pragma once
#include <string>
#include <iostream>
#include "../List/List.h"
#include <utility>

using namespace std;

class Product
{
protected:
	string name;
	string manufacturer;
	double price;
	unsigned id;
	Product();
public:
	virtual ~Product();

	string getName() const { return name; }
	void setName(string name) { this->name = name; }

	string getManufacturer() const { return manufacturer; }
	void setManufacturer(string manufacturer) { this->manufacturer = manufacturer; }

	double getPrice() const { return price; }
	void setPrice(double price) { this->price = price; }

	unsigned getId() const { return id; }
	void setId(unsigned id)	{ this->id = id; }

	//intput method for command prompt 
	//in order to create new\modify existing product
	virtual void input();

	//output method for command prompt 
	//in order to create new\modify existing product
	virtual void output() const;

	//comparing products by id using its value only
	bool operator==(const Product&) const;
	bool operator!=(const Product&) const;

	//overloaded operators for file\console reading\output
	friend istream& operator>>(istream& stream, Product& obj);
	friend ostream& operator<<(ostream& stream, const Product& obj);

	virtual  List<pair<string, string>> metadata()
	{
		List<pair<string, string>> result;
		result.pushBack(make_pair("name", name));
		result.pushBack(make_pair("manufacturer", manufacturer));
		result.pushBack(make_pair("price", to_string(price)));
		result.pushBack(make_pair("id", to_string(id)));
		return result;
	}
};