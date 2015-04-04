#pragma once
#include "../Product.h"

//abstract class Nutrition
class Nutrition : public Product
{
protected:
	string manufacture_date;
	string expiration_date;
	string ingredients;
	Nutrition();
public:
	virtual ~Nutrition() {}
	
	friend istream& operator>>(istream& stream, Nutrition& obj);
	friend ostream& operator<<(ostream& stream, const Nutrition& obj);

	//function returns all the info/details about Product in string form
	virtual string getDetails();

	string getManufactureDate() const { return manufacture_date; }
	void setManufactureDate(string m_d) { this->manufacture_date = m_d; }
	string getExpirationDate() const { return expiration_date; }
	void setExpirationDate(string e_d) { this->expiration_date = e_d; }
	string getIngredients() const { return ingredients; }
	void setIngredients(string ing) { this->ingredients = ing; }
};