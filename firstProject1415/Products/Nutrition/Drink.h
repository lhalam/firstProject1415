#pragma once
#include "Nutrition.h"

class Drink : public Nutrition
{
protected:
	double volume;
public:
	Drink();
	
	friend istream& operator>>(istream& stream, Drink& obj);
	friend ostream& operator<<(ostream& stream, const Drink& obj);

	//intput\output methods for command prompt 
	//in order to create new\modify existing product
	virtual void Input();
	virtual void Output() const;
};