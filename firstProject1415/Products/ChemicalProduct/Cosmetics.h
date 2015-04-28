#pragma once
#include "ChemicalProduct.h"

class Cosmetics : public ChemicalProduct
{
private:
	char part_of_body; // for face - 'f'; for hands - 'h'; for body - 'b'.
public:
	Cosmetics();

	friend istream& operator>>(istream& stream, Cosmetics& obj);
	friend ostream& operator<<(ostream& stream, const Cosmetics& obj);

	~Cosmetics() {}

	//intput\output methods for command prompt 
	//in order to create new\modify existing product
	void input();
	void output() const;

	void setPartOfBody(char part_of_body_) { this->part_of_body = part_of_body_; }
	char getPartOfBody() const { return part_of_body; }
};

