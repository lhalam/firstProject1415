#include "User.h"

User::User() :
	Person(),
	login("noLogin"),
	password("noPass"),
	email("noEmail")
{
	properties = new Properties(GUEST, 0);
}

User::User(string mname, string msurname, Date mbirthday,
		string mlogin, string mpasssword, string memail,
		Properties* mproperties) :
	Person(mname, msurname, mbirthday),
	login(mlogin),
	password(mpasssword),
	email(memail)
{
	properties = new Properties(mproperties->getRole(), mproperties->getId());
}

User::User(const User& user) :
	Person(user),
	login(user.login),
	password(user.password),
	email(user.email)
{
	properties = new Properties(user.properties->getRole(), user.properties->getId());
}

User::~User()
{
	delete properties;
}

istream& operator>>(istream& stream, User& user)
{
	//added all cout messages (User team)
	using std::cout;
	stream >> user.name;
	stream >> user.surname;
	stream>>user.birthday;
	stream>>user.login;
	stream>>user.password;
	stream>>user.email;
	stream>>*user.properties;
	return stream;
}
ostream& operator<<(ostream& stream, const User& user)
{
	stream << user.name << " "
		<< user.surname << " "
		<< user.birthday << " "
		<< user.login << " "
		<< user.password << " "
		<< user.email << " "
		<< *user.properties;
	stream;
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
	cout << Message("Properties", CONTEXT_MSG);
	cin >> *properties;
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
	return properties->getId();
}

Access User::getRole() const
{
	return properties->getRole();
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