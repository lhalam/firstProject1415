#include "stdafx.h"
#include "CppUnitTest.h"

#define DLL_IMPORT

#include "firstProject1415/UI/UI.h"
#include "firstProject1415/Products/Products.h"
#include "firstProject1415/DataManager/DataManager.h"

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
				test->output();
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
	/*
	TEST_CLASS(CommandHandlersTest)
	{
		TEST_METHOD(RemoveProductFromCartTest)
		{
			Product* test = new Drink();
			
			try
			{
				//remove command execution
				commands[19].execute(); 
			}
			catch(...)
			{
				Assert::Fail();
			}

		}

		TEST_METHOD(ShowCartTest)
		{
			int delta = 6;
			Product* test = new Drink();
			for (int i = 0; i < delta; i++)
			{
				//independent adding to cart
			}
			for (int i = 0; i < delta; i++)
			{
				//here - reading cart and comparing
				Assert::IsTrue();
			}
		}

	};
	*/
}