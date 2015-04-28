#pragma once
#include "Message.h"
#include "Globals.h"

/*Command executors listed alphabetically*/

Result addNewProduct();
Result addNewProductsFromXML();
Result addProductToCart();
Result buyAllProductFromCart();
Result buyOneElementById();
Result changeAmount();
Result changeProduct();
Result createAdmin();
Result createUser();
Result exit();
Result exportProdXML();
Result help();
Result logIn();
Result logOut();
Result removeProductFromAssortment();
Result removeProductFromCart();
Result removeUser();
Result showCart();
Result showProducts();
Result showPurchaseHistory();
Result showStats();
Result showUsers();
