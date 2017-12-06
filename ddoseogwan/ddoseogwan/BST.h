#pragma once
#include "WithIndex.h"
#include "BSTNode.h"

// 인덱스를 사용하는 검색
// BST 중 Insert와 Search만 구현한다.
class BST :
	public WithIndex
{
public:
	BST();
	~BST();

	void buildIndex();
	vector<Book*>* search(string key); 
	void insert(Book* book);
	bool isEmpty() const;

private:
	BSTNode* root;
};

