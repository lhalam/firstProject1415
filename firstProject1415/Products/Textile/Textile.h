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
	virtual ~Textile(){}

	friend istream& operator>>(istream& stream, Textile& obj);
	friend ostream& operator<<(ostream& stream, Textile& obj);

	string getMaterial() const { return material; }

	void setMaterial(string material) { this->material = material; }

	char getCategory() const { return category; }

	void setCategory(char category) { this->category = category; }

	string getBrand() const { return brand; }

	void setBrand(string brand) { this->brand = brand; }

	unsigned getCollectionYear() const { return collectionYear; }

	void setCollectionYear(unsigned collectionYear) { this->collectionYear = collectionYear; }

	// leading input/output from the console.
	virtual void input();
	virtual void output();
};
