#include "stdafx.h"
#include "CppUnitTest.h"
#define DLL_IMPORT
#include "DataManager/DataManager.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PruductServiceTest
{		
	TEST_CLASS(PruductServiceTest)
	{
	public:

		TEST_METHOD(SaveAllTest)
		{
			DataManager service;
			Product *prod1 = new Appliance();

			List<Product*> list;
			list.pushBack(prod1);

			service.saveAllProducts(list);
			int id = 0;
			try
			{
				id = ((service.readAllProducts()).popBack())->getId();
			}
			catch (exception e)
			{
				Assert::Fail();//AreEqual(e.what(),"Cannot open file for writing.");
			}
			Assert::AreEqual(id, 0);
		}
		
		TEST_METHOD(GetQuantityTest)
		{
			DataManager service;
			int test = 0;
			try
			{
				test = service.getQuantity(0);
			}
			catch (...)
			{
				Assert::Fail();
			}
			Assert::AreEqual(test, 0);
		}
		
		TEST_METHOD(ReadTest)
		{
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
			DataManager service;
			int test = 0;
			try
			{
				test = service.getQuantity(0);
				service.changeQuantity(0,0);
				test = service.getQuantity(0);
			}
			catch (exception e)
			{
				Assert::Fail();
			}
			Assert::AreEqual(test, 0);
		}
				
		TEST_METHOD(GetByIdTest)
		{
			DataManager service;
			double test = 0;
			try
			{
				test = (service.getProductById(0))->getPrice();
			}
			catch (exception e)
			{
				Assert::Fail();
			}
			
			Assert::AreEqual(test, 0.0);
		}
				
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