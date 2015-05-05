#include <iostream>
#include "Command.h"
#include "CommandHandlers.h"

/*Initialization of commands; commands are listed alphabetically*/
Command commands[] = 
{
	Command("add -c", addProductToCart, "add product to cart by id ", Access(GUEST | USER)),
	Command("add -p", addNewProduct, "adds new product", Access::ADMIN),
	Command("buy", buyOneElementById, "buys product by id", Access::USER),
	Command("buy -a", buyAllProductFromCart, "buys all product from cart", Access(USER | GUEST)),
	Command("change amount", changeAmount, "changes amount of products", Access::ADMIN),
	Command("change -p", changeProduct, "changes product settings", Access::ADMIN),
	Command("clear", clear, "clears the screen", Access(GUEST | USER | ADMIN)),
	Command("exit", exit, "exits the program", Access(GUEST | USER | ADMIN)),
	Command("export -p", exportProdXML, "exports all existing products to XML file", Access::ADMIN),
	Command("export -h", exportHistoryToHTML, "exports purchase history to a web-document", Access::USER),
	Command("help", help, "provides you with the list of available commands and their description", Access(GUEST | USER | ADMIN)),
	Command("import", addNewProductsFromXML, "adds new products from .xml file", Access::ADMIN),
	Command("log in", logIn, "performs user authentication", Access::GUEST),
	Command("log out", logOut, "exits user profile", Access(USER | ADMIN)),
	Command("matrix", enterMatrix, "just a fun", Access(GUEST | USER | ADMIN)),
	Command("register", createUser, "creates a new account", Access(GUEST | ADMIN)),
	Command("register admin", createAdmin, "makes a normal user an administrator", Access::ADMIN),
	Command("remove -u", removeUser, "deletes a specified user account", Access::ADMIN),
	Command("remove -p", removeProductFromAssortment, "removes the product from assortment", Access::ADMIN),
	Command("remove -pc", removeProductFromCart, "deletes a product from your cart", Access(GUEST | USER)),
	Command("show -ap", showProducts, "shows the list of all products", Access(GUEST | USER | ADMIN)),
	Command("show -au", showUsers, "shows the list of all users", Access::ADMIN),
	Command("show -c", showCart, "shows all products added to cart", Access(GUEST | USER)),
	Command("show -h", showPurchaseHistory, "shows the history of the purchases of the user", Access(USER | ADMIN)),
	Command("show -s", showStats, "shows the statistics of all bought products", Access::ADMIN),
};

const int numOfCommands = sizeof(commands) / sizeof(commands[0]);


