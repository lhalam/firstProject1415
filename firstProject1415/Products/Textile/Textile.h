# pragma once
# include "../Product.h"

// abstract class Textile.
class Textile : public Product
{
protected:
	string material;
	char category; // male - 'm'; female - 'f'; baby - 'b'.
	string brand;
	unsigned collectionYear;
	Textile();
public:
	virtual ~Textile() { }

	friend DLL istream& operator>>(istream& stream, Textile& obj);
	friend DLL ostream& operator<<(ostream& stream, Textile& obj);

	string getMaterial() const { return material; }

	void setMaterial(string material) { this->material = material; }

	char getCategory() const { return category; }

	void setCategory(char category) { this->category = category; }

	string getBrand() const { return brand; }

	void setBrand(string brand) { this->brand = brand; }

	unsigned getCollectionYear() const { return collectionYear; }

	void setCollectionYear(unsigned collectionYear) { this->collectionYear = collectionYear; }

	// leading input/output from the console.
	virtual DLL void input();
	virtual DLL void output();

	virtual DLL List<pair<string, string>> metadata();

	virtual DLL void fill(string source);
};
