#include "TextReader.h"



TextReader::TextReader()
{
}


TextReader::~TextReader()
{
}

void TextReader::readUserFile(vector<User*>* _userList)
{
	ifstream ifs("UserText.txt");
	int id, bnum, bookid;
	vector<int>borrowlist;
	string pw, name;
	
	while (!ifs.eof())
	{
		ifs >> id >> pw >> name >> bnum;
		for (int i = 0; i < bnum; i++)
		{
			ifs >> bookid;
			borrowlist.push_back(bookid);
		}
		User* temp = new User(id, pw, name, borrowlist);
		_userList->push_back(temp);
	}
	ifs.close();
}

void TextReader::readBookFile(vector<Book*>* _bookList)
{
	ifstream ifs("BookText.txt");
	int id, year, borrowid, borrow;
	string bname, author;
	while (!ifs.eof())
	{
		ifs >> id >> bname >> author >> year >> borrow;
		Book* temp = new Book(id, bname, author, year, borrow);
		if (borrow == 1)
		{
			ifs >> borrowid;
			temp->SetBorrowerID(borrowid);
		}
		_bookList->push_back(temp);
	}
	ifs.close();
}
