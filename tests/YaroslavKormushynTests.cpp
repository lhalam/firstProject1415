#include "stdafx.h"
#include "CppUnitTest.h"

#define DLL_IMPORT

#include "UI/UI.h"
#include "Products/Products.h"
#include "DataManager/DataManager.h"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace YaroslavKormushynTests
{		
	TEST_CLASS(ProductMethodsTest)
	{
	public:
		
		TEST_METHOD(ProductConstructor)
		{
			Product* test = new Drink();
			
			Assert::AreEqual(test->getId(), 0u);
			Assert::AreEqual(test->getPrice(), 0.0);
			Assert::AreEqual(test->getManufacturer(), string("No manufacturer"));
			Assert::AreEqual(test->getName(), string("No name"));

			delete test;
		}

		TEST_METHOD(ProductInput)
		{
			Product* test = new Drink();
			
			string input = "Name\nManuf\n130\n2\n18 18 1996\n32 12 2014\nWater\n34\n";
			stringbuf in(input);
			cin.rdbuf(&in);

			try
			{
				test->input();
			}
			catch(...)
			{
				Assert::Fail();
			}

			delete test;
		}

		TEST_METHOD(ProductOutput)
		{
			Product* test = new Drink();
			
			string input = "Name\nManuf\n130\n2\n18 18 1996\n32 12 2014\nWater\n34\n";
			stringbuf in(input);
			cin.rdbuf(&in);
			test->input();
			try
			{
				stringstream sstream;
				streambuf* coutstream = cout.rdbuf(sstream.rdbuf());
				test->output();
				string act_out = sstream.str();
				cout.rdbuf(coutstream);
				string exp_out = "Name: Name\n"
								 "Manufacturer: Manuf\n"
								 "Price: 130.000000\n"
								 "ID: 2\n"
								 "Manufacture date: 18 18 1996\n"
								 "Expiration date: 32 12 2014\n"
								 "Ingredients: Water\n"
								 "Volume: 34.000000\n";
				Assert::AreEqual(exp_out, act_out);
			}
			catch(...)
			{
				Assert::Fail();
			}

			delete test;
		}

		TEST_METHOD(ProductComparisonOperators)
		{
			Product* test = new Drink();
			Product* test2 = new Drink();
			test->setId(20);
			test2->setId(31);
			Assert::IsFalse(*test == *test2);
			Assert::IsTrue(*test != *test2);
		}
	};
	
	TEST_CLASS(CommandHandlersTest)
	{
		TEST_METHOD(RemoveProductFromCartTest)
		{
			Product* test = new Drink();
			cart.pushBack(test);
			string input = "y\n";
			stringbuf in(input);
			cin.rdbuf(&in);
			try
			{
				//'remove' command execution
				commands[19].execute(); 
			}
			catch(...)
			{
				Assert::Fail();
			}

		}

		TEST_METHOD(ShowCartTest)
		{
			Product* test = new Drink();
			cart.pushBack(test);
			try
			{
				stringstream sstream;
				streambuf* coutstream = cout.rdbuf(sstream.rdbuf());
				commands[22].execute();
				string act_out = sstream.str();
				cout.rdbuf(coutstream);
				string exp_out = "Name: No name\n"
								 "Manufacturer: No manufacturer\n"
								 "Price: 0.000000\n"
								 "ID: 0\n"
								 "Manufacture date: 00.00.0000\n"
								 "Expiration date: 00.00.0000\n"
								 "Ingredients: No ingredients\n"
								 "Volume: 0.000000\n\n";
				Assert::AreEqual(exp_out, act_out);
			}
			catch(...)
			{
				Assert::Fail();
			}
		}
	};
	
}