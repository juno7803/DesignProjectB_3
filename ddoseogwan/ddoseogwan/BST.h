#pragma once
#include "WithIndex.h"
#include "BSTNode.h"

// �ε����� ����ϴ� �˻�
class BST :
	public WithIndex
{
public:
	BST();
	~BST();

	void buildIndex(); // BST�� ���ο� ��带 �߰��ϴ� ���
	void search(string key);

private:
	BSTNode* root;
};

