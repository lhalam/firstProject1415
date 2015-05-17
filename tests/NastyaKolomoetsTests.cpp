#include "stdafx.h"
#include "CppUnitTest.h"

#define DLL_IMPORT
#include "UI/UI.h"
#include "DataManager\DataManager.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NastyaKolomoetsTests
{		
	TEST_CLASS(CommandHandlersTests)
	{
	public:
		
		TEST_METHOD(RemoveProductFromAssortmentTest)
		{
			int id = 3;
			string inputId = to_string(id) + "\n";
			stringbuf in(inputId);
			cin.rdbuf(&in);
			DataManager manager;
			try
			{
				commands[18].execute();
			}
			catch (...)
			{
				Assert::Fail();
			}
			Assert::AreEqual(-1, manager.getQuantity(id));
			Assert::AreEqual(to_string(commands[18].execute().getId()), to_string(SUCCESSFUL));
		}

		TEST_METHOD(ShowUsersTest)
		{
			stringstream sstream;
			streambuf* coutstream = cout.rdbuf(sstream.rdbuf()); 
			commands[21].execute();
			cout.rdbuf(coutstream);
			string output = sstream.str();
			/*string line = "Name: Nastya\n"
				"Surname: Kolomoets\n"
				"Birthday: 12/5/1997\n"
				"Login: Nastya\n"
				"Password: nastya\n"
				"Email: nastya.kolomoets@gmail.com\n"
				"Role:  user\n"
				"Id: 1\n"
				"\nListing completed.\n";*/
			string line = "Listing completed.\n";
			Assert::AreEqual(output, line);
			Assert::AreEqual(to_string(commands[21].execute().getId()), to_string(SUCCESSFUL));
		}

		TEST_METHOD(ShowStatsTest)
		{
			stringstream sstream;
			streambuf* coutstream = cout.rdbuf(sstream.rdbuf());
			commands[24].execute();
			cout.rdbuf(coutstream);
			string output = sstream.str();
			/*string line = "Name: Shirt\n"
				"Manufacturer: OGGI\n"
				"Price: 350.000000\n"
				"ID: 6\n"
				"Quantity: 0\n"
				"Listing completed.\n";*/
			string line = "Listing completed.\n";
			Assert::AreEqual(output, line);
			Assert::AreEqual(to_string(commands[24].execute().getId()), to_string(SUCCESSFUL));
		}
	};
}
