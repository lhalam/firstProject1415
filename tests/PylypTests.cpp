#include "stdafx.h"
#include "CppUnitTest.h"

#define DLL_IMPORT

#include <fstream>
#include <iostream>
#include "Products/Products.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Test
{		
	TEST_CLASS(ChemicalProductTests)
	{
	public:
		TEST_METHOD(ChemicalProductConstructor)
		{
			Cosmetics testObject;
			Assert::AreEqual(testObject.getManufacturer(), string("No manufacturer"));
			Assert::AreEqual(testObject.getName(), string("No name"));
			Assert::AreEqual(testObject.getPrice(), 0.0);
			Assert::AreEqual(testObject.getId(), 0u);
			Assert::AreEqual(testObject.getVolume(), 0.0);
			Assert::AreEqual(testObject.getManufactureDate(), string("00.00.0000"));
		}
		TEST_METHOD(CosmeticsConstructor)
		{
			Cosmetics testObject;
			Assert::AreEqual(testObject.getManufacturer(), string("No manufacturer"));
			Assert::AreEqual(testObject.getName(), string("No name"));
			Assert::AreEqual(testObject.getPrice(), 0.0);
			Assert::AreEqual(testObject.getId(), 0u);
			Assert::AreEqual(testObject.getVolume(), 0.0);
			Assert::AreEqual(testObject.getManufactureDate(), string("00.00.0000"));
			Assert::AreEqual(testObject.getPartOfBody(), ' ');
		}
		TEST_METHOD(DetergentConstructor)
		{
			Detergent testObject;
			Assert::AreEqual(testObject.getManufacturer(), string("No manufacturer"));
			Assert::AreEqual(testObject.getName(), string("No name"));
			Assert::AreEqual(testObject.getPrice(), 0.0);
			Assert::AreEqual(testObject.getId(), 0u);
			Assert::AreEqual(testObject.getVolume(), 0.0);
			Assert::AreEqual(testObject.getManufactureDate(), string("00.00.0000"));
		}
		TEST_METHOD(ChemicalProductInput)
		{
			Cosmetics testObject;
			string input = "Chemical\nOrest\n13\n2\n07.07.2014\n0.9\n";
			stringbuf in(input);
			cin.rdbuf(&in);
			try
			{
				testObject.ChemicalProduct::input();
			}
			catch (...)
			{
				Assert::Fail();
			}
		}
		TEST_METHOD(CosmeticsInput)
		{
			Cosmetics testObject;
			string input = "Natural\nNivea\n73\n5\n02.02.2014\n0.2\nb\n";
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
		TEST_METHOD(DetergentInput)
		{
			Detergent testObject;
			string input = "Atlantic\nUnilever\n25\n3\n04.04.2014\n0.5\n";
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
		TEST_METHOD(ChemicalProductOutput)
		{
			Cosmetics testObject;

			string input = "Chemical\nOrest\n13\n2\n07.07.2014\n0.9\n";
			stringbuf in(input);
			cin.rdbuf(&in);
			testObject.ChemicalProduct::input();
			try
			{
				stringstream sstream;
				streambuf* coutstream = cout.rdbuf(sstream.rdbuf());
				testObject.ChemicalProduct::output();
				string act_out = sstream.str();
				cout.rdbuf(coutstream);
				string exp_out =
					"Name: Chemical\n"
					"Manufacturer: Orest\n"
					"Price: 13.000000\n"
					"ID: 2\n"
					"Manufacture date: 07.07.2014\n"
					"Volume: 0.900000\n";
				Assert::AreEqual(exp_out, act_out);
			}
			catch (...)
			{
				Assert::Fail();
			}
		}
		TEST_METHOD(CosmeticsOutput)
		{
			Cosmetics testObject;

			string input = "Natural\nNivea\n73\n5\n02.02.2014\n0.2\nb\n";
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
					"Name: Natural\n"
					"Manufacturer: Nivea\n"
					"Price: 73.000000\n"
					"ID: 5\n"
					"Manufacture date: 02.02.2014\n"
					"Volume: 0.200000\n"
					"Part of body: body\n";
				Assert::AreEqual(exp_out, act_out);
			}
			catch (...)
			{
				Assert::Fail();
			}
		}
		TEST_METHOD(DetergentOutput)
		{
			Detergent testObject;

			string input = "Atlantic\nUnilever\n25\n3\n04.04.2014\n0.5\n";
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
					"Name: Atlantic\n"
					"Manufacturer: Unilever\n"
					"Price: 25.000000\n"
					"ID: 3\n"
					"Manufacture date: 04.04.2014\n"
					"Volume: 0.500000\n";
				Assert::AreEqual(exp_out, act_out);
			}
			catch (...)
			{
				Assert::Fail();
			}
		}
		TEST_METHOD(ChemicalProductSetAndGet)
		{
			Detergent testObject;
			testObject.ChemicalProduct::setName("Chemical");
			testObject.ChemicalProduct::setManufacturer("Orest");
			testObject.ChemicalProduct::setPrice(13);
			testObject.ChemicalProduct::setId(2);
			testObject.ChemicalProduct::setManufactureDate("07.07.2014");
			testObject.ChemicalProduct::setVolume(0.9);
			Assert::AreEqual(testObject.ChemicalProduct::getName(), string("Chemical"));
			Assert::AreEqual(testObject.ChemicalProduct::getManufacturer(), string("Orest"));
			Assert::AreEqual(testObject.ChemicalProduct::getPrice(), 13.0);
			Assert::AreEqual(testObject.ChemicalProduct::getId(), 2u);
			Assert::AreEqual(testObject.ChemicalProduct::getManufactureDate(), string("07.07.2014"));
			Assert::AreEqual(testObject.ChemicalProduct::getVolume(), 0.9);
		}
		TEST_METHOD(CosmeticsSetAndGet)
		{
			Cosmetics testObject;
			testObject.setName("Natural");
			testObject.setManufacturer("Nivea");
			testObject.setPrice(73);
			testObject.setId(5);
			testObject.setManufactureDate("02.02.2014");
			testObject.setVolume(0.2);
			testObject.setPartOfBody('b');
			Assert::AreEqual(testObject.getName(), string("Natural"));
			Assert::AreEqual(testObject.getManufacturer(), string("Nivea"));
			Assert::AreEqual(testObject.getPrice(), 73.0);
			Assert::AreEqual(testObject.getId(), 5u);
			Assert::AreEqual(testObject.getManufactureDate(), string("02.02.2014"));
			Assert::AreEqual(testObject.getVolume(), 0.2);
			Assert::AreEqual(testObject.getPartOfBody(), 'b');
		}
		TEST_METHOD(DetergentSetAndGet)
		{
			Detergent testObject;
			testObject.setName("Atlantic");
			testObject.setManufacturer("Unilever");
			testObject.setPrice(25);
			testObject.setId(3);
			testObject.setManufactureDate("04.04.2014");
			testObject.setVolume(0.5);
			Assert::AreEqual(testObject.getName(), string("Atlantic"));
			Assert::AreEqual(testObject.getManufacturer(), string("Unilever"));
			Assert::AreEqual(testObject.getPrice(), 25.0);
			Assert::AreEqual(testObject.getId(), 3u);
			Assert::AreEqual(testObject.getManufactureDate(), string("04.04.2014"));
			Assert::AreEqual(testObject.getVolume(), 0.5);
		}
		TEST_METHOD(ComprasionOperators)
		{
			Detergent test1;
			Cosmetics test2;
			Assert::IsTrue(test1 == test2);
			test1.setId(5u);
			test2.setId(7u);
			Assert::IsTrue(test1 != test2);
		}
	};
}