#pragma once
#include "WithIndex.h"
#include "BSTNode.h"
#include <string>

// �ε����� ����ϴ� �˻�
// BST �� Insert�� Search�� �����Ѵ�.
class BST :
	public WithIndex
{
public:
	BST();
	BST(vector<Book*>* booklist);
	~BST();

	void buildIndex();
	vector<Book*> search(string key);
	void insert(BSTNode* current,Book* book);
	bool isEmpty() const;

private:
	BSTNode* root;
};

