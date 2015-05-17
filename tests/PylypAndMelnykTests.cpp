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
		TEST_METHOD(CosmeticsOutput)
		{
			Cosmetics testObject;
			string input = "Natural\nNivea\n73\n5\n02.02.2014\n0.2\nb\n";
			stringbuf in(input);
			cin.rdbuf(&in);
			testObject.input();
			try
			{
				testObject.output();
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
				testObject.output();
			}
			catch (...)
			{
				Assert::Fail();
			}
		}
	};
}