#pragma once
#include <string>
using namespace std;

// ������ Ŭ����
class Book
{
public:
	Book();
	Book(int _id, string _bookname, string _author, int _pyear, bool _isborrowed);
	~Book();
	void setBorrowerID(int _borrowerID);

	string Getname();

private:
	int id;
	string bookName;
	string author;
	int publishedYear;
	bool isBorrowed;
	int borrowerID; // �뿩�ȵȰ�� -1�� ����
};

