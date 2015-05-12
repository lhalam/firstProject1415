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
	virtual DLL void input();
	virtual DLL void output() const;

	friend DLL istream& operator>>(istream&, Electronics&);
	friend DLL ostream& operator<<(ostream&, const Electronics&);

	string getCategory() const { return category; }

	void setCategory(string category) { this->category = category; }

	double getWeight() const { return weight; }

	void setWeight(double weight) { this->weight = weight; }

	string getModel() const { return model; }

	void setModel(string model) { this->model = model; }

	virtual DLL List<pair<string, string>> metadata();

	virtual DLL void fill(string);

	~Electronics() { }
};
