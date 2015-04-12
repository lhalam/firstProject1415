#include "CommandHandlers.h"
#include "../DataManager/DataManager.h"
#include "Globals.h"
#include "../Products/Product.h"

/*Command executors listed alphabetically*/

Result addToAssortment()
{
	int id;
	cout << Message("Enter id", CONTEXT_MSG);
	cin >> id;

	int quantity;
	cout << Message("Enter new quantity", CONTEXT_MSG);
	cin >> quantity;

	DataManager manager;
	manager.setQuantity(id, quantity);

	return Result("Product is added to asortment.", SUCCESSFUL);
}

Result changeProduct()
{
	int id = 0;
	cout << Message("Enter id", CONTEXT_MSG);
	cin >> id;

	DataManager manager;
	Product *prod = manager.getProductById(id);
	int quantity = manager.getQuantity(id);

	prod->input();

	manager.removeProductById(id);
	manager.saveProduct(*prod);
	manager.setQuantity(id, quantity);

	delete[] prod;
	return Result("Product is changed.", SUCCESSFUL);
}

Result createAdmin()
{
	int id;
	cout << Message("Enter id of the account", CONTEXT_MSG);
	cin >> id;

	DataManager manager;
	User *user = nullptr;

	try
	{
		user = manager.getUserById(id);
	} catch (exception exp)
	{
		cin.get();
		return Result(exp.what(), NOT_SUCCESSFUL);
	}

	if (user == nullptr)
	{
		cin.get();
		return Result("The id is invalid. Please try again.", NOT_SUCCESSFUL);
	}

	if (user->getRole() == Access::ADMIN)
	{
		return Result("The account already has administrator rights.", SUCCESSFUL);
	}

	user->properties->setRole(Access::ADMIN);

	return Result("The account was granted administrator rights.", SUCCESSFUL);
}

Result createUser()
{
	using std::cin;
	User newUser;
	cin >> newUser;
	DataManager manager;
	manager.saveUser(newUser);

	return Result("Your account was successfully created\nWelcome, ", SUCCESSFUL);
}

Result exit()
{
	return Result(EXIT);
}

Result help()
{
	for (int i = 0; i < numOfCommands; i++)
	{
		if (currentUser.getRole() & commands[i].getAccessLevel())
			cout << Message("[" + commands[i].getName() + "] - " + commands[i].getDescription(), LOG_MSG);
	}
	return Result();
}

Result logIn()
{
	using std::cin;

	cout << Message("Name", CONTEXT_MSG);
	string name;
	getline(cin, name, '\n');
	cout << Message("Password", CONTEXT_MSG);
	string password;
	getline(cin, password, '\n');

	/* Checking the database */
	bool correct = true;

	if (correct)
	{
		/* Writing user data into global variable 'User'*/
		return Result("Authentication successful\nWelcome, " + name + "!", SUCCESSFUL);
	}
	else
	{
		return Result("Authentication failed\nPlease, check your name, password and try again", NOT_SUCCESSFUL);
	}
}

Result logOut()
{
	/*Deletes data of global variable User*/
	return Result("You logged out successfully.", SUCCESSFUL);
}

