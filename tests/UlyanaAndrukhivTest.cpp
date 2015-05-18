#include "stdafx.h"
#include "CppUnitTest.h"
#include <fstream>
#include <iostream>

#define DLL_IMPORT
#include "UI\CommandHandlers.h"
#include "DataManager\DataManager.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Test
{		
	TEST_CLASS(BuyProduct)
	{
		ifstream fin;
	    	ofstream fout;

		public:
			BuyProduct()
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

			~BuyProduct()
			{
				fin.close();
				fout.close();
			}

			TEST_METHOD(buyOneProductById)
		{
			buyOneElementById();
		}

		TEST_METHOD(buyAllProductsFromCart)
		{
			buyAllProductFromCart();
		}

	};
}
