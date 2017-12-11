#include "Bucket.h"



Bucket::Bucket()
{
}


Bucket::~Bucket()
{
}

vector<Book*> Bucket::getbooks()
{
	return books;
}

void Bucket::setbook(Book * b)
{
	books.push_back(b);
}
