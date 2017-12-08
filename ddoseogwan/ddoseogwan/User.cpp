#include "User.h"



User::User()
{
}

User::User(int _id, string _pw, string _name, vector<int> _bl)
{
	id = _id;
	password = _pw;
	name = _name;
	for (int i = 0; i < _bl.size(); i++)
	{
		borrowingList.push_back(_bl[i]);
	}
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
