#include "Globals.h"

/* Definition of all global variables */
User currentUser = User();
List<Product*> cart = List<Product*>();

/* Definition of all global functions */
void toLowercase(string& line)
{
	for(unsigned i = 0; i < line.length(); i++)
	{
		line[i] = tolower(line[i]);
	}
}

Product* identifyType(string type)
{
	Product* prod = nullptr;
	if (type == "appliance")
	{
		prod = new Appliance();
		return prod;
	}
	else if (type == "audio&TV")
	{
		prod = new AudioAndTv();
		return prod;
	}
	else if (type == "laptop&computer")
	{
		prod = new LaptopAndComputer();
		return prod;
	}
	else if (type == "phone&tablet")
	{
		prod = new PhoneAndTablet();
		return prod;
	}
	else if (type == "photo&videocamera")
	{
		prod = new PhotoAndVideoCamera();
		return prod;
	}
	else if (type == "drink")
	{
		prod = new Drink();
		return prod;
	}
	else if (type == "food")
	{
		prod = new Food();
		return prod;
	}
	else if (type == "accessory")
	{
		prod = new Accessory();
		return prod;
	}
	else if (type == "clothing")
	{
		prod = new Clothing();
		return prod;
	}
	else if (type == "footwear")
	{
		prod = new Footwear();
		return prod;
	}
	else if(type == "cosmetics")
	{
		prod = new Cosmetics();
		return prod;
	}
	else if (type == "detergent")
	{
		prod = new Detergent();
		return prod;
	}
	else if (type == "personal hygiene")
	{
		prod = new PersonalHygiene();
		return prod;
	}
	return prod;
}

bool ifValidString(const string& str)
{
	if(str[0] == ' ' || str[0] == '\t'|| str[0] == '\n'|| 
	   str[0] == '\0'|| str[0] == '\a'|| str[0] == '.' || 
	   str[0] == ',' || str[0] == ':' || str[0] == ';' || 
	   str[0] == '`' || str[0] == '&' || str[0] == '@' )
	{
		return false;
	}
	return true;
}

