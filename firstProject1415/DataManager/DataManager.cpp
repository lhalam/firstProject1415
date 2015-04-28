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

void saveToUserHistory(int id, const Product& prod, unsigned quantity)
{
	UserService().saveToHistory(id, prod, quantity);
}

void DataManager::removeUserById(int id)
{
	UserService user;
	user.removeById(id);
}

void DataManager::writeInHTML(int id, const Date& start, const Date& end) const
{
	HTMLService().write(id, start, end);
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

List<Product*> DataManager::getAllFromUserStory(int id)
{
	return UserService().getAllFromStory(id);
}

int DataManager::getQuantity(int id)
{
	ProductService quantity;
	return quantity.getQuantity(id);
}

void DataManager::setQuantity(int id, int newQuantity)
{
	ProductService quantity;
	quantity.setQuantity(id, newQuantity);
}

void DataManager::changeQuantity(int id, int add_quantity)
{
	ProductService quantity;
	quantity.changeQuantity(id, add_quantity);
}

Product* DataManager::identifyProductType(string type)
{
	ProductService product;
	return product.identifyType(type);
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

void DataManager::removeProducts(function<bool(const Product&)> predicate)
{
	ProductService prod;
	prod.removeByPredicate(predicate);
}

void DataManager::removeUsers(function<bool(const User&)> predicate)
{
	UserService user;
	user.removeByPredicate(predicate);
}

void DataManager::saveStatistics(unsigned quantity, int id)
{
	ProductService product;
	product.saveStatistics(quantity, id);

}

map<Product*, int> DataManager::readStatistics()
{
	ProductService product;
	return product.readStatistics();
}
