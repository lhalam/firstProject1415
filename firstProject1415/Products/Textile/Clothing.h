# pragma once
#include "Textile.h"

class Clothing : public Textile
{
private:
	char size;
	char season; // summer - 's'; winter - 'w'; autumn&spring - 'a'.
public:
	Clothing();

	friend istream& operator>>(istream& stream, Clothing& obj);
	friend ostream& operator<<(ostream& stream, Clothing& obj);

	char getSize() const { return this->size; }
	void setSize(char s) { this->size = s; }
	char getSeason() const { return this->season; }
	void setSeason(char s) { this->season = s; }

	virtual void input();
	virtual void output();

	~Clothing(){}
};