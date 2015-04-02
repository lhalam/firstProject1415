#include "DataManager.h"

void DataManager::saveUser(const User& user)
{
	UserService service;
	service.save(user);
}

void DataManager::saveProduct(const Product& prod)
{
	ProductService service;
	service.save(prod);
}

List<User*> DataManager::readAllUsers()
{
	UserService service;
	return service.readAll();
}

List<User*> DataManager::readUsers(bool(*predicate)(const User& user))
{
	UserService service;
	return service.read(predicate);
}

List<Product*> DataManager::readAllProducts()
{
	ProductService service;
	return service.readAll();
}

List<Product*> DataManager::readProducts(bool(*predicate)(const Product& user))
{
	ProductService service;
	return service.read(predicate);
}
