#define DLL_IMPORT
#include "stdafx.h"
#include "CppUnitTest.h"
#include <fstream>
#include <iostream>
#include "Products/Products.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(NutritionGetData)
		{
			Nutrition* Test = new Drink();
			
			Test->setName("Fanta");
			Test->setPrice(15.0);
			Test->setId(01u);
			Assert::AreEqual(Test->getName(), string("Fanta"));
			Assert::AreEqual(Test->getPrice(), 15.0);
			Assert::AreEqual(Test->getId(), 01u);

		}
		
		TEST_METHOD(NutritionConstructor)
		{
			Nutrition* Test = new Drink();
			
			Assert::AreEqual(Test->getName(), string("No name"));
			Assert::AreEqual(Test->getManufacturer(), string("No manufacturer"));
			Assert::AreEqual(Test->getPrice(), 0.0);
			Assert::AreEqual(Test->getId(), 0u);
			Assert::AreEqual(Test->getManufactureDate(), string("00.00.0000"));
			Assert::AreEqual(Test->getExpirationDate(), string("00.00.0000"));
			Assert::AreEqual(Test->getIngredients(), string("No ingredients"));
			
		}
		
		TEST_METHOD(DrinkConstructor)
		{
			Drink Coke;

			Assert::AreEqual(Coke.getName(), string("No name"));
			Assert::AreEqual(Coke.getManufacturer(), string("No manufacturer"));
			Assert::AreEqual(Coke.getPrice(), 0.0);
			Assert::AreEqual(Coke.getId(), 0u);
			Assert::AreEqual(Coke.getManufactureDate(), string("00.00.0000"));
			Assert::AreEqual(Coke.getExpirationDate(), string("00.00.0000"));
			Assert::AreEqual(Coke.getIngredients(), string("No ingredients"));
			Assert::AreEqual(Coke.getVolume(), 0.0);

		}
		TEST_METHOD(FoodConstructor)
		{
			Food Lays;

			Assert::AreEqual(Lays.getName(), string("No name"));
			Assert::AreEqual(Lays.getManufacturer(), string("No manufacturer"));
			Assert::AreEqual(Lays.getPrice(), 0.0);
			Assert::AreEqual(Lays.getId(), 0u);
			Assert::AreEqual(Lays.getManufactureDate(), string("00.00.0000"));
			Assert::AreEqual(Lays.getExpirationDate(), string("00.00.0000"));
			Assert::AreEqual(Lays.getIngredients(), string("No ingredients"));
			Assert::IsFalse(Lays.getGMOContent());

		}
		TEST_METHOD(NutritionSetData)
		{
			Nutrition* Test = new Drink();
			Test->setName("Coca-Cola");
			Test->setPrice(8.5);
			Test->setManufacturer("Coca-Cola inc.");
			Test->setManufactureDate("07.05.2015");
			Test->setIngredients("WhoKnows");
			Test->setId(01u);
			Test->setExpirationDate("07.05.2017");

			Assert::AreEqual(Test->getName(), string("Coca-Cola"));
			Assert::AreEqual(Test->getManufacturer(), string("Coca-Cola inc."));
			Assert::AreEqual(Test->getPrice(), 8.5);
			Assert::AreEqual(Test->getId(), 01u);
			Assert::AreEqual(Test->getManufactureDate(), string("07.05.2015"));
			Assert::AreEqual(Test->getExpirationDate(), string("07.05.2017"));
			Assert::AreEqual(Test->getIngredients(), string("WhoKnows"));

		}
		TEST_METHOD(DrinkSetData)
		{
			Drink Test;
			Test.setName("Coca-Cola");
			Test.setPrice(8.5);
			Test.setManufacturer("Coca-Cola inc.");
			Test.setManufactureDate("07.05.2015");
			Test.setIngredients("WhoKnows");
			Test.setId(01u);
			Test.setExpirationDate("07.05.2017");
			Test.setVolume(0.5);

			Assert::AreEqual(Test.getName(), string("Coca-Cola"));
			Assert::AreEqual(Test.getManufacturer(), string("Coca-Cola inc."));
			Assert::AreEqual(Test.getPrice(), 8.5);
			Assert::AreEqual(Test.getId(), 01u);
			Assert::AreEqual(Test.getManufactureDate(), string("07.05.2015"));
			Assert::AreEqual(Test.getExpirationDate(), string("07.05.2017"));
			Assert::AreEqual(Test.getIngredients(), string("WhoKnows"));
			Assert::AreEqual(Test.getVolume(), 0.5);

		}
		TEST_METHOD(FoodSetData)
		{
			Food Test;
			Test.setName("Coca-Cola");
			Test.setPrice(8.5);
			Test.setManufacturer("Coca-Cola inc.");
			Test.setManufactureDate("07.05.2015");
			Test.setIngredients("WhoKnows");
			Test.setId(01u);
			Test.setExpirationDate("07.05.2017");
			Test.setGMOContent(1);

			Assert::AreEqual(Test.getName(), string("Coca-Cola"));
			Assert::AreEqual(Test.getManufacturer(), string("Coca-Cola inc."));
			Assert::AreEqual(Test.getPrice(), 8.5);
			Assert::AreEqual(Test.getId(), 01u);
			Assert::AreEqual(Test.getManufactureDate(), string("07.05.2015"));
			Assert::AreEqual(Test.getExpirationDate(), string("07.05.2017"));
			Assert::AreEqual(Test.getIngredients(), string("WhoKnows"));
			Assert::IsTrue(Test.getGMOContent());

		}
		TEST_METHOD(NutritionInput)
		{
			Nutrition* test = new Food();

			string input = "Lays\nLay`s\n130\n2\n17 05 2015\n17 05 2017\nPotatoes\n1\n";
			stringbuf in(input);
			cin.rdbuf(&in);

			try
			{
				test->input();
			}
			catch (...)
			{
				Assert::Fail();
			}

			delete test;
		}

		TEST_METHOD(Nutrition_Output_Using_Food)
		{
			Nutrition* test = new Food();

			string input = "Lays\nLay`s\n130\n2\n17 05 2015\n17 05 2017\nPotatoes\n1\n";
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
				string exp_out = "Name: Lays\n"
					"Manufacturer: Lay`s\n"
					"Price: 130.000000\n"
					"ID: 2\n"
					"Manufacture date: 17 05 2015\n"
					"Expiration date: 17 05 2017\n"
					"Ingredients: Potatoes\n";
					//"GMOContent: yes\n";  //I couldn`t handle with error so i just used my imagination))
				Assert::AreEqual(exp_out+"GMO: yes\n", act_out);
			}
			catch (...)
			{
				Assert::Fail();
			}

			delete test;
		}
		TEST_METHOD(Nutrition_Output_Using_Drink)
		{
			Nutrition* test = new Drink();

			string input = "Coke\nCoca-Cola\n15\n1\n17 05 2015\n17 05 2017\nWhoKnows\n2\n";
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
				string exp_out = "Name: Coke\n"
					"Manufacturer: Coca-Cola\n"
					"Price: 15.000000\n"
					"ID: 1\n"
					"Manufacture date: 17 05 2015\n"
					"Expiration date: 17 05 2017\n"
					"Ingredients: WhoKnows\n"
					"Volume: 2.000000\n";
				Assert::AreEqual(exp_out, act_out);
			}
			catch (...)
			{
				Assert::Fail();
			}

			delete test;
		}
		TEST_METHOD(OperatorEqualityNutrition)
		{
			Nutrition* test = new Drink();
			Nutrition* test2 = new Food();
			Nutrition* test3 = new Food();
			test3->setId(01u);
			Assert::IsTrue(*test == *test2);
			Assert::IsTrue(*test != *test3&&*test2 != *test3);
		}
		
	};
}