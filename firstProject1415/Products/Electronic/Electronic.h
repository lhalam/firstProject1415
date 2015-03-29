# pragma once
# include "../Product.h"


class Electronic : public Product
{
protected:
    string category;
	double weight;
	string model;
public:
    Electronic(): category("No category"), weight(0.0), model("No model") { }
    
    friend istream& operator>>(istream& stream, Electronic& obj)
    {
        getline(stream, obj.category);
        stream >> obj.weight;
        stream.get();
        getline(stream, obj.model);
        return stream;
    }
    
    friend ostream& operator<<(ostream& stream, const Electronic& obj)
    {
        stream << obj.category << ' ' << obj.weight << ' '<< obj.model << endl;
        return stream;
    }

	string getCategory() const { return category; }
	void setCategory(const string& c) { category = c; }
	double getWeight() const { return weight; }
	void setWeight(double w) { this->weight = w; }
	string getModel() const { return model; }
	void setModel(string m) { model = m; }

	~Electronic(){}
};