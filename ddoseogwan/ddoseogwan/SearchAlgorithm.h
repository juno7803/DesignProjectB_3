#pragma once
#include "User.h"
#include "Book.h"

// 최상위 클래스
class SearchAlgorithm
{
public:
	SearchAlgorithm();
	~SearchAlgorithm();
	virtual vector<Book*> search(string key) = 0; // 이름이 일치하는 책들 찾아 반환하는 함수 void는 오류 -> vector<book*>* : 중복되는 책 있는경우때문!

protected:
	vector<Book*>* _bookList;
};

