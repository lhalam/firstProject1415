#include "User.h"

#include <fstream>

#include "..\DataManager\DataManager.h"

User::User() :
	Person(),
	login("noLogin"),
	password("noPass"),
	email("noEmail"),
	role(GUEST),
	id(0)
{
}

User::User(string mname, string msurname, Date mbirthday,
		string mlogin, string mpasssword, string memail,
		Access mrole, int mid) :
	Person(mname, msurname, mbirthday),
	login(mlogin),
	password(mpasssword),
	email(memail),
	role(mrole),
	id(mid)
{
}

User::User(const User& user) :
	Person(user),
	login(user.login),
	password(user.password),
	email(user.email),
	role(user.role),
	id(user.id)
{
}

User::~User()
{
}

istream& operator>>(istream& stream, User& user)
{
	getline(stream, user.name, ',');
	getline(stream, user.surname, ',');
	stream >> user.birthday;
	stream.get();
	getline(stream, user.login, ',');
	getline(stream, user.password, ',');
	getline(stream, user.email, ',');
	string helpInput;
	getline(stream, helpInput, ',');
	user.role = Access(stoi(helpInput));
	getline(stream, helpInput, '\n');
	user.id = stoi(helpInput);
	/*
	stream >> user.name;
	stream >> user.surname;
	stream >> user.birthday;
	stream >> user.login;
	stream >> user.password;
	stream >> user.email;
	stream >>*user.properties;
	*/
	return stream;
}
ostream& operator<<(ostream& stream, const User& user)
{
	stream << user.name << ','
		<< user.surname << ','
		<< user.birthday << ','
		<< user.login << ','
		<< user.password << ','
		<< user.email << ','
		<< user.role << ','
		<< user.id << '\n';
	return stream;
}

void User::input()
{
	using std::cout;
	using std::cin;
	cout << Message("Name", CONTEXT_MSG);
	cin >> name;
	cout << Message("Surname", CONTEXT_MSG);
	cin >> surname;
	cout << Message("Birthday (day month year)", CONTEXT_MSG);
	cin >> birthday;
	cout << Message("Login", CONTEXT_MSG);
	cin >> login;
	cout << Message("Password", CONTEXT_MSG);
	cin >> password;
	cout << Message("Email", CONTEXT_MSG);
	cin >> email;
	role = USER;
	id = 0;
	//id autogenerating
	/* soon
	DataManager manager;
	List<User*> list = manager.readAllUsers();
	int lastUserId = (*(--list.end()))->getId();
	std::ifstream file("Text.txt", std::ios::binary);
	file.seekg(0, std::ios::end);
	int length = file.tellg();
	file.open("Text.txt");
	file.seekg(length-1);
	char mid;
	file >> mid;
	
	file.unget();
	id = (int)mid + 1;
	
	
	file.close();
	*/
}

void User::print()
{
	std::cout 
		<< "Name: " << name
		<< "\nSurname: " << surname
		<< "\nBirthday: " << birthday
		<< "\nLogin: " << login
		<< "\nPassword: " << password
		<< "\nEmail: " << email
		<< "\nRole: " << role
		<< "\nId: " << id;
}

void User::changePassword(string newPass)
{
	password = newPass;
}

void User::changeEmail(string newEmail)
{
	email = newEmail;
}

int User::getId() const
{
	return id;
}

Access User::getRole() const
{
	return role;
}

string User::getLogin() const
{
	return login;
}

string User::getPassword() const
{
	return password;
}

string User::getEmail() const
{
	return email;
}

void User::setRole(Access mrole)
{
	role = mrole;
}