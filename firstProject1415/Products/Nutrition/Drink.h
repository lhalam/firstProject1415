#pragma once
#include "Nutrition.h"

class Drink : public Nutrition
{
protected:
	double volume;
public:
	DLL Drink();
	
	friend DLL istream& operator>>(istream& stream, Drink& obj);
	friend DLL ostream& operator<<(ostream& stream, const Drink& obj);

	//intput/output methods for command prompt 
	//in order to create new\modify existing product
	void DLL input();
	void DLL output() const;

	void setVolume(double volume_) { this->volume = volume_; }
	double getVolume() const { return volume; }

	//returns list of pairs (first - name of field, second - its value)
	virtual DLL List<pair<string, string>> metadata();

	//fills all the fields in class (values taken from given string)
	virtual DLL void fill(string);
};