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

		if (type.empty())
		{
			continue;
		}

		Product *prod = getProduct(type, stream);

		if (predicate(*prod))
			list.pushBack(prod);
	}

	stream.close();
	return list;
}

int ProductService::getQuantity(int id)
{
	ifstream assortment("Assortment.txt");
	if (!assortment.is_open())
	{
		throw exception("Cannot open file for reading.");
	}

	unsigned currentId, quant;

	while (!assortment.eof())
	{
		assortment >> currentId >> quant;

		if (currentId == id)
		{
			assortment.close();
			return quant;
		}
	}

	assortment.close();
	return -1;
}

void ProductService::setQuantity(int id, int new_quantity)
{
	ifstream assortment("Assortment.txt");
	if (!assortment.is_open())
	{
		throw exception("Cannot open file for reading.");
	}

	ofstream tempAssort("tempAsort");
	if (!tempAssort.is_open())
	{
		throw exception("Cannot open temporary file for writing.");
	}

	unsigned currentId, quant;

	while (!assortment.eof())
	{
		assortment >> currentId >> quant;

		tempAssort << currentId << " ";
		if (currentId != id)
		{
			tempAssort << quant;
		}
		else
		{
			cout << "Current quantity of product with id " << id << " is - " << quant << endl;
			cout << "Enter new quantity : ";
			cin >> new_quantity;
			tempAssort << new_quantity;
		}
		tempAssort << endl;
	}

	tempAssort.close();
	assortment.close();

	remove("Assortment.txt");
	rename("tempAssort.txt", "Assortment.txt");
}

void ProductService::changeQuantity(int id, int add_quantity)
{
	ifstream assortment("Assortment.txt");
	if (!assortment.is_open())
	{
		throw exception("Cannot open file for reading.");
	}

	ofstream tempAssort("tempAsort");
	if (!tempAssort.is_open())
	{
		throw exception("Cannot open temporary file for writing.");
	}

	unsigned currentId, quant;

	while (!assortment.eof())
	{
		assortment >> currentId >> quant;

		tempAssort << currentId << " ";
		if (currentId != id)
		{
			tempAssort << quant;
		}
		else
		{
			tempAssort << quant + add_quantity;
		}
		tempAssort << endl;
	}

	tempAssort.close();
	assortment.close();

	remove("Assortment.txt");
	rename("tempAssort.txt", "Assortment.txt");
}

Product* ProductService::getById(int id)
{
	ifstream stream("Products.txt");
	if (!stream.is_open())
	{
		throw exception("Cannot open file for reading.");
	}

	Product *product = nullptr;
	bool isSuccessful = false;

	while (!stream.eof())
	{
		string productType;
		getline(stream, productType);

		if (productType.empty())
		{
			continue;
		}

		Product *product = getProduct(productType, stream);

		if (product->getId() == id)
		{
			isSuccessful = true;
			break;
		}
	}

	if (!isSuccessful)
	{
		product = nullptr;
	}

	stream.close();
	return product;
}

void ProductService::removeById(int id)
{
	removeByPredicate([id](const Product& product) -> bool {	return id == product.getId(); });
}

void ProductService::removeByPredicate(function<bool(const Product&)> predicate)
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

	List<int> ids;

	while (!stream.eof())
	{
		string type;
		getline(stream, type);

		if (type.empty())
		{
			continue;
		}

		Product *prod = getProduct(type, stream);

		if (!predicate(*prod))
		{
			temp << typeid(*prod).name() << endl;
			temp << *prod;
		}
		else
		{
			ids.pushBack(prod->getId());
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

		if (ids.front() != currentId)
		{
			tempAsort << currentId << ' ' << quant << endl;
		}

		ids.erase(ids.begin());
	}

	tempAsort.close();
	asortment.close();

	remove("Assortment.txt");
	rename("tempAsort.txt", "Assortment.txt");
}

Product * ProductService::getProduct(string type, istream& stream)
{
	Product *prod = nullptr;

	if (type == typeid(Appliance).name())
	{
		prod = new Appliance();
		stream >> (Appliance&)*prod;
	} else if (type == typeid(AudioAndTv).name())
	{
		prod = new AudioAndTv();
		stream >> (AudioAndTv&)*prod;
	} else if (type == typeid(LaptopAndComputer).name())
	{
		prod = new LaptopAndComputer();
		stream >> (LaptopAndComputer&)*prod;
	} else if (type == typeid(PhotoAndVideoCamera).name())
	{
		prod = new PhotoAndVideoCamera();
		stream >> (PhotoAndVideoCamera&)*prod;
	} else if (type == typeid(PhoneAndTablet).name())
	{
		prod = new PhoneAndTablet();
		stream >> (PhoneAndTablet&)*prod;
	} else if (type == typeid(Food).name())
	{
		prod = new Food();
		stream >> (Food&)*prod;
	} else if (type == typeid(Drink).name())
	{
		prod = new Drink();
		stream >> (Drink&)*prod;
	} else if (type == typeid(Accessory).name())
	{
		prod = new Accessory();
		stream >> (Accessory&)*prod;
	} else if (type == typeid(Clothing).name())
	{
		prod = new Clothing();
		stream >> (Clothing&)*prod;
	} else if (type == typeid(Footwear).name())
	{
		prod = new Footwear();
		stream >> (Footwear&)*prod;
	} else if (type == typeid(Detergent).name())
	{
		prod = new Detergent();
		stream >> (Detergent&)*prod;
	} else if (type == typeid(Cosmetic).name())
	{
		prod = new Cosmetic();
		stream >> (Cosmetic&)*prod;
	} else if (type == typeid(PersonalHygiene).name())
	{
		prod = new PersonalHygiene();
		stream >> (PersonalHygiene&)*prod;
	} else
	{
		throw exception("Unknown type of product.");
	}

	return prod;
}

void ProductService::saveStatistics(unsigned quantity, int id)
{
	ofstream stream("Stats.txt", ios_base::app);

	if (!stream.is_open())
	{
		 throw exception("Cannot open file for writing.");
	}

	stream << getById(id) << endl;
	stream << quantity;

 stream.close();
}
