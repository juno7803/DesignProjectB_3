#pragma once
#include <string>
using namespace std;

// ������ Ŭ����
class Book
{
public:
	Book();
	~Book();

private:
	int id;
	string bookName;
	string author;
	int publishedYear;
	int isBorrowed;
	int borrowerID; // �뿩�ȵȰ�� -1�� ����
};

