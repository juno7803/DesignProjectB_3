#pragma once
#include "FileReader.h"

// ���̳ʸ� ���� �б�
class BinaryReader :
	public FileReader
{
public:
	BinaryReader();
	~BinaryReader();

	void readUserFile(vector<User*>* _userList);
	void readBookFile(vector<Book*>* _bookList);
};