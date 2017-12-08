#pragma once
#include <string>
using namespace std;

// 데이터 클래스
class Book
{
public:
	Book();
	Book(int _id, string _bookname, string _author, int _pyear, bool _isborrowed);
	~Book();

	string Getname();
	string Getauthor();
	int Getyear();
	int Getbookid();

	void SetBorrowerID(int bid);
	void SetBorrowed(bool ib);

private:
	int id;
	string bookName;
	string author;
	int publishedYear;
	bool isBorrowed;
	int borrowerID; // 대여안된경우 -1로 설정
};

