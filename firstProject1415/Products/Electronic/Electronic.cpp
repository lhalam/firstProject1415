#include"Electronic.h"

	Electronic::Electronic(): Product(), category("No category"), weight(0.0), model("No model") { }

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
		cout << Message("Category: " + category, INPUT_MSG);
		cout << Message("Weight: " + to_string(weight), INPUT_MSG);
		cout << Message("Model: " + model, INPUT_MSG);
	}
    
    istream& operator>>(istream& stream, Electronic& obj)
    {
        getline(stream, obj.category);
        stream >> obj.weight;
        stream.get();
        getline(stream, obj.model);
        return stream;
    }
    
    ostream& operator<<(ostream& stream, const Electronic& obj)
    {
        stream << "Category: " << obj.category << endl;
		stream << "Weight: " << obj.weight << endl;
		stream << "Model: " << obj.model << endl;
        return stream;
    }


