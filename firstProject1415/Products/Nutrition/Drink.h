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
	void input();
	void output() const;

	void setVolume(double volume_) { this->volume = volume_; }
	double getVolume() const { return volume; }

	virtual  List<pair<string, string>> metadata()
	{
		List<pair<string, string>> result = Nutrition::metadata();
		result.pushBack(make_pair("volume", to_string(volume)));
		return result;
	}
};