#include "HTMLService.h"
#include <fstream>

using namespace std;

void HTMLService::write(const Date& start, const Date& end)
{
	ofstream file("File.html");
	file << "<!DOCTYPE html>\n";
	file << "<html>\n";

	file << "<head>";
	file << "</head>\n";

	file << "<body>\n";
	/*for (unsigned i = 0; i < 5; i++)
	{
		file << "<p>" << i <<"</p>";
	}*/
	file << "</body>\n";

	file << "</html>";
	file.close();
}