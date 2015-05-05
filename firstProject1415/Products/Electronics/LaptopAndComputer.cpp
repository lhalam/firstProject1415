#include "LaptopAndComputer.h"
#include "..\..\UI\Globals.h"
#include "..\..\UI\Message.h"



LaptopAndComputer::LaptopAndComputer(): 
	Electronics(),
	firm(" ")
{
}

istream& operator>>(istream& stream, LaptopAndComputer& obj)
{
	stream >> (Electronics&)obj;
	getline(stream, obj.firm);
	return stream;
}

ostream& operator<<(ostream& stream, const LaptopAndComputer& obj)
{
	stream << (Electronics&)obj
		   << obj.firm << endl;
	return stream;
}


void LaptopAndComputer::input()
{
	Electronics::input();

	cout << Message("Input firm: ", CONTEXT_MSG);
	getline(cin, firm);
	while (!ifValidString(firm))
	{
		cout << Message("Bad input. Try Again:", ALERT_MSG);
		getline(cin, firm);
	}
}

void LaptopAndComputer::output() const
{
	Electronics::output();
	cout << Message("Firm: " + firm, LOG_MSG);
}

List<pair<string, string>> LaptopAndComputer::metadata()
{
	List<pair<string, string>> result = Electronics::metadata();
	result.pushBack(make_pair("firm", firm));
	return result;
}

void LaptopAndComputer::fill(string source)
{
	this->Electronics::fill(source);
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
		if(k == 7)
		{
			firm = field;
		}
		field.clear();
		k++;
		posStart = posEnd + 1;
		posEnd = source.find_first_of(',', posStart);
		if (posEnd == string::npos) break;
	}
}
