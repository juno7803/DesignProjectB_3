#pragma once
#include "User.h"
#include "Book.h"

// �ֻ��� Ŭ����
class SearchAlgorithm
{
public:
	SearchAlgorithm();
	~SearchAlgorithm();
	virtual vector<Book*> search(string key) = 0; // �̸��� ��ġ�ϴ� å�� ã�� ��ȯ�ϴ� �Լ� void�� ���� -> vector<book*>* : �ߺ��Ǵ� å �ִ°�춧��!

protected:
	vector<Book*>* _bookList;
};

