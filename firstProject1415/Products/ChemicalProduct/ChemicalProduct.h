#pragma once
#include "../Product.h"

class ChemicalProduct : public Product
{
protected:
	string manufacture_date;
	double volume;
	ChemicalProduct();
public:

	void setDate(string m_d)
	{
		this->manufacture_date = m_d;
	}
	string getDate() const
	{ 
		return manufacture_date;
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

	virtual ~ChemicalProduct(){}
};