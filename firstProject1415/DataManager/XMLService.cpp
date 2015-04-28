#include "XMLService.h"
#include "DataManager.h"
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
	DataManager manager;

	while (!products.eof())
	{
		string line;
		if (products.get() == '<')
		{
			getline(products, line, '>');
			if (manager.identifyProductType(line) != nullptr)
			{
				Product* prod = manager.identifyProductType(line);
				list.pushBack(prod);
			}
		}
	}
	products.close();
	return list;
}