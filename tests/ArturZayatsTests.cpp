#define DLL_IMPORT

#include "stdafx.h"
#include "CppUnitTest.h"
#include <fstream>
#include "UI/CommandHandlers.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace ForTests
{		
	TEST_CLASS(UITests)
	{
		ifstream fin;
		ofstream fout;
	public:
		UITests()
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
		~UITests()
		{
			fin.close();
			fout.close();
		}

		TEST_METHOD(TestExit)
		{
			exit();
		}
		TEST_METHOD(TestShowCart)
		{
			showCart();
		}
		TEST_METHOD(TestLogIn)
		{
			logIn();
		}
	};
}
