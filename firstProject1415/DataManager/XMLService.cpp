#include "XMLService.h"
#include "DataManager.h"
#include "../UI/Globals.h"
#include <fstream>
#include <string>

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