#pragma once 
#include "../User/Date.h"
#include "../List/List.h"
#include "../Products/Products.h"

class XMLService
{
public:
	List<Product*> read();
};