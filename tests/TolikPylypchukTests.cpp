#include "stdafx.h"
#include "CppUnitTest.h"

#define DLL_IMPORT

#include "DataManager/DataManager.h"
#include "UI/UI.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace TolikPylypchukTests
{
	TEST_CLASS(HTMLServiceTests)
	{
		ifstream fin;
		ofstream fout;

	public:
		HTMLServiceTests()
		{
			fin.open("input.txt");
			if (!fin.is_open())
			{
				exit(EXIT_FAILURE);
			}

			filebuf *in = fin.rdbuf();
			cin.rdbuf(in);

			fout.open("output.txt");
			if (!fin.is_open())
			{
				exit(EXIT_FAILURE);
			}

			filebuf *out = fout.rdbuf();
			cout.rdbuf(out);
		}

		~HTMLServiceTests()
		{
			fin.close();
			fout.close();
		}
		
		TEST_METHOD(WriteTest)
		{
			currentUser = User("testname", "testsurname", Date(1, 1, 2000),
				"test", "pass", "test@test.com", Access::USER, 4);

			DataManager manager;
			manager.writeInHTML(currentUser.getId(), Date(), Date());

			//I have no idea what to check here
			//I guess I just have to have a look on the file myself after the test
		}
	};
}