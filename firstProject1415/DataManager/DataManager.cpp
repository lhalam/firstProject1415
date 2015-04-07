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

List<User*> DataManager::readUsers(function<bool(const User&)> predicate)
{
	UserService service;
	return service.read(predicate);
}

User * DataManager::getUserByLogin(string login, string password)
{
	UserService service;
	return service.getByLogin(login, password);
}

User* DataManager::getUserById(int id)
{
	UserService user;
	return user.getById(id);
}
void DataManager::removeUserById(int id)
{
	UserService user;
	user.removeById(id);
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

Product* DataManager::getProductById(int id)
{
	ProductService product;
	product.getById(id);
}

void DataManager::removeProductById(int id)
{
	ProductService prod;
	prod.removeById(id);
}
