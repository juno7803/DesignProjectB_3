#include "Book.h"



Book::Book()
{
}

Book::Book(int _id, string _bookname, string _author, int _pyear, bool _isborrowed)
{
	id = _id;
	bookName = _bookname;
	author = _author;
	publishedYear = _pyear;
	isBorrowed = _isborrowed;
}


Book::~Book()
{
}

string Book::Getname()
{
	return bookName;
}

string Book::Getauthor()
{
	return author;
}

int Book::Getyear()
{
	return publishedYear;
}

int Book::Getbookid()
{
	return id;
}

bool Book::Getisborrowed()
{
	return isBorrowed;
}

int Book::GetborrwedID()
{
	return borrowerID;
}

void Book::SetBorrowerID(int bid)
{
	borrowerID = bid;
}

void Book::SetBorrowed(bool ib)
{
	isBorrowed = ib;
}
