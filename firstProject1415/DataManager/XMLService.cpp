#include "XMLService.h"
#include "DataManager.h"
#include "../UI/Globals.h"
#include <fstream>
#include <string>
#include <algorithm>

List<Product*> XMLService::read()
{
	ifstream products("Products.xml");
	if (!products.is_open())
	{
		throw exception("Cannot open file for reading.");
	}

	List<Product*> list;

	string line;
	string type;
	while (!products.eof())
	{
		if (products.get() == '<')
		{
			getline(products, line, '>');
			if (identifyType(line) != nullptr)
			{
				type = line;
				toLowercase(type);
				Product *prod = identifyType(type);
				list.pushBack(prod);
			}
			if (line == "name")
			{
				getline(products, line, '<');
				list.back()->setName(line);
			}
			else if (line == "manufacturer")
			{
				getline(products, line, '<');
				list.back()->setManufacturer(line);
			}
			else if (line == "price")
			{
				getline(products, line, '<');
				list.back()->setPrice(stod(line));
			}
			else if (line == "id")
			{
				getline(products, line, '<');
				list.back()->setId(stoi(line));
			}
		}
	}
	products.close();
	return list;
}

void XMLService::exportXML()
{
	ofstream out("Products.xml");
	if (!out.is_open())
	{
		throw exception("File Products.xml isn't open!");
	}
	out.clear();
	out << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
	out << "<products>\n";
	List<Product*> list = DataManager().readAllProducts();

	for (List<Product*>::iterator i = list.begin();
		i != list.end(); i++)
	{
		string prod = typeid(*(*i)).name();
		prod = prod.substr(prod.find(' ') + 1);
		int lth = prod.length();
		transform(prod.begin(), prod.end(),
			prod.begin(), ::tolower);

		out << "\t<" << prod << ">\n";

		List<pair<string, string>> members = (*i)->metadata();
		for (List<pair<string, string>>::iterator j = members.begin();
			j != members.end();
			j++)
		{
			out << "\t\t<" << (*j).first << ">"
				<< (*j).second
				<< "</" << (*j).first << ">\n";
		}

		out << "\t</" << prod << ">\n";
	}

	out << "</products>";
	out.close();
}