#include "stdafx.h"
#include "CppUnitTest.h"

#define DLL_IMPORT

#include "DataManager\DataManager.h"
#include "List\List.h"
#include "Products\Products.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace MyroslavVyspyanskyTests
{		
	TEST_CLASS(UnitTest1)
	{
	public:

		//doesn`t works
		TEST_METHOD(Statistics)
		{
			try
			{
				Clothing clothes;
				DataManager service;

				ofstream stream("Stats.txt");
				stream.close();

				service.saveStatistics(5, clothes.getId());
				int quantity;

				ifstream file("Stats.txt");

				file >> clothes >> quantity;

				file.close();

				Assert::AreEqual(5, quantity);
			}
			catch (...)
			{
				Assert::Fail();
			}
		}

		TEST_METHOD(SaveAndReadAllFuntions) // and also read function
		{
			try
			{
				DataManager service;
				Drink drink;
			
				service.saveProduct(drink);

				List<Product*> list = service.readAllProducts();

				ofstream stream_1("Products.txt");
				ofstream stream_2("Assortment.txt");
				ofstream stream_3("Stats.txt");
				stream_1.close();
				stream_2.close();
				stream_3.close();

				Assert::IsTrue(drink == *list.popFront());
			}
			catch (...)
			{
				Assert::Fail();
			}
		}

		TEST_METHOD(SetQuantityMethod)
		{
			try
			{
				Food food;
				DataManager service;
				service.saveProduct(food);

				int prevQuantity, prevId;
				ifstream fin("Assortment.txt");
				fin >> prevId >> prevQuantity;
				fin.close();
				service.changeQuantity(0, 5);
			
				int newQuantity, testId;
				ifstream stream("Assortment.txt");
				stream >> testId >> newQuantity;
				stream.clear();
				stream.close();

				ifstream file("Stats.txt");
				file.clear();
				file.close();

				Assert::AreEqual(prevId, testId);
				Assert::AreEqual(prevQuantity, 0);
				Assert::AreEqual(newQuantity, 5);
			}
			catch (...)
			{
				Assert::Fail();
			}
		}

		TEST_METHOD(RemoveByIdMethod)//also remove by predicate
		{
			try
			{
				Clothing clothes;
				DataManager service;
				service.saveProduct(clothes);

				service.removeProductById(clothes.getId());


				ifstream file("Stats.txt");
				file.clear();
				file.close();
				ifstream fin("Assortment.txt");
				string str;
				fin >> str;
				fin.clear();
				fin.close();

				Assert::IsTrue(str.empty());
			}
			catch (...)
			{
				Assert::Fail();
			}
		}
	};
}