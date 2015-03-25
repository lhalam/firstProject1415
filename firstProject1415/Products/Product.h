#pragma once
#include <string>
#include <iostream>

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
	virtual ~Product() { }

	string getName() const
	{
		return name;	
	}
	void setName(string name)
	{
		this->name = name;	
	}
	string getManufacturer() const
	{
		return manufacturer;	
	}
	void setManufacturer(string manufacturer)
	{
		this->manufacturer = manufacturer;	
	}
	double getPrice() const
	{
		return price;	
	}
	void setPrice(double price)
	{
		this->price = price;	
	}
	unsigned getId() const
	{
		return id;	
	}
	void setId(unsigned id)
	{
		this->id = id;	
	}

	friend istream& operator>>(istream& stream, Product& obj);
	friend ostream& operator<<(ostream& stream, const Product& obj);
};