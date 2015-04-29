#pragma once
#include "../Product.h"

class ChemicalProduct : public Product
{
protected:
	string manufactureDate;
	double volume;
	ChemicalProduct();
public:

	void setManufactureDate(string md)
	{
		this->manufactureDate = md;
	}
	string getManufactureDate() const
	{ 
		return manufactureDate;
	}
	void setVolume(double vol)
	{
		this->volume = vol;
	}
	double getVolume() const
	{
		return volume;
	}

	friend istream& operator>>(istream& stream, ChemicalProduct& obj);
	friend ostream& operator<<(ostream& stream, const ChemicalProduct& obj);

	//intput\output methods for command prompt 
	//in order to create new\modify existing product
	virtual void input();
	virtual void output() const;

	virtual  List<pair<string, string>> metadata()
	{
		List<pair<string, string>> result = Product::metadata();
		result.pushBack(make_pair("manufactureDate", manufactureDate));
		result.pushBack(make_pair("volume", to_string(volume)));
		return result;
	}

	virtual ~ChemicalProduct(){}
};