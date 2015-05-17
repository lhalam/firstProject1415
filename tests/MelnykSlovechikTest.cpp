#include "stdafx.h"
#include "CppUnitTest.h"

#define DLL_IMPORT

#include <fstream>
#include <iostream>
#include "Products/Products.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace MelnykSlovechikTest
{
	TEST_CLASS(ChemicalProductTests)
	{
	public:
		
		TEST_METHOD(PersonalHygieneConstructor)
		{
			PersonalHygiene testObject;
			Assert::AreEqual(testObject.getManufacturer(), string("No manufacturer"));
			Assert::AreEqual(testObject.getName(), string("No name"));
			Assert::AreEqual(testObject.getPrice(), 0.0);
			Assert::AreEqual(testObject.getId(), 0);
			Assert::AreEqual(testObject.getVolume(), 0.0);
			Assert::AreEqual(testObject.getManufactureDate(), string("00.00.0000"));
		}
		
		TEST_METHOD(PersonalHygieneInput)
		{
			PersonalHygiene testObject;
			string input = "Name\nManuf\n69\n9\n02.04.2014\n2.5\n";
			stringbuf in(input);
			cin.rdbuf(&in);
			try
			{
				testObject.input();
			}
			catch (...)
			{
				Assert::Fail();
			}
		}
		
		TEST_METHOD(PersonalHygieneOutput)
		{
			PersonalHygiene testObject;

			string input = "Name\nManuf\n69\n9\n02.04.2014\n2.5\n";
			stringbuf in(input);
			cin.rdbuf(&in);
			testObject.input();
			try
			{
				stringstream sstream;
				streambuf* coutstream = cout.rdbuf(sstream.rdbuf());
				testObject.output();
				string act_out = sstream.str();
				cout.rdbuf(coutstream);
				string exp_out =
					"Name: Name\n"
					"Manufacturer: Manuf\n"
					"Price: 69.000000\n"
					"ID: 9\n"
					"Manufacture date: 02.04.2014\n"
					"Volume: 2.500000\n";
				Assert::AreEqual(exp_out, act_out);
			}
			catch (...)
			{
				Assert::Fail();
			}
		}
	};
}