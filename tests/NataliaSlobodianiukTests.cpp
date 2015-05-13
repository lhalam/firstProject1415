#include "stdafx.h"
#include "CppUnitTest.h"

#define DLL_IMPORT

#include "DataManager\DataManager.h"
#include "UI\UI.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NataliaSlobodianiukTests
{		
	TEST_CLASS(XMLTests)
	{
		ifstream fin;
		ofstream fout;
		DataManager manager;
	public:
		
		TEST_METHOD(ReadFromXML)
		{
			List<Product*> list = manager.readFromXML();
			fin.open("Products.xml");
			if (!fin.eof())
			{
				Assert::IsNotNull(list.popBack());
			}
			else
			{
				try
				{
					list.popBack();
				}
				catch (exception & x)
				{
					Assert::AreEqual(x.what(), "List is empty.");
				}
			}
		}

		TEST_METHOD(WriteInXML)
		{
			fin.open("Products.txt");
			manager.exportXML();
			List<Product*> list = manager.readFromXML();
			if (!fin.eof())
			{
				Assert::IsNotNull(list.popBack());
			}
			else
			{
				try
				{
					list.popBack();
				}
				catch (exception & x)
				{
					Assert::AreEqual(x.what(), "List is empty.");
				}
			}
		}

	/*	TEST_METHOD(AddNewProductsFromXML)
		{
			fin.open("Product.txt");
			string before;
			while (!fin.eof())
			{
				string line;
				getline(fin, line);
				before = line + '\n';
			}
			fin.close();
			commands[11].execute();
			fin.open("Product.txt");
			string after;
			while (!fin.eof())
			{
				string line;
				getline(fin, line);
				after = line + '\n';
			}
			fin.close();
			Assert::AreNotEqual(before, after);
		} */
	};
}