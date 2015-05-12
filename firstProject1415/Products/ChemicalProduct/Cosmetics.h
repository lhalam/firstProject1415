#pragma once
#include "ChemicalProduct.h"

class Cosmetics : public ChemicalProduct
{
private:
	char part_of_body; // face - 'f'; hands - 'h'; body - 'b'.
public:
	DLL Cosmetics();

	friend DLL istream& operator>>(istream& stream, Cosmetics& obj);
	friend DLL ostream& operator<<(ostream& stream, const Cosmetics& obj);

	DLL ~Cosmetics() {}

	//intput\output methods for command prompt 
	//in order to create new\modify existing product
	void DLL input();
	void DLL output() const;

	virtual DLL List<pair<string, string>> metadata();

	void DLL setPartOfBody(char part_of_body_) { this->part_of_body = part_of_body_; }
	char DLL getPartOfBody() const { return part_of_body; }

	virtual DLL void fill(string source);
};

