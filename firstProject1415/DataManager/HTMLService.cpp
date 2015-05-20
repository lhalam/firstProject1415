#include "HTMLService.h"
#include "ProductService.h"
#include "../UI/Globals.h"

#include <fstream>
#include <cctype>

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
	file << "<h1>Purchase history of " << currentUser.getName() << ' '
		 << currentUser.getSurname() << "</h1>\n";

	UserService user;
	Product *product = nullptr;
	auto list = user.getAllFromHistory(id);

	if (list.isEmpty())
	{
		file << "<p>No items were purchased.</p>\n";
		file.close();
		return;
	}

	for (auto iter = list.begin(); iter != list.end(); iter++)
	{ 
		auto metadataList = (*iter).first->metadata();
		this->format(metadataList);

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

void HTMLService::format(List<pair<string, string>>& list)
{
	for (auto iter = list.begin(); iter != list.end(); iter++)
	{
		int length = (*iter).first.length();

		if ((*iter).first == "GMOContent")
		{
			(*iter).first = "GMO Content";
			(*iter).second = ((*iter).second == "1" ? "yes" : "no");
			continue;
		}

		for (int i = 1; i < length; i++)
		{
			if (isupper((*iter).first[i]))
			{
				(*iter).first.insert(i, 1, ' ');
			}
		}

		(*iter).first[0] = toupper((*iter).first[0]);
	}
}
