#pragma once
#include "Message.h"
#include "Globals.h"

/*Command executors*/
Result help();
Result exit();
Result logIn();
Result logOut();
Result createUser();
Result changeRole();
Result showUsers();
Result showCart();
Result changeProduct();