#include "Food.h"

Food::Food() :
	Nutrition(),
	GMOContent(0)
{
}

istream& operator>>(istream& stream, Food& obj)
{
	stream >> Nutrition(obj)
		   >> obj.GMOContent;
	return stream;
}

ostream& operator<<(ostream& stream, const Food& obj)
{
	stream << Nutrition(obj) << endl
		<< obj.GMOContent << endl;
	return stream;
}

void Food::input()
{
	Nutrition::input();
	string temp;

	cout << Message("Input GMO content: ", CONTEXT_MSG);
	getline(cin, temp);
	if (ifValidString(temp))
	{
		if (stoi(temp) == 0)
			this->GMOContent = false;
		else if (stoi(temp) == 1)
			this->GMOContent = true;
	}
	temp.clear();
}

void Food::output() const
{
	Nutrition::output();
	cout << Message("GMO: " + this->GMOContent, INPUT_MSG);
}