#pragma once
#include "FileReader.h"
#include <sstream>
class TextReader :
	public FileReader
{
public:
	TextReader();
	~TextReader();

	void readUserFile(vector<User*>* _userList);
	void readBookFile(vector<Book*>* _bookList);
};

