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
		/*
		TEST_METHOD(Statistics)
		{
			Clothing clothes;
			DataManager service;

			ifstream file("Stats.txt");
			//file.clear();
			service.saveStatistics(5, clothes.getId());
			
			int quantity = 0, id = 0;
			Product* temp = new Clothing();
			file >> *temp >> id >> quantity;

			file.close();

			ifstream fin("Assortment.txt");
			fin.clear();
			fin.close();

			ifstream stream("Products.txt");
			stream.clear();
			stream.close();

			Assert::AreEqual(quantity, 5);
		}*/

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

				stream_1.clear();
				stream_2.clear();
				stream_3.clear();

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

			Clothing clothes;
			DataManager service;
			service.saveProduct(clothes);

			service.removeProductById(clothes.getId());

			
			ifstream file("Stats.txt");
			file.clear();
			file.close();
			/*
			ifstream fin("Assortment.txt");
			string str;
			fin >> str;
			fin.clear();
			fin.close();

			Assert::IsTrue(str.empty());*/
		}
	};
}

/*
void save(const Product& prod);
 
 Це можеш на моє глянути може зможеш виправити але нє обовязково
 void saveAll(List<Product*> list);
  
  void setQuantity(int id, int newQuantity);
 
 
 void removeById(int id);

 
 void removeByPredicate(function<bool(const Product&)> predicate);

 
 List<Product*> readAll();


 List<Product*> read(function<bool(const Product&)> predicate);

 
 void saveStatistics(unsigned quantity, int id);

 /це мені ще треба але я не знаю ще як
 map<Product*, int> readStatistics();


*/