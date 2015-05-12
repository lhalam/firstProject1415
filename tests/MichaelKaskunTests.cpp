#include "stdafx.h"
#include "CppUnitTest.h"

#define DLL_IMPORT

#include "User\User.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void memoryCheck(void(*)());
void userTest1();
void userTest2();

namespace MichaelKaskunTests
{		
	TEST_CLASS(UserTests)
	{
	public:

		TEST_METHOD(CreateUser1)
		{
			memoryCheck(userTest1);
		}

		TEST_METHOD(CreateUser2)
		{
			memoryCheck(userTest2);
		}

	};
}

void memoryCheck(void(*f)())
{
	try
	{
		_CrtMemState before, after, difference;
		_CrtMemCheckpoint(&before);
		(*f)();
		_CrtMemCheckpoint(&after);
		if (_CrtMemDifference(&difference, &after, &before))
		{
			throw std::exception("Something wrong with memory");
		}
	}
	catch (std::exception& err)
	{
		Logger::WriteMessage(err.what());
		Assert::Fail();
	}
	catch (...)
	{
		Logger::WriteMessage("Unknown error");
		Assert::Fail();
	}
}

void userTest1()
{
	User usr;
	usr.changePassword("pass");
	usr.changeEmail("email");
	usr.setRole(ADMIN);
	Assert::AreEqual(usr.getPassword(), string("pass"));
	Assert::AreEqual(usr.getEmail(), string("email"));
	Assert::AreEqual((int)usr.getRole(), (int)ADMIN);
}

void userTest2()
{
	User usr
		("name",
		"surname",
		Date(21, 02, 1997),
		"login",
		"pass",
		"email",
		ADMIN,
		1);

	Assert::AreEqual(usr.getLogin(), string("login"));
	Assert::AreEqual(usr.getPassword(), string("pass"));
	Assert::AreEqual(usr.getEmail(), string("email"));
	Assert::AreEqual((int)usr.getRole(), (int)ADMIN);
	Assert::AreEqual(usr.getId(), 1);
}