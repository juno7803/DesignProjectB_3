#pragma once
#include <string>
#include <vector>
using namespace std;

// ตฅภฬลอ
class User
{
public:
	User();
	User(int _id, string _pw, string _name, vector<int> _bl);
	~User();
	int getid();
	string getpw();
	string getname();
	vector<int> GetborrowingList();

private:
	int id;
	string password;
	string name;
	vector<int> borrowingList;
};