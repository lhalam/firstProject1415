#pragma once
#include <string>
#include <iostream>
#include "../List/List.h"
#include <utility>

#ifndef DLL_IMPORT
#define DLL __declspec(dllexport)
#else
#define DLL __declspec(dllimport)
#endif

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
	virtual DLL ~Product();

	DLL string getName() const { return name; }
	DLL void setName(string name) { this->name = name; }

	DLL string getManufacturer() const { return manufacturer; }
	DLL void setManufacturer(string manufacturer) { this->manufacturer = manufacturer; }

	DLL double getPrice() const { return price; }
	DLL void setPrice(double price) { this->price = price; }

	DLL unsigned getId() const { return id; }
	DLL void setId(unsigned id)	{ this->id = id; }

	//intput method for command prompt 
	//in order to create new\modify existing product
	virtual DLL void input();

	//output method for command prompt 
	//in order to create new\modify existing product
	virtual DLL void output() const;

	//comparing products by id using its value only
	DLL bool operator==(const Product&) const;
	DLL bool operator!=(const Product&) const;

	//overloaded operators for file\console reading\output
	friend DLL istream& operator>>(istream& stream, Product& obj);
	friend DLL ostream& operator<<(ostream& stream, const Product& obj);

	//returns list of pairs(first - name of field, second - its value)
	virtual DLL  List<pair<string, string>> metadata();

	//fills all the fields in class (values taken from given string)
	virtual DLL void fill(string);
};