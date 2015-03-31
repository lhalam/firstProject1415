#include "User.h"

User::User() :
Person(),
login("noLogin"),
password("noPass"),
email("noEmail")
{
	properties = new Properties("Guest", 0);
}

User::User(string mname, string msurname, Date mbirthday, string mlogin, string mpasssword, string memail, Properties* mproperties) :
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
	cout<<"name : ";
	stream >> user.name;
	cout<<"surname : ";
	stream >> user.surname;
	cout<<"birthday : ";
	stream>>user.birthday;
	cout<<"login : ";
	stream>>user.login;
	cout<<"password : ";
	stream>>user.password; 
	cout<<"email : ";
	stream>>user.email;
	cout<<"properties : \n";
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

void User::changePassword(string newPass)
{
	password = newPass;
}

void User::changeEmail(string newEmail)
{
	email = newEmail;
}

void User::changeRole(string newRole)
{
	properties->setRole(newRole);
}