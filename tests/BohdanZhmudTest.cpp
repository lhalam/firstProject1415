#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest9
{		
	//List testing
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(size_isEmpty)
		{
			List<int> list;
			for (int i = 0; i < 100; i++)
			{
				if (i % 2)
				{
					list.pushFront(i);
				}
				else
				{
					list.pushBack(i);
				}
				Assert::AreEqual(i+1, list.size());
			}

			int i = 99;
			while (!list.isEmpty())
			{
				if (i % 2)
				{
					list.popBack();
				}
				else
				{
					list.popFront();
				}
				Assert::AreEqual(i--, list.size());
			}
		}

		TEST_METHOD(PushFront)
		{
			List<int> list;
			for (int i = 0; i < 100; i++)
			{
				list.pushFront(i);
			}
			int j = 99;
			for (List<int>::iterator i = list.begin(); i != list.end(); i++, j--)
			{
				Assert::AreEqual(*i, j);
			}
		}

		TEST_METHOD(PushBack)
		{
			List<int> list;
			for (int i = 0; i < 100; i++)
			{
				list.pushBack(i);
			}
			int j = 0;
			for (List<int>::iterator i = list.begin(); i != list.end(); i++, j++)
			{
				Assert::AreEqual(*i, j);
			}
		}

		TEST_METHOD(PushBack_PushFront_PopBack_PopFront)
		{
			List<int> list;
			for (int i = 0; i < 100; i++)
			{
				list.pushBack(i);
				list.pushFront(i);
			}
			
			while (!list.isEmpty())
			{
				Assert::AreEqual(list.popFront(), list.popBack());
			}
		}

		TEST_METHOD(PopBack)
		{
			List<int> list;
			for (int i = 0; i < 100; i++)
			{
				list.pushFront(i);
			}

			for (int i = 0; i < 100; i++)
			{
				Assert::AreEqual(list.popBack(), i);
			}
			
		}

		TEST_METHOD(PopFront)
		{
			List<int> list;
			for (int i = 0; i < 100; i++)
			{
				list.pushBack(i);
			}

			for (int i = 0; i < 100; i++)
			{
				Assert::AreEqual(list.popFront(), i);
			}

		}

		TEST_METHOD(find)
		{
			List<int> list;
			for (int i = 0; i < 100; i++)
			{
				list.pushBack(i);
			}

			for (int i = 0; i < 100; i++)
			{
				Assert::AreEqual(*list.find(i, list.begin(), list.end()), i);
			}

		}

		TEST_METHOD(erase)
		{
			List<int> list;
			for (int i = 0; i < 100; i++)
			{
				list.pushBack(i);
			}

			for (int i = 0; i < 100; i++)
			{
				if (i % 2)
				{
					list.erase(list.find(i, list.begin(), list.end()));
				}
			}

			for (int i = 0; i < 100; i+=2)
			{
				Assert::AreEqual(*list.find(i, list.begin(), list.end()), i);
			}
				
		}

	};
}