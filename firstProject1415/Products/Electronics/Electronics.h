# pragma once
# include "../Product.h"

//abstact class
class Electronics : public Product
{
protected:
    string category;
	double weight;
	string model; 
	Electronics();
	
public:
	//intput/output methods for user to input/output date
	virtual void input();
	virtual void output() const;

	friend istream& operator>>(istream&, Electronics&);
	friend ostream& operator<<(ostream&, const Electronics&);

	string getCategory() const { return category; }

	void setCategory(string category) { this->category = category; }

	double getWeight() const { return weight; }

	void setWeight(double weight) { this->weight = weight; }

	string getModel() const { return model; }

	void setModel(string model) { this->model = model; }

	virtual  List<pair<string, string>> metadata();

	virtual void fill(string);

	~Electronics(){}
};
