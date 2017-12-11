#pragma once
#include "Book.h"
#include <vector>
using namespace std;
class Bucket
{
public:
	Bucket();
	~Bucket();
	vector<Book*> getbooks();
	void setbook(Book* b);

private:
	vector<Book*> books;
	// 같은 해시값을 가진 책들의 모임
	// 해시테이블에서의 "방"에 해당한다.
};