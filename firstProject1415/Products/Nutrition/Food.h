#pragma once
#include "Nutrition.h"

class Food : public Nutrition
{
private:
	bool GMOContent; // '1' - with GMO, '0' - without GMO
public:
	Food();

	friend istream& operator>>(istream& stream, Food& obj);
	friend ostream& operator<<(ostream& stream, const Food& obj);

	//intput\output methods for command prompt 
	//in order to create new\modify existing product
	void input();
	void output() const;

	void setGMOContent(bool GMO_content_) { this->GMOContent = GMO_content_; }
	bool getGMOContent() const { return GMOContent; }

	virtual  List<pair<string, string>> metadata()
	{
		List<pair<string, string>> result = Nutrition::metadata();
		result.pushBack(make_pair("GMOContent", to_string(GMOContent)));
		return result;
	}
};