Result removeProductFromCart()
{
	if(cart.begin() == cart.end())
	{
		return Result("Your cart is empty.", NOT_SUCCESSFUL);
	}

	else if(cart.begin()++ == cart.end())
	{
		cout << Message("You currently have one product in your cart.", CONTEXT_MSG)
			 << Message("Are you sure you want to remove this product? (y/n)", CONTEXT_MSG);

		char answer;
		cin >> answer;
		while(answer != 'y' && answer != 'n')
		{
			cout << Message("You may have misunderstood me.", CONTEXT_MSG);
			cout << Message("Are you sure you want to remove this product? (y/n)", CONTEXT_MSG);
			cin >> answer;
		}
		try
		{
			switch(answer)
			{
			case 'y': 
				cart.erase(cart.begin()); 
				return Result("Operation successful.", SUCCESSFUL);
			case 'n': 
				return Result("Operation cancelled.", SUCCESSFUL);
			}
		}
		catch(exception exc)
		{
			return Result(exc.what(), NOT_SUCCESSFUL);
		}
	}

	cout << Message("You currently have " + to_string(cart.size()) + " products in your cart.", CONTEXT_MSG)
		 << Message("Which product would you like to remove from your cart?", INPUT_MSG)
		 << Message("Input ID:", INPUT_MSG);
	int ID;
	cin >> ID;

	cout << Message("Are you sure you want to remove this product? (y/n)", CONTEXT_MSG);
	char answer;
	cin >> answer;
	int stupidityCount = 0;
	while(answer != 'y' && answer != 'n')
	{
		stupidityCount++;
		if(stupidityCount >= 3)
		{
			cout << Message("You aren't smart, are you?..", ALERT_MSG);
		}
		else
		{
			cout << Message("You may have misunderstood me.", CONTEXT_MSG);
		}
		cout << Message("Are you sure you want to remove this product? (y/n)", CONTEXT_MSG);
		cin >> answer;
	}
	try
	{
		switch(answer)
		{
		case 'y': 
			DataManager manager;
			cart.erase(cart.find(manager.getProductById(ID), cart.begin(), cart.end()));
			return Result("Operation successful.", SUCCESSFUL);
		case 'n': 
			return Result("Operation cancelled.", SUCCESSFUL);
		}
	}
	catch(exception exc)
	{
		return Result(exc.what(), NOT_SUCCESSFUL);
	}
}

Result removeUser()
{
	int id = 0;
	cout << Message("Enter id of the account", CONTEXT_MSG);
	cin >> id;

	if (id == currentUser.getId())
	{
		return Result("You cannot delete yourself.", SUCCESSFUL);
	}

	DataManager manager;

	try
	{
		manager.removeUserById(id);
	} catch (exception exp)
	{
		cin.get();
		return Result(exp.what(), NOT_SUCCESSFUL);
	}

	return Result("The user was deleted successfully.", SUCCESSFUL);
}

Result showCart()
{
	if(cart.begin() == cart.end())
	{
		cout << Message("Your cart is empty.", INPUT_MSG);
		return Result(SUCCESSFUL);
	}

	List<Product*>::iterator end = cart.end();
	for (List<Product*>::iterator iterator = cart.begin(); iterator != end; iterator++)
	{
		cout << *iterator;
	}
	return Result("Listing completed.", SUCCESSFUL);
}

Result showProducts()
{
	List<Product*> allProducts = DataManager().readAllProducts();
	List<Product*>::iterator end = allProducts.end();
	for (List<Product*>::iterator it = allProducts.begin();
		it != end;
		it++)
	{
		cout << Message(
			"#" + to_string((*it)->getId()) + ": " + (*it)->getName() + " " + (*it)->getManufacturer() + " price: " + to_string((*it)->getPrice())
			, LOG_MSG) << endl;
	}
	return Result("Listing completed.", SUCCESSFUL);
}

Result showStats()
{

}

Result showUsers()
{
	DataManager manager;
	List<User*> list = manager.readAllUsers();
	List<User*>::iterator iter = list.begin();

	while(iter != list.end())
	{
		int temp = 0;
		cout << (*iter);
		temp ++;
		iter ++;

		if((temp % 5) == 0)
		{
			cout << Message("Press Enter to continue... ", LOG_MSG);
			cin.get();
		}
	}

	return Result("Listing completed.", SUCCESSFUL);
}

Result buyOneElementById()
{
	cout << Message("Enter product id", LOG_MSG);
	int id;
	cin >> id;
	cout << Message("You bought : ", LOG_MSG);
	cout << ProductService().getById(id);
	return Result("thank you for buying " ,SUCCESSFUL);
}

