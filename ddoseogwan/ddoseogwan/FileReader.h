#pragma once
#include <vector>
#include <fstream>
#include "Book.h"
#include "User.h"
using namespace std;

// �߻�Ŭ���� -> Text���� Binary����
class FileReader
{
public:
	FileReader();
	~FileReader();

	virtual void readUserFile(vector<User*>* _userList) = 0;
	virtual void readBookFile(vector<Book*>* _userList) = 0;
};

