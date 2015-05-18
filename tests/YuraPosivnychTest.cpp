#include "stdafx.h"
#include "CppUnitTest.h"
#define DLL_IMPORT
#include "DataManager/DataManager.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PruductServiceTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(GetQuantityTest)
		{
			//must create Assortment.txt with line "10 10"
			DataManager service;
			int test = 0;
			try
			{
				test = service.getQuantity(10);
			}
			catch (...)
			{
				Assert::Fail();
			}
			Assert::AreEqual(test, 10);
		}
		
	//must have clean text files
	TEST_METHOD(SaveAllTest)
		{
			DataManager service;
			Product *prod1 = new Clothing();

			List<Product*> list;
			list.pushBack(prod1);

			service.saveAllProducts(list); 
			int id = 0;
			try
			{
				id = ((service.readAllProducts()).popFront())->getId();
			}
			catch (exception e)
			{
				Assert::AreEqual(e.what(),"Cannot open file for writing.");
			}
			Assert::AreEqual(id, 0);
		}
	
		
		TEST_METHOD(ReadTest)
		{
			//must create Products.txt with default product
			DataManager service;
			string str = "";
			try
			{
				auto lambda = [](const Product& prod)
				{
					return prod.getPrice() == 0;
				};
				str = ((service.readProducts(lambda).popBack())->getName());
			}
			catch (exception e)
			{
				Assert::Fail();
			}
			char* ch = &str[0u];
			Assert::AreEqual(ch, "No name");
		}
		
		TEST_METHOD(ChangeQuantityTest)
		{
			//must create Assortment.txt with line "8 8"
			DataManager service;
			int test = 0;
			try
			{
				test = service.getQuantity(8);
				service.changeQuantity(8, 2);
				test = service.getQuantity(8);
			}
			catch (exception e)
			{
				Assert::Fail();
			}
			Assert::AreEqual(test, 10);
		}
				
		TEST_METHOD(GetByIdTest)
		{
			//must create Products.txt with default product and change id(4),price(3.0)"
			DataManager service;
			double test = 0;
			try
			{
				test = (service.getProductById(4))->getPrice();
			}
			catch (exception e)
			{
				Assert::Fail();
			}
			
			Assert::AreEqual(test, 3.0);
		}
		
		//must add default product
		TEST_METHOD(ReadStatisticsTest)
		{
			map<Product*, int> productMap;
			DataManager service;
			int iter = 0;
			service.saveStatistics(5, 0);
			try
			{
				productMap = service.readStatistics();
				auto it = productMap.begin();
				iter = it->second;
			}
			catch (exception e)
			{
				Assert::Fail();
			}
			Assert::AreEqual(iter, 5);
		}
			
	};
}