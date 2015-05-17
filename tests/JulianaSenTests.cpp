#include "stdafx.h"
#include "CppUnitTest.h"
#include <iostream>
#include <fstream>

#define DLL_IMPORT

#include "UI/CommandHandlers.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace JulianaSenTests
{		
	TEST_CLASS(ProductTest)
	{
		ifstream fin;
		ofstream fout;

	public:
		ProductTest()
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

		~ProductTest()
		{
			fin.close();
			fout.close();
		}

		TEST_METHOD(AddNewProduct)
		{
			addNewProduct();
		}

		TEST_METHOD(ChangeAmount)
		{
			changeAmount();
		}

		TEST_METHOD(ChangeProduct)
		{
			changeProduct();
		}

	};
}
