# pragma once
# include "../Product.h"

//abstact class
class Electronic : public Product
{
protected:
    string category;
	double weight;
	string model; 
	Electronic() { }
	
public:
	//intput/output methods for user to input/output date
	virtual void input() { }
	virtual void output() const { }

	friend istream& operator>>(istream&, Electronic&);
	friend ostream& operator<<(ostream&, const Electronic&);

	string getCategory() const { return category; }
	void setCategory(const string& c) { category = c; }
	double getWeight() const { return weight; }
	void setWeight(double w) { this->weight = w; }
	string getModel() const { return model; }
	void setModel(string m) { model = m; }

	~Electronic(){}
};
