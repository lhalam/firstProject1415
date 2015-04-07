#pragma once
#include "Nutrition.h"

class Food : public Nutrition
{
private:
	bool GMO_content; // '1' - with GMO, '0' - without GMO
public:
	Food();

	friend istream& operator>>(istream& stream, Food& obj);
	friend ostream& operator<<(ostream& stream, const Food& obj);

	//intput\output methods for command prompt 
	//in order to create new\modify existing product
	void input();
	void output() const;

	void setGMOContent(bool GMO_content_) { this->GMO_content = GMO_content_; }
	bool getGMOContent() const { return GMO_content; }
};