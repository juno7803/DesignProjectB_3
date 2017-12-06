#pragma once
#include "FileReader.h"

// 바이너리 모드로 읽기
class BinaryReader :
	public FileReader
{
public:
	BinaryReader();
	~BinaryReader();

	void readUserFile(vector<User*>* _userList);
	void readBookFile(vector<Book*>* _bookList);
};