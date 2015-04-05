#pragma once
#include <string>
#include <iostream>
#include "..\UI\Message.h"

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
	//intput\output methods for command prompt 
	//in order to create new\modify existing product
	virtual void Input();
	virtual void Output() const;

	//overloaded operators for file\console reading\output
	friend istream& operator>>(istream& stream, Product& obj);
	friend ostream& operator<<(ostream& stream, const Product& obj);
};