#include "stdafx.h"
#include "CppUnitTest.h"

#define DLL_IMPORT

#include "DataManager/DataManager.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace tests
{		
	TEST_CLASS(UserServiceTests)
	{
	public:
		
		TEST_METHOD(SaveUser)
		{
			User user1("name1", "surname1", Date(1, 2, 1997), "test1", 
				"password", "test1@test.com", Access::USER, 1);

			User user2("name2", "surname2", Date(3, 4, 1996), "test2", 
				"pass", "test2@test.com", Access::USER, 2);

			DataManager manager;

			try
			{
				manager.saveUser(user1);
				manager.saveUser(user2);
			}
			catch (exception& ex)
			{
				Logger::WriteMessage(ex.what());
				Assert::Fail();
			}
		}

		TEST_METHOD(GetUserById)
		{
			User user3("name3", "surname3", Date(5, 5, 1995), "test3", 
				"passd", "test3@test.com", Access::USER, 3);

			DataManager manager;

			int test;

			try
			{
				manager.saveUser(user3);
				test = (manager.getUserById(3))->getId();
			}
			catch (exception& ex)
			{
				Logger::WriteMessage(ex.what());
				Assert::Fail();
			}

			Assert::AreEqual(3, test);
		}

		TEST_METHOD(GetUserByLogin)
		{
			User user4("name4", "surname4", Date(7, 8, 1997), "test4", 
				"pd", "test4@test.com", Access::USER, 4);

			DataManager manager;

			int test;

			try
			{
				manager.saveUser(user4);
				test = (manager.getUserByLogin("test4", "pd"))->getId();
			}
			catch (exception& ex)
			{
				Logger::WriteMessage(ex.what());
				Assert::Fail();
			}

			Assert::AreNotEqual(7, test);
		}

		TEST_METHOD(SaveToHistory)
		{
			Product* product = new Food();

			DataManager manager;

			try
			{
				manager.saveToUserHistory(*product, 5);
			}
			catch (exception& ex)
			{
				Logger::WriteMessage(ex.what());
				Assert::Fail();
			}
		}
	};
}