#include <iostream>
#include "Command.h"
#include "CommandHandlers.h"

/*Initialization of commands; commands are listed alphabetically*/
Command commands[] = 
{ 
	Command("add product", addNewProduct, "adds new product", Access::ADMIN),
	Command("buy", buyOneElementById, "buys product by id", Access::USER),
	Command("buy all products", buyAllProductFromCart, "buys all product from cart", Access::USER),
	Command("change amount", changeAmount, "changes amount of products", Access::ADMIN),
	Command("change product", changeProduct, "changes product settings", Access::ADMIN),
	Command("exit", exit, "exits the program", Access(GUEST | USER | ADMIN)),
	Command("help", help, "provides you with the list of available commands and their description", Access(GUEST | USER | ADMIN)),
	Command("log in", logIn, "performs user authentication", Access::GUEST),
	Command("log out", logOut, "exits user profile", Access(USER | ADMIN)),
	Command("register", createUser, "creates a new account", Access(GUEST | ADMIN)),
	Command("register admin", createAdmin, "makes a normal user an administrator", Access::ADMIN),
	Command("remove user", removeUser, "deletes a specified user account", Access::ADMIN),
	Command("remove product from assortment", removeProductFromAssortment, "removes the product from assortment", Access::ADMIN),
	Command("remove product from cart", removeProductFromCart, "deletes a product from your cart", Access(GUEST | USER)),
	Command("show all products", showProducts, "shows the list of all products", Access(GUEST | USER | ADMIN)),
	Command("show all users", showUsers, "shows the list of all users", Access::ADMIN),
	Command("show cart", showCart, "shows all products added to cart", Access(GUEST | USER)),
	Command("show purchase history", showPurchaseHistory, "shows the history of the purchases of the user", Access(USER | ADMIN)),
	Command("show stats", showStats, "shows the statistics of all bought products", Access::ADMIN),
	Command("add product to cart", addProductToCart ,"add product to cart by id ", Access(GUEST | USER | ADMIN)),
};

const int numOfCommands = sizeof(commands) / sizeof(commands[0]);

