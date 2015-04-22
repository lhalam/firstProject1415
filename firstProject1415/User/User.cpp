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
	using namespace std;
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

	/* id autogenerating */
	ifstream fin("Users.txt", ios_base::app);
	int i = 0;

	fin.seekg(0, fin.end);
	if (int(fin.tellg()) == 0) //If file is empty
	{
		id = 1;
	} else
	{
		do
		{
			fin.seekg(--i, fin.end); // go to i spots before the EOF
		} while (fin.get() != ',');
		fin >> id;
		++id;
	}
	
	fin.close();
}

void User::print()
{
	string message = "Name: " + name +
					 "\nSurname: " + surname +
					 "\nBirthday: " + birthday.toString() +
					 "\nLogin: " + login +
					 "\nPassword: " + password +
					 "\nEmail: " + email +
					 "\nRole: ";
	switch (role)
	{
		case Access::GUEST:
			message += " guest";
			break;
		case Access::USER:
			message += " user";
			break;
		case Access::ADMIN:
			message += " administrator";
			break;
	}
	message += "\nId: " + to_string(id);

	std::cout << Message(message, LOG_MSG);
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