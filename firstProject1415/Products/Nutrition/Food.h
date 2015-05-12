#pragma once
#include "Nutrition.h"

class Food : public Nutrition
{
private:
	bool GMOContent; // '1' - with GMO, '0' - without GMO
public:
	DLL Food();

	friend DLL istream& operator>>(istream& stream, Food& obj);
	friend DLL ostream& operator<<(ostream& stream, const Food& obj);

	//intput\output methods for command prompt 
	//in order to create new\modify existing product
	void DLL input();
	void DLL output() const;

	void setGMOContent(bool GMO_content_) { this->GMOContent = GMO_content_; }
	bool getGMOContent() const { return GMOContent; }

	//returns list of pairs (first - name of field, second - its value)
	virtual DLL List<pair<string, string>> metadata();

	//fills all the fields in class (values taken from given string)
	virtual DLL void fill(string);
};