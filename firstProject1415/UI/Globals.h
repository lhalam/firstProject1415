#pragma once
#include "../User/User.h"
#include "../List/List.h"
#include "../Products/Product.h"

/* Declarations of all global variables (all extern) */
extern User currentUser; // User that is using our program
extern List<Product*> cart; // Current session's shopping cart

/* Declarations of all global functions (all extern )*/
extern void toLowercase(string& line);
