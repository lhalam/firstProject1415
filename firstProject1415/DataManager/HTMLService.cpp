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