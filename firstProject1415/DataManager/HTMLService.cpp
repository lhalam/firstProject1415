#include "HTMLService.h"
#include "ProductService.h"
#include "../List/List.h"


#include <fstream>
#include <string>

using namespace std;

void HTMLService::write(int id, const Date& start, const Date& end)
{
	//Change the direction if you want
	ofstream file("History.html");
	file << "<!DOCTYPE html>\n";
	file << "<html>\n";

	string head = "<head>\n"
				  "<title>Purchase history</title>\n"
				  "<meta charset=\"UTF-8\"/>\n"
				  "<style type=\"text/css\">\n"
				  "* { font-family: Verdana; }\n"
				  "h1 { font-size: 2em; font-weight: normal; text-align: center; }\n"
				  "p { font-size: 1.25em; }\n"
				  "</style>\n"
				  "</head>\n";

	file << head;

	file << "<body>\n";
	file << "<h1>Purchase history</h1>\n";

	UserService user;
	Product *product = nullptr;
	auto list = user.getAllFromHistory(id);

	for (auto iter = list.begin(); iter != list.end(); iter++)
	{ 
		auto metadataList = (*iter).first->metadata();
		file << "<p>\n";
		string type = typeid(*((*iter).first)).name();
		type = type.substr(6);
		file << type << ":<br/>\n";
		for (auto metadataIter = metadataList.begin(); metadataIter != metadataList.end(); metadataIter++)
		{
			file << (*metadataIter).first << ": " << (*metadataIter).second << "<br/>\n";
		}
		file << "Quantity: " << (*iter).second << "<br/>\n";
		file << "</p>\n";
	}

	for (auto iter = list.begin(); iter != list.end(); iter++)
	{
		delete (*iter).first;
	}

	file << "</body>\n";
	file << "</html>\n";
	file.close();
}