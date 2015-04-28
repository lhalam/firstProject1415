#include "HTMLService.h"
#include <fstream>
#include <string>

using namespace std;

void HTMLService::write(const Date& start, const Date& end)
{
	//Change the direction if you want
	ofstream file("History.html");
	file << "<!DOCTYPE html>\n";
	file << "<html>\n";

	string head = "<head>\n"
				  "<title>Purchase history</title>\n"
				  "<meta charset=\"UTF-8\"/>\n"
				  "<style type=\"text/css\">\n"
				  "* { font-family: Verdana; font-weight: normal; }"
				  "h1 { font-size: 2em; text-align: center; }"
				  "p { font-size: 1.25em; }"
				  "</style>\n"
				  "</head>";

	//Change cycle as you wish
	file << "<body>\n";
	for (unsigned i = 0; i < 5; i++)
	{
		//file << "<p>" << i <<"</p>";
	}
	file << "</body>\n";

	file << "</html>";
	file.close();
}