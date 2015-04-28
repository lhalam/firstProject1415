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
	if (type == "Appliance" || type == "appliance")
	{
		prod = new Appliance();
		return prod;
	}
	else if (type == "Audio&TV" || type == "audio&TV")
	{
		prod = new AudioAndTv();
		return prod;
	}
	else if (type == "Laptop&computer" || type == "laptop&computer")
	{
		prod = new LaptopAndComputer();
		return prod;
	}
	else if (type == "Phone&tablet" || type == "phone&tablet")
	{
		prod = new PhoneAndTablet();
		return prod;
	}
	else if (type == "Photo&videocamera" || type == "photo&videocamera")
	{
		prod = new PhotoAndVideoCamera();
		return prod;
	}
	else if (type == "Drink" || type == "drink")
	{
		prod = new Drink();
		return prod;
	}
	else if (type == "Food" || type == "food")
	{
		prod = new Food();
		return prod;
	}
	else if (type == "Accessory" || type == "accessory")
	{
		prod = new Accessory();
		return prod;
	}
	else if (type == "Clothing" || type == "clothing")
	{
		prod = new Clothing();
		return prod;
	}
	else if (type == "Footwear" || type == "footwear")
	{
		prod = new Footwear();
		return prod;
	}
	else if (type == "Cosmetic" || type == "cosmetic")
	{
		prod = new Cosmetic();
		return prod;
	}
	else if (type == "Detergent" || type == "detergent")
	{
		prod = new Detergent();
		return prod;
	}
	else if (type == "Personal hygiene" || type == "personal hygiene")
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

