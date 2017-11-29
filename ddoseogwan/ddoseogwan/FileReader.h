#pragma once
#include <vector>
#include <fstream>
#include "Book.h"
#include "User.h"
using namespace std;

// 추상클래스 -> Text리더 Binary리더
class FileReader
{
public:
	FileReader();
	~FileReader();

	virtual void readUserFile(vector<User*>* _userList) = 0;
	virtual void readBookFile(vector<Book*>* _userList) = 0;
};

