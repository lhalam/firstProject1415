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

void DataManager::removeUserById(int id)
{
	UserService user;
	user.removeById(id);
}

void DataManager::removeProductById(int id)
{
	ProductService prod;
	prod.removeById(id);
}

List<User*> DataManager::readAllUsers()
{
	UserService service;
	return service.readAll();
}

List<User*> DataManager::readUsers(function<bool(const User&)> predicate)
{
	UserService service;
	return service.read(predicate);
}

List<Product*> DataManager::readAllProducts()
{
	ProductService service;
	return service.readAll();
}

List<Product*> DataManager::readProducts(function<bool(const Product&)> predicate)
{
	ProductService service;
	return service.read(predicate);
}
