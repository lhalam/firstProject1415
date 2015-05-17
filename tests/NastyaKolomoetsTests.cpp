#include "stdafx.h"
#include "CppUnitTest.h"

#define DLL_IMPORT
#include "UI/UI.h"
#include "DataManager\DataManager.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NastyaKolomoetsTests
{		
	TEST_CLASS(CommandHandlersTests)
	{
	public:
		
		TEST_METHOD(RemoveProductFromAssortmentTest)
		{
			int id = 3;
			string inputId = to_string(id) + "\n";
			stringbuf in(inputId);
			cin.rdbuf(&in);
			DataManager manager;
			try
			{
				commands[18].execute();
			}
			catch (...)
			{
				Assert::Fail();
			}
			Assert::AreEqual(-1, manager.getQuantity(id));
			Assert::AreEqual(to_string(commands[18].execute().getId()), to_string(SUCCESSFUL));
		}

		TEST_METHOD(ShowUsersTest)
		{
			Assert::AreEqual(to_string(commands[21].execute().getId()), to_string(SUCCESSFUL));
		}

		TEST_METHOD(ShowStatsTest)
		{
			Assert::AreEqual(to_string(commands[24].execute().getId()), to_string(SUCCESSFUL));
		}
	};
}
