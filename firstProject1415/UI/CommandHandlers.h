#pragma once
#include "../User/User.h"
#include "Message.h"

using std::cout;

/*Command executors*/
Result help();
Result exit();
Result logIn();
Result logOut();
Result createUser();
Result changeRole();
Result showUsers();