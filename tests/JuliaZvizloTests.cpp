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

			try
			{
				manager.saveUser(user1);
			}
			catch (exception& ex)
			{
				Assert::Fail();
			}
		}

		TEST_METHOD(GetUserById)
		{
			User user2("name2", "surname2", Date(5, 5, 1995), "test2", 
				"passd", "test2@test.com", Access::USER, 2);

			DataManager manager;

			int test;

			try
			{
				manager.saveUser(user2);
				test = (manager.getUserById(2))->getId();
			}
			catch (exception& ex)
			{
				Assert::Fail();
			}

			Assert::AreEqual(2, test);
		}

		TEST_METHOD(GetUserByLogin)
		{
			User user3("name3", "surname3", Date(7, 8, 1997), "test3", 
				"pd", "test3@test.com", Access::USER, 3);

			DataManager manager;
			
			int test;

			try
			{
				manager.saveUser(user3);
				test = (manager.getUserByLogin("test3", "pd"))->getId();
			}
			catch (exception& ex)
			{
				Assert::Fail();
			}

			Assert::AreEqual(3, test);
		}

		TEST_METHOD(ReadUsersByPredicate)
		{
			DataManager manager;

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
		}

		TEST_METHOD(ReadAllUsers)
		{
			DataManager manager;

			try
			{
				manager.readAllUsers();
			}
			catch (exception& ex)
			{
				Assert::Fail();
			}
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
		}

		TEST_METHOD(GetAllFromHistory)
		{
			DataManager manager;

			try
			{
				manager.getAllFromUserStory(5);
			}
			catch (exception& ex)
			{
				Assert::Fail();
			}
		}

		TEST_METHOD(RemoveUsersByPredicate)
		{
			DataManager manager;

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
			DataManager manager;

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