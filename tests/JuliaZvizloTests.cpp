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

			DataManager manager;
			int test;

			try
			{
				manager.saveUser(user1);
			}
			catch (exception& ex)
			{
				Assert::Fail();
			}

			test = (manager.getUserByLogin("test1", "password"))->getId();
			Assert::AreEqual(1, test);
			manager.removeUserById(1);
		}

		TEST_METHOD(GetUserById)
		{
			User user2("name2", "surname2", Date(5, 5, 1995), "test2", 
				"passd", "test2@test.com", Access::USER, 2);

			DataManager manager;
			manager.saveUser(user2);

			int test;

			try
			{
				test = (manager.getUserById(2))->getId();
			}
			catch (exception& ex)
			{
				Assert::Fail();
			}

			Assert::AreEqual(2, test);
			manager.removeUserById(2);
		}

		TEST_METHOD(GetUserByLogin)
		{
			User user3("name3", "surname3", Date(7, 8, 1997), "test3", 
				"pd", "test3@test.com", Access::USER, 3);

			DataManager manager;
			manager.saveUser(user3);

			int test;

			try
			{
				test = (manager.getUserByLogin("test3", "pd"))->getId();
			}
			catch (exception& ex)
			{
				Assert::Fail();
			}

			Assert::AreEqual(3, test);
			manager.removeUserById(3);
		}

		TEST_METHOD(ReadUsersByPredicate)
		{
			User user1("name1", "surname1", Date(1, 2, 1997), "test1", 
				"password", "test1@test.com", Access::USER, 1);

			DataManager manager;
			manager.saveUser(user1);

			int test;

			auto lambda = [](const User& user)
			{
				return user.getLogin() == "test1";
			};

			try
			{
				test = (manager.readUsers(lambda).popBack())->getId();
			}
			catch (exception& ex)
			{
				Assert::Fail();
			}

			Assert::AreEqual(1, test);
			manager.removeUserById(1);
		}

		TEST_METHOD(ReadAllUsers)
		{
			
			User user5("name5", "surname5", Date(17, 8, 1997), "test5", 
				"passd", "test5@test.com", Access::USER, 5);

			DataManager manager;

			try
			{
				manager.readAllUsers();
			}
			catch (exception& ex)
			{
				Assert::Fail();
			}

			manager.removeUserById(5);
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
				Assert::Fail();
			}

			delete product;
		}

/*		TEST_METHOD(GetAllFromHistory)
		{
			DataManager manager;
			Product *product = new Drink();
			manager.saveToUserHistory(*product, 5);

			double test;

			try
			{
				test = (manager.getAllFromUserStory(5))->getVolume();
			}
			catch (exception& ex)
			{
				Assert::Fail();
			}

			Assert::AreEqual(test, 0.0);
		}*/

		TEST_METHOD(RemoveUsersByPredicate)
		{
			User user1("name1", "surname1", Date(1, 2, 1997), "test1", 
				"password", "test1@test.com", Access::USER, 1);

			DataManager manager;
			manager.saveUser(user1);

			auto lambda = [](const User& user)
			{
				return user.getId() == 1;
			};

			try
			{
				manager.removeUsers(lambda);
			}
			catch (exception & ex)
			{
				Assert::Fail();
			}
		}

		TEST_METHOD(RemoveUsersById)
		{
			User user3("name3", "surname3", Date(7, 8, 1997), "test3", 
				"pd", "test3@test.com", Access::USER, 3);

			DataManager manager;
			manager.saveUser(user3);

			try
			{
				manager.removeUserById(3);
			}
			catch (exception& ex)
			{
				Assert::Fail();
			}
		}
	};
}