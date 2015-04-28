#pragma once
#include "../Product.h"

//abstract class Nutrition
class Nutrition : public Product
{
protected:
	string manufactureDate;
	string expirationDate;
	string ingredients;
	Nutrition();
public:
	virtual ~Nutrition();
	
	friend istream& operator>>(istream& stream, Nutrition& obj);
	friend ostream& operator<<(ostream& stream, const Nutrition& obj);

	//intput\output methods for command prompt 
	//in order to create new\modify existing product
	virtual void input();
	virtual void output() const;

	string getManufactureDate() const { return manufactureDate; }
	void setManufactureDate(string m_d) { this->manufactureDate = m_d; }

	string getExpirationDate() const { return expirationDate; }
	void setExpirationDate(string e_d) { this->expirationDate = e_d; }

	string getIngredients() const { return ingredients; }
	void setIngredients(string ing) { this->ingredients = ing; }

	virtual  List<pair<string, string>> metadata()
	{
		List<pair<string, string>> result = Product::metadata();
		result.pushBack(make_pair("manufactureDate", manufactureDate));
		result.pushBack(make_pair("expirationDate", expirationDate));
		result.pushBack(make_pair("ingredients", ingredients));
		return result;
	}
};