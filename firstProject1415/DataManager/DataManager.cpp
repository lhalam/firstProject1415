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

int DataManager::getQuantity(int id)
{
	ProductService quantity;
	return quantity.getQuantity(id);
}

void DataManager::setQuantity(int id, int add_quantity)
{
	ProductService quantity;
	quantity.setQuantity(id, add_quantity);
}

Product* DataManager::getProductById(int id)
{
	ProductService product;
	return product.getById(id);
}

void DataManager::removeProductById(int id)
{
	ProductService prod;
	prod.removeById(id);
}

void DataManager::removeProductByPredicate(function<bool(const Product&)> predicate)
{
	ProductService prod;
	prod.removeByPredicate(predicate);
}

void DataManager::removeUserByPredicate(function<bool(const User&)> predicate)
{
	UserService user;
	user.removeByPredicate(predicate);
}

