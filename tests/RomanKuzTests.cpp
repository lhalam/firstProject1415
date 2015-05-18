#include "stdafx.h"
#include "CppUnitTest.h"

#define DLL_IMPORT

#include <fstream>
#include <iostream>
#include "Products/Products.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Test
{
	TEST_CLASS(ChemicalProductTests)
	{
	public:
		TEST_METHOD(ElectronicsConstructor)
		{
			Electronics* Test = new Appliance();

			Assert::AreEqual(Test->getName(), string("No name"));
			Assert::AreEqual(Test->getManufacturer(), string("No manufacturer"));
			Assert::AreEqual(Test->getPrice(), 0.0);
			Assert::AreEqual(Test->getId(), 0u);
			Assert::AreEqual(Test->getModel(), string("No model"));
			Assert::AreEqual(Test->getCategory(), string("No category"));
			Assert::AreEqual(Test->getWeight(), 0.0);

		}

		TEST_METHOD(ApplianceConstructor)
		{
			Appliance Mouse;

			Assert::AreEqual(Mouse.getName(), string("No name"));
			Assert::AreEqual(Mouse.getManufacturer(), string("No manufacturer"));
			Assert::AreEqual(Mouse.getPrice(), 0.0);
			Assert::AreEqual(Mouse.getId(), 0u);
			Assert::AreEqual(Mouse.getCategory(), string("No category"));
			Assert::AreEqual(Mouse.getModel(), string("No model"));
			Assert::AreEqual(Mouse.getWeight(), 0.0);

		}
		TEST_METHOD(AudioAndTvConstructor)
		{
			AudioAndTv TV;

			Assert::AreEqual(TV.getName(), string("No name"));
			Assert::AreEqual(TV.getManufacturer(), string("No manufacturer"));
			Assert::AreEqual(TV.getPrice(), 0.0);
			Assert::AreEqual(TV.getId(), 0u);
			Assert::AreEqual(TV.getCategory(), string("No category"));
			Assert::AreEqual(TV.getModel(), string("No model"));
			Assert::AreEqual(TV.getWeight(), 0.0);

		}
		TEST_METHOD(LaptopAndComputerConstructor)
		{
			LaptopAndComputer Laptop;

			Assert::AreEqual(Laptop.getName(), string("No name"));
			Assert::AreEqual(Laptop.getManufacturer(), string("No manufacturer"));
			Assert::AreEqual(Laptop.getPrice(), 0.0);
			Assert::AreEqual(Laptop.getId(), 0u);
			Assert::AreEqual(Laptop.getCategory(), string("No category"));
			Assert::AreEqual(Laptop.getModel(), string("No model"));
			Assert::AreEqual(Laptop.getWeight(), 0.0);
			Assert::AreEqual(Laptop.getFirm(), string(" "));
		}
		TEST_METHOD(PhoneAndTabletConstructor)
		{
			PhoneAndTablet Mobile;

			Assert::AreEqual(Mobile.getName(), string("No name"));
			Assert::AreEqual(Mobile.getManufacturer(), string("No manufacturer"));
			Assert::AreEqual(Mobile.getPrice(), 0.0);
			Assert::AreEqual(Mobile.getId(), 0u);
			Assert::AreEqual(Mobile.getCategory(), string("No category"));
			Assert::AreEqual(Mobile.getModel(), string("No model"));
			Assert::AreEqual(Mobile.getWeight(), 0.0);
			Assert::AreEqual(Mobile.getMemoryCard(), 0);
		}
		TEST_METHOD(PhotoAndVideoCameraConstructor)
		{
			PhotoAndVideoCamera Camera;

			Assert::AreEqual(Camera.getName(), string("No name"));
			Assert::AreEqual(Camera.getManufacturer(), string("No manufacturer"));
			Assert::AreEqual(Camera.getPrice(), 0.0);
			Assert::AreEqual(Camera.getId(), 0u);
			Assert::AreEqual(Camera.getCategory(), string("No category"));
			Assert::AreEqual(Camera.getModel(), string("No model"));
			Assert::AreEqual(Camera.getMegapixels(), 0.0);
		}
		TEST_METHOD(ElectronicsSetData)
		{
			Electronics* Test = new Appliance();
			Test->setName("Mouse");
			Test->setPrice(8.5);
			Test->setManufacturer("Logitec");
			Test->setCategory("ok");
			Test->setId(01u);
			Test->setModel("nice");
			Test->setWeight(0.2);

			Assert::AreEqual(Test->getName(), string("Mouse"));
			Assert::AreEqual(Test->getManufacturer(), string("Logitec"));
			Assert::AreEqual(Test->getPrice(), 8.5);
			Assert::AreEqual(Test->getId(), 01u);
			Assert::AreEqual(Test->getWeight(), 0.2);
			Assert::AreEqual(Test->getModel(), string("nice"));
			Assert::AreEqual(Test->getCategory(), string("ok"));
		}
		TEST_METHOD(ApplianceSetData)
		{
			Appliance Test;
			Test.setName("Mouse");
			Test.setPrice(8.5);
			Test.setManufacturer("Logitec");
			Test.setCategory("ok");
			Test.setId(01u);
			Test.setModel("nice");
			Test.setWeight(0.2);

			Assert::AreEqual(Test.getName(), string("Mouse"));
			Assert::AreEqual(Test.getManufacturer(), string("Logitec"));
			Assert::AreEqual(Test.getPrice(), 8.5);
			Assert::AreEqual(Test.getId(), 01u);
			Assert::AreEqual(Test.getWeight(), 0.2);
			Assert::AreEqual(Test.getModel(), string("nice"));
			Assert::AreEqual(Test.getCategory(), string("ok"));
		}
		TEST_METHOD(AudioAndTvSetData)
		{
			AudioAndTv Test;
			Test.setName("TV");
			Test.setPrice(28.25);
			Test.setManufacturer("LG");
			Test.setCategory("nice");
			Test.setId(02u);
			Test.setModel("ok");
			Test.setWeight(5.0);

			Assert::AreEqual(Test.getName(), string("TV"));
			Assert::AreEqual(Test.getManufacturer(), string("LG"));
			Assert::AreEqual(Test.getPrice(), 28.25);
			Assert::AreEqual(Test.getId(), 02u);
			Assert::AreEqual(Test.getWeight(), 5.0);
			Assert::AreEqual(Test.getModel(), string("ok"));
			Assert::AreEqual(Test.getCategory(), string("nice"));
		}
		TEST_METHOD(LaptopAndComputerSetData)
		{
			LaptopAndComputer Test;
			Test.setName("Laptop");
			Test.setPrice(82.5);
			Test.setManufacturer("China");
			Test.setCategory("ok");
			Test.setId(03u);
			Test.setModel("nice");
			Test.setWeight(2.0);
			Test.setFirm("Asus");

			Assert::AreEqual(Test.getName(), string("Laptop"));
			Assert::AreEqual(Test.getManufacturer(), string("China"));
			Assert::AreEqual(Test.getPrice(), 82.5);
			Assert::AreEqual(Test.getId(), 03u);
			Assert::AreEqual(Test.getWeight(), 2.0);
			Assert::AreEqual(Test.getModel(), string("nice"));
			Assert::AreEqual(Test.getCategory(), string("ok"));
			Assert::AreEqual(Test.getFirm(), string("Asus"));
		}
		TEST_METHOD(PhoneAndTabletSetData)
		{
			PhoneAndTablet Test;
			Test.setName("Mobile");
			Test.setPrice(5.5);
			Test.setManufacturer("Nokia");
			Test.setCategory("ok");
			Test.setId(04u);
			Test.setModel("nice");
			Test.setWeight(0.2);
			Test.setMemoryCard(512);

			Assert::AreEqual(Test.getName(), string("Mobile"));
			Assert::AreEqual(Test.getManufacturer(), string("Nokia"));
			Assert::AreEqual(Test.getPrice(), 5.5);
			Assert::AreEqual(Test.getId(), 04u);
			Assert::AreEqual(Test.getWeight(), 0.2);
			Assert::AreEqual(Test.getModel(), string("nice"));
			Assert::AreEqual(Test.getCategory(), string("ok"));
			Assert::AreEqual(Test.getMemoryCard(), 512);
		}
		TEST_METHOD(PhotoAndVideoCameraSetData)
		{
			Appliance Test;
			Test.setName("Camera");
			Test.setPrice(8.0);
			Test.setManufacturer("Canon");
			Test.setCategory("nice");
			Test.setId(05u);
			Test.setModel("ok");
			Test.setWeight(0.8);

			Assert::AreEqual(Test.getName(), string("Camera"));
			Assert::AreEqual(Test.getManufacturer(), string("Canon"));
			Assert::AreEqual(Test.getPrice(), 8.0);
			Assert::AreEqual(Test.getId(), 05u);
			Assert::AreEqual(Test.getWeight(), 0.8);
			Assert::AreEqual(Test.getModel(), string("ok"));
			Assert::AreEqual(Test.getCategory(), string("nice"));
		}

	};
}