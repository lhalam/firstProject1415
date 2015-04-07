#pragma once
#include "Nutrition.h"

class Food : public Nutrition
{
private:
	bool GMO_content; // '+' - with GMOs, '-' - without GMOs
public:
	Food();

	friend istream& operator>>(istream& stream, Food& obj);
	friend ostream& operator<<(ostream& stream, const Food& obj);

	//intput\output methods for command prompt 
	//in order to create new\modify existing product
	virtual void input();
	virtual void output() const;

	void setGMOContent(bool GMO_content_) { this->GMO_content = GMO_content_; }
	bool getGMOContent() { return this->GMO_content; }
};