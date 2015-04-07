#include "ProductService.h"
#include <fstream>
#include <exception>
#include <typeinfo>
#include <string>

#include "../Products/Electronic/Appliance.h"
#include "../Products/Electronic/AudioAndTv.h"
#include "../Products/Electronic/LaptopAndComputer.h"
#include "../Products/Electronic/PhotoAndVideoCamera.h"
#include "../Products/Electronic/PhoneAndTablet.h"
#include "../Products/Nutrition/Food.h"
#include "../Products/Nutrition/Drink.h"
#include "../Products/Textile/Accessory.h"
#include "../Products/Textile/Clothing.h"
#include "../Products/Textile/Footwear.h"
#include "../Products/ChemicalProduct/Detergent.h"
#include "../Products/ChemicalProduct/Cosmetic.h"
#include "../Products/ChemicalProduct/PersonalHygiene.h"

using namespace std;

void ProductService::save(const Product& prod)
{
	ofstream stream("Products.txt", ios_base::app);

	if (!stream.is_open())
	{
		throw exception("Cannot open file for writing.");
	}

	stream << typeid(prod).name() << endl;
	stream << prod;

	stream.close();
}

List<Product*> ProductService::readAll()
{
	return read([](const Product& prod) { return true; });
}

List<Product*> ProductService::read(function<bool(const Product&)> predicate)
{
	ifstream stream("Products.txt");
	if (!stream.is_open())
	{
		throw exception("Cannot open file for reading.");
	}
	
	List<Product*> list;
	
	while (!stream.eof())
	{
		string type;
		getline(stream, type);

		Product *prod = getProduct(type);

		stream >> *prod;
		if (predicate(*prod))
			list.pushBack(prod);
	}

	stream.close();
	return list;
}

void ProductService::removeById(int id)
{
	ifstream stream("Products.txt");
	if (!stream.is_open())
	{
		throw exception("Cannot open file for reading.");
	}

	ofstream temp("Temp.txt");
	if (!temp.is_open())
	{
		throw exception("Cannot open temporary file for writing.");
	}


	while (!stream.eof())
	{
		string type;
		getline(stream, type);
		Product *prod = getProduct(type);
		stream >> *prod;

		if (prod->getId() != id)
		{
			temp << typeid(*prod).name() << endl;
			temp << *prod;
		}
	}

	temp.close();
	stream.close();

	remove("Products.txt");
	rename("Temp.txt", "Products.txt");

	ifstream asortment("Assortment.txt");
	if (!asortment.is_open())
	{
		throw exception("Cannot open file for reading.");
	}

	ofstream tempAsort("tempAsort");
	if (!tempAsort.is_open())
	{
		throw exception("Cannot open temporary file for writing.");
	}

	unsigned currentId, quant;

	while (!asortment.eof())
	{
		asortment >> currentId >> quant;

		if (currentId != id)
		{
			tempAsort << currentId << " " << quant << endl;
		}
	}

	tempAsort.close();
	asortment.close();

	remove("Assortment.txt");
	rename("tempAsort.txt", "Assortment.txt");
}


Product * ProductService::getProduct(string type)
{
	Product *prod = nullptr;

	if (type == typeid(Appliance).name())
	{
		prod = new Appliance();
	} else if (type == typeid(AudioAndTv).name())
	{
		prod = new AudioAndTv();
	} else if (type == typeid(LaptopAndComputer).name())
	{
		prod = new LaptopAndComputer();
	} else if (type == typeid(PhotoAndVideoCamera).name())
	{
		prod = new PhotoAndVideoCamera();
	} else if (type == typeid(PhoneAndTablet).name())
	{
		prod = new PhoneAndTablet();
	} else if (type == typeid(Food).name())
	{
		prod = new Food();
	} else if (type == typeid(Drink).name())
	{
		prod = new Drink();
	} else if (type == typeid(Accessory).name())
	{
		prod = new Accessory();
	} else if (type == typeid(Clothing).name())
	{
		prod = new Clothing();
	} else if (type == typeid(Footwear).name())
	{
		prod = new Footwear();
	} else if (type == typeid(Detergent).name())
	{
		prod = new Detergent();
	} else if (type == typeid(Cosmetic).name())
	{
		prod = new Cosmetic();
	} else if (type == typeid(PersonalHygiene).name())
	{
		prod = new PersonalHygiene();
	} else
	{
		throw exception("Unknown type of product.");
	}

	return prod;
}