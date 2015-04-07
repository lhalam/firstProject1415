#pragma once
#include "../Product.h"

class ChemicalProduct : public Product
{
protected:
	string manufacture_date;
	double volume;
	ChemicalProduct();
public:

	void setManufactureDate(string m_d)
	{
		this->manufacture_date = m_d;
	}
	string getManufactureDate() const
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

	//intput\output methods for command prompt 
	//in order to create new\modify existing product
	virtual void input();
	virtual void output() const;

	virtual ~ChemicalProduct(){}
};