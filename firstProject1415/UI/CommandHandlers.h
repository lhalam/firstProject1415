#pragma once
#include "Message.h"
#include "Globals.h"

/*Command executors listed alphabetically*/

DLL Result addNewProduct();
DLL Result addNewProductsFromXML();
DLL Result addProductToCart();
DLL Result buyAllProductFromCart();
DLL Result buyOneElementById();
DLL Result changeAmount();
DLL Result changeProduct();
DLL Result clear();
DLL Result createAdmin();
DLL Result createUser();
DLL Result enterMatrix();
DLL Result exit();
DLL Result exportProdXML();
DLL Result exportHistoryToHTML();
DLL Result help();
DLL Result logIn();
DLL Result logOut();
DLL Result removeProductFromAssortment();
DLL Result removeProductFromCart();
DLL Result removeUser();
DLL Result showCart();
DLL Result showProducts();
DLL Result showPurchaseHistory();
DLL Result showStats();
DLL Result showUsers();
