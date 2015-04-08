#include <iostream>
#include "Command.h"
#include "CommandHandlers.h"

/*Initialization of commands*/
Command commands[] = 
{
	Command("help", help, "provides you with the list of available commands and their description", Access(GUEST | USER | ADMIN)),
	Command("exit", exit, "exits the program", Access(GUEST | USER | ADMIN)),
	Command("log in", logIn, "performs user authentication", Access::GUEST),
	Command("log out", logOut, "exits user profile", Access(USER | ADMIN)),
	Command("register", createUser, "create your account", Access::GUEST),
	Command("show all users", showUsers, "show the list of all users", Access::ADMIN),
	Command("show cart", showCart, "show all products added to cart", Access(GUEST | USER)),
	Command("change product", changeProduct, "change product settings", Access::ADMIN),
	Command("add to assortment", addToAssortment, "add products to assortment", Access::ADMIN)
};
const int numOfCommands = sizeof(commands) / sizeof(commands[0]);

	/*void changePassword(string);
	void changeEmail(string);
	void changeRole(string);*/