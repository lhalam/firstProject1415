#include"Electronic.h"
#include "..\..\UI\Message.h"

Electronic::Electronic():
	Product(),
	category("No category"),
	weight(0.0),
	model("No model")
{
}

void Electronic::input()
{
	Product::input();
	string temp;

	cout << Message("Input category: ", CONTEXT_MSG);
	getline(cin, temp);
	if(ifValidString(temp))
	{
		this->category = temp;
	}
	temp.clear();

	cout << Message("Input weight: ", CONTEXT_MSG);
	getline(cin, temp);
	if(ifValidString(temp))
	{
		this->weight = stod(temp);
	}
	temp.clear();

	cout << Message("Input model: ", CONTEXT_MSG);
	getline(cin, temp);
	if(ifValidString(temp))
	{
		this->model = temp;
	}
	temp.clear();
}

void Electronic::output() const
{
	Product::output();
	cout << Message("Category: " + category, CONTEXT_MSG);
	cout << Message("Weight: " + to_string(weight), CONTEXT_MSG);
	cout << Message("Model: " + model, CONTEXT_MSG);
}

istream& operator>>(istream& stream, Electronic& obj)
{
	stream >> (Product&)obj;
	getline(stream, obj.category);
	stream.get();
	stream >> obj.weight;
	getline(stream, obj.model);
	stream.get();
	return stream;
}

ostream& operator<<(ostream& stream, const Electronic& obj)
{
	stream << (Product&)obj
		<< obj.category << endl
		<< obj.weight << endl
		<< obj.model << endl;
	return stream;
}


