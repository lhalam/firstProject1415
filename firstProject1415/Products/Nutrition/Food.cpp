#include "Food.h"
#include "../../UI/UI.h"
#include <exception>

Food::Food():
	Nutrition(),
	GMOContent(0)
{
}

istream& operator>>(istream& stream, Food& obj)
{
	stream >> (Nutrition&)obj
		   >> obj.GMOContent;
	stream.get();
	return stream;
}

ostream& operator<<(ostream& stream, const Food& obj)
{
	stream << (Nutrition&)obj
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
	cout << Message(string("GMO: ") + (this->GMOContent ? "yes" : "no"), LOG_MSG);
}

List<pair<string, string>> Food::metadata()
{
	List<pair<string, string>> result = Nutrition::metadata();
	result.pushBack(make_pair("GMOContent", to_string(GMOContent)));
	return result;
}

void Food::fill(string source)
{
	this->Nutrition::fill(source);
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
		if (k == 7)
		{
			if (field == "0")
				GMOContent = false;
			else if (field == "1")
				GMOContent = true;
			else
				throw invalid_argument("GMO content has bool type! Just 0 and 1 are available!");
		}
		field.clear();
		k++;
		posStart = posEnd + 1;
		posEnd = source.find_first_of(',', posStart);
		if (posEnd == string::npos) break;
	}
}