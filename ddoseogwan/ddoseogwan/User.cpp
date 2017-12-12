#include "User.h"



User::User()
{
}

User::User(int _id, string _pw, string _name)
{
	id = _id;
	password = _pw;
	name = _name;
}


User::~User()
{
}

int User::getid()
{
	return id;
}

string User::getpw()
{
	return password;
}

string User::getname()
{
	return name;
}

vector<int> User::GetborrowingList()
{
	return borrowingList;
}

void User::setborrowingList(int id)
{
	borrowingList.push_back(id);
}

void User::ResetBorrowingList(vector<int> li)
{
	borrowingList = li;
}
