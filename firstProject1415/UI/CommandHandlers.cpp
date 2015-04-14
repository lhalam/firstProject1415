#include "CommandHandlers.h"
#include "../DataManager/DataManager.h"
#include "Globals.h"
#include "../Products/Product.h"

/*Command executors listed alphabetically*/

Result changeAmount()
{
	int id;
	cout << Message("Enter id", CONTEXT_MSG);
	cin >> id;

	DataManager manager;
	manager.setQuantity(id);

	return Result("New quantity is added to assortment.", SUCCESSFUL);
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
	newUser.input();
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
	
	DataManager dataManager;
	User* existingUser = dataManager.getUserByLogin(name, password);
	
	if (existingUser == nullptr) //User with this login exists
	{
		return Result("Authentication failed\nPlease, check your name, password and try again", NOT_SUCCESSFUL);
	}
	else
	{
		cout << Message("Authentication successful\nWelcome, " + name + "!", LOG_MSG);
	}
	return Result();
}

Result logOut()
{
	currentUser = User();

	cout << Message("You logged out successfully.", LOG_MSG);
	return Result();
}

Result removeProductFromCart()
{
	int ID;
	bool option;

	if(cart.size() == 0)
	{
		cout << Message("Your cart is empty.", LOG_MSG);
		return Result();
	}
	else if(cart.size() == 1)
	{
		option = true;
		cout << Message("You currently have one product in your cart.", CONTEXT_MSG);
	}
	else
	{
		option = false;
		cout << Message("You currently have " + to_string(cart.size()) + " products in your cart.", CONTEXT_MSG)
			 << Message("Which product would you like to remove from your cart?", CONTEXT_MSG)
			 << Message("Input ID:", CONTEXT_MSG);
		cin >> ID;
	}

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
			cout << Message("You may have misunderstood me.", LOG_MSG);
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
			cart.erase(option ? cart.begin() : cart.find(manager.getProductById(ID), cart.begin(), cart.end()));
			return Result("Operation successful.", SUCCESSFUL);
			break;
		case 'n': 
			return Result("Operation cancelled.", SUCCESSFUL);
			break;
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
		cout << Message("Your cart is empty.", CONTEXT_MSG);
		return Result(SUCCESSFUL);
	}

	List<Product*>::iterator end = cart.end();
	for (List<Product*>::iterator iterator = cart.begin(); iterator != end; iterator++)
	{
		cout << *iterator;
	}
	return Result();
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
	return Result();
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
	cout << Message("Enter product id", CONTEXT_MSG);
	int id;
	cin >> id;
	cout << Message("You bought: ", LOG_MSG);
	cout << DataManager().getProductById(id);
	DataManager().removeProductById(id);
	return Result("Thank you for buying " ,SUCCESSFUL);
}

Result showPurchaseHistory()
{
	DataManager dataManager;
	List<Product*> products = dataManager.readAllProducts();
	List<Product*>::iterator cursor = products.begin();

	while (cursor != products.end())
	{
		Product* product = *cursor;
		cout << Message(product->getName(), LOG_MSG);
		cursor++;
	}

	return Result();
}
Result buyAllProductFromCart()
{
	if (cart.size() == 0)
	{
		return Result("Your cart is empty.", SUCCESSFUL);
	}
	else 
	{
		List<Product*> allProducts = DataManager().readAllProducts();
		List<Product*>::iterator end = allProducts.end();
		for (List<Product*>::iterator it = allProducts.begin(); it != end; it++)
		{
			cout << Message("You bought : " + to_string((*it)->getId()) + " : " + (*it)->getName() + " " + " price: " + to_string((*it)->getPrice()), LOG_MSG) << endl;
			
		}
	}
	return Result("You bought all products.", SUCCESSFUL);
}
