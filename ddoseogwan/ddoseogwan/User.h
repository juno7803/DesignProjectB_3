#pragma once
#include <string>
#include <vector>
using namespace std;

// ������
class User
{
public:
	User();
	User(int _id, string _pw, string _name);
	~User();
	int getid();
	string getpw();
	string getname();
	vector<int> GetborrowingList();

	void setborrowingList(int id);
	void ResetBorrowingList(vector<int> li);

private:
	int id;
	string password;
	string name;
	vector<int> borrowingList;
};