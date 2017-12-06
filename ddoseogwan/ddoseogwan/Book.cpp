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

void Book::setBorrowerID(int _borrowerID)
{
	borrowerID = _borrowerID;
}

string Book::Getname()
{
	return bookName;
}
