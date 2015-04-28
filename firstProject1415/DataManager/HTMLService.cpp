#include "HTMLService.h"
#include <fstream>

using namespace std;

void HTMLService::write(const Date& start, const Date& end)
{
	//Change the direction if you want
	ofstream file("File.html");
	file << "<!DOCTYPE html>\n";
	file << "<html>\n";

	file << "<head>";
	file << "</head>\n";

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