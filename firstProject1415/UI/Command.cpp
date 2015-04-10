#include <iostream>
#include "Command.h"
#include "CommandHandlers.h"

/*Initialization of commands; commands are listed alphabetically*/
Command commands[] = 
{
	Command("add to assortment", addToAssortment, "adds products to the assortment", Access::ADMIN),
	Command("change product", changeProduct, "change product settings", Access::ADMIN),
	Command("exit", exit, "exits the program", Access(GUEST | USER | ADMIN)),
	Command("help", help, "provides you with the list of available commands and their description", Access(GUEST | USER | ADMIN)),
	Command("log in", logIn, "performs user authentication", Access::GUEST),
	Command("log out", logOut, "exits user profile", Access(USER | ADMIN)),
	Command("register", createUser, "creates a new account", Access(GUEST | ADMIN)),
	Command("register admin", createAdmin, "makes a normal user an administrator", Access::ADMIN),
	Command("remove user", removeUser, "deletes a specified user account", Access::ADMIN),
	Command("show all products", showProducts, "shows the list of all products", Access(GUEST | USER | ADMIN)),
	Command("show all users", showUsers, "shows the list of all users", Access::ADMIN),
	Command("show cart", showCart, "shows all products added to cart", Access(GUEST | USER)),
};

const int numOfCommands = sizeof(commands) / sizeof(commands[0]);

	/*void changePassword(string);
	void changeEmail(string);
	void changeRole(string);*/
