#include "HTMLService.h"
#include "UserService.cpp"
#
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
				  "* { font-family: Verdana; }"
				  "h1 { font-size: 2em; font-weight: normal; text-align: center; }"
				  "p { font-size: 1.25em; }"
				  "</style>\n"
				  "</head>";

	file << head;

	string body = "<body>\n";

	ifstream history(to_string(id) + ".txt");
	Product *product;
	while (!history.eof())
	{
		string text = "<p>"
					  "Name: " + product->getName() + "\n"
					  "Manufacturer: " + product->getManufacturer() + "\n";

		file << text;
		file << "Price: ";
		file << product->getPrice();
		file << "\n";
		file << "</p>";
	}

	body += "</body>\n";

	file << body;

	file << "</html>";
	file.close();
}