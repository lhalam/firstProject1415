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

namespace Team4
{
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

	List<Product&> ProductService::readAll()
	{
		return read(alwaysTrue);
	}

	
	List<Product&> ProductService::read(bool (*predicate)(const Product& prod))
	{
		ifstream stream("Products.txt");
		if (!stream.is_open())
		{
			throw exception("Cannot open file for reading.");
		}

		List<Product&> list;

		string type;
		getline(stream, type);
		
		if (type == typeid(Appliance).name())
		{
			Appliance prod;
			
		} else if (type == typeid(AudioAndTv).name())
		{
			AudioAndTv prod;
			stream >> prod;
			if (predicate(prod))
				list.pushBack(prod);
		} else if (type == typeid(LaptopAndComputer).name())
		{
			LaptopAndComputer prod;
			stream >> prod;
			if (predicate(prod))
				list.pushBack(prod);
		} else if (type == typeid(PhotoAndVideoCamera).name())
		{
			PhotoAndVideoCamera prod;
			stream >> prod;
			if (predicate(prod))
				list.pushBack(prod);
		} else if (type == typeid(PhoneAndTablet).name())
		{
			PhoneAndTablet prod;
			stream >> prod;
			if (predicate(prod))
				list.pushBack(prod);
		} else if (type == typeid(Food).name())
		{
			Food prod;
			stream >> prod;
			if (predicate(prod))
				list.pushBack(prod);
		} else if (type == typeid(Drink).name())
		{
			Drink prod;
			stream >> prod;
			if (predicate(prod))
				list.pushBack(prod);
		} else if (type == typeid(Accessory).name())
		{
			Accessory prod;
			stream >> prod;
			if (predicate(prod))
				list.pushBack(prod);
		} else if (type == typeid(Clothing).name())
		{
			Clothing prod;
			stream >> prod;
			if (predicate(prod))
				list.pushBack(prod);
		} else if (type == typeid(Footwear).name())
		{
			Footwear prod;
			stream >> prod;
			if (predicate(prod))
				list.pushBack(prod);
		} else if (type == typeid(Detergent).name())
		{
			Detergent prod;
			stream >> prod;
			if (predicate(prod))
				list.pushBack(prod);
		} else if (type == typeid(Cosmetic).name())
		{
			Cosmetic prod;
			stream >> prod;
			if (predicate(prod))
				list.pushBack(prod);
		} else if (type == typeid(PersonalHygiene).name())
		{
			PersonalHygiene prod;
			stream >> prod;
			if (predicate(prod))
				list.pushBack(prod);
		}
		
		stream.close();
		return list;
	}
}