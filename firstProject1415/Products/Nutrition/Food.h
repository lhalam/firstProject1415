#pragma once
#include "Nutrition.h"

class Food : public Nutrition
{
private:
	char GMO_content; // '+' - with GMOs, '-' - without GMOs
public:
	Food();

	friend istream& operator>>(istream& stream, Food& obj);
	friend ostream& operator<<(ostream& stream, const Food& obj);
};