#include "stdafx.h"
#include "CppUnitTest.h"

#define DLL_IMPORT

#include "DataManager/DataManager.h"
#include "UI/UI.h"

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
			fin.close();
		}

		TEST_METHOD(WriteInXML)
		{
			manager.exportXML();
			fin.open("Products.txt");
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
			fin.close();
		}
		
		TEST_METHOD(AddNewProductsFromXML)
		{
			fin.open("Products.txt");
			string before;
			while (!fin.eof())
			{
				string line;
				getline(fin, line);
				before += line + '\n';
			}
			fin.close();
			commands[11].execute();
			fin.open("Products.txt");
			string after;
			while (!fin.eof())
			{
				string line;
				getline(fin, line);
				after += line + '\n';
			}
			fin.close();
			Assert::AreNotEqual(before, after);
		}

		TEST_METHOD(AddNewProductsToXML)
		{
			fin.open("Products.xml");
			string before;
			while (!fin.eof())
			{
				string line;
				getline(fin, line);
				before += line + '\n';
			}
			fin.close();
			commands[8].execute();
			fin.open("Products.xml");
			string after;
			while (!fin.eof())
			{
				string line;
				getline(fin, line);
				after += line + '\n';
			}
			fin.close();
			Assert::AreNotEqual(before, after);
		}
	};

	TEST_CLASS(AdminCommandsTests)
	{
		DataManager manager;
	public:
		TEST_METHOD(Register)
		{
			string input = "Name Surname 21 02 1997 login password email";
			stringbuf in(input);
			cin.rdbuf(&in);
			commands[15].execute();
			List<User*> list = manager.readAllUsers();
			Assert::IsTrue(list.popBack()->getLogin() == "login");
		}

		TEST_METHOD(RegisterAdmin)
		{
			List<User*> list = manager.readAllUsers();
			List<User*>::iterator it = list.end();
			int id = (*(--it))->getId();
			while (manager.getUserById(id)->getRole() == ADMIN)
			{
				id--;
			}
			stringbuf in(to_string(id) + " ADMIN");
			cin.rdbuf(&in);
			commands[16].execute();
			Assert::IsTrue(manager.getUserById(id)->getRole() == ADMIN);
		}

		TEST_METHOD(RemoveUser)
		{
			List<User*> list = manager.readAllUsers();
			List<User*>::iterator it = list.end();
			int id = (*(--it))->getId();
			stringbuf in(to_string(id));
			cin.rdbuf(&in);
			commands[17].execute();
			Assert::IsTrue(manager.getUserById(id) == nullptr);
		}
	};
}