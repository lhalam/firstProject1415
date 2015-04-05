# pragma once
# include "../Product.h"

// abstract class Textile.
class Textile : public Product
{
protected:
	string material;
	char category; // male - 'm'; female - 'f'; baby - 'b'.
	string brand;
	unsigned collection_year;
	Textile();
public:
	virtual ~Textile(){}

	friend istream& operator>>(istream& stream, Textile& obj);
	friend ostream& operator<<(ostream& stream, Textile& obj);

	string getMaterial() const { return material; }
	void setMaterial(string m) { this->material = m; }
	char getCategory() const { return category; }
	void setCategory(char c) { this->category = c; }
	string getBrand() const { return brand; }
	void setBrand(string b) { this->brand = b; }
	unsigned getCollectionYear() const { return collection_year; }
	void setCollectionYear(unsigned c_y) { this->collection_year = c_y; }
	// leading in/out put from the console.
	virtual void input();
	virtual void output();
};