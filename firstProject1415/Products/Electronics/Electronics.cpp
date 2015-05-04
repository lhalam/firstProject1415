#include"Electronics.h"
#include "..\..\UI\Message.h"
#include "..\..\UI\Globals.h"

Electronics::Electronics():
	Product(),
	category("No category"),
	weight(0.0),
	model("No model")
{
}

void Electronics::input()
{
	Product::input();
	
	cout << Message("Input category: ", CONTEXT_MSG);
	getline(cin, category);
	while(!ifValidString(category))
	{
		cout << Message("Bad input. Try Again:", ALERT_MSG);
		getline(cin, category);
	}

	cout << Message("Input weight: ", CONTEXT_MSG);
	forInput(weight, Message("Bad input. Try Again:", ALERT_MSG));

	cout << Message("Input model: ", CONTEXT_MSG);
	getline(cin, model);
	while (!ifValidString(model))
	{
		cout << Message("Bad input. Try Again:", ALERT_MSG);
		getline(cin, model);
	}
}

void Electronics::output() const
{
	Product::output();
	cout << Message("Category: " + category, LOG_MSG);
	cout << Message("Weight: " + to_string(weight), LOG_MSG);
	cout << Message("Model: " + model, LOG_MSG);
}

istream& operator>>(istream& stream, Electronics& obj)
{
	stream >> (Product&)obj;
	getline(stream, obj.category);
	stream >> obj.weight;
	stream.get();
	getline(stream, obj.model);
	return stream;
}

ostream& operator<<(ostream& stream, const Electronics& obj)
{
	stream << (Product&)obj
		<< obj.category << endl
		<< obj.weight << endl
		<< obj.model << endl;
	return stream;
}

List<pair<string, string>> Electronics::metadata()
{
	List<pair<string, string>> result = Product::metadata();
	result.pushBack(make_pair("category", category));
	result.pushBack(make_pair("weight", to_string(weight)));
	result.pushBack(make_pair("model", model));
	return result;
}

void Electronics::fill(string source)
{
	this->Product::fill(source);
	int posStart = 0;
	int posEnd = source.find_first_of(',');
	string field = "";
	int i = 0, k = 0;
	while (source[i] != '\n')
	{
		for (i = posStart; i < posEnd; i++)
		{
			field += source[i];
		}
		switch (k)
		{
		case 4: category = field;
			break;
		case 5: weight = stod(field);
			break;
		case 6: model = field;
			break;
		}
		field.clear();
		k++;
		posStart = posEnd + 1;
		posEnd = source.find_first_of(',', posStart);
		if (posEnd == string::npos) break;
	}
}


