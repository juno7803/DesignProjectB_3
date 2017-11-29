#pragma once
#include "WithIndex.h"
#include "BSTNode.h"

// 인덱스를 사용하는 검색
class BST :
	public WithIndex
{
public:
	BST();
	~BST();

	void buildIndex(); // BST에 새로운 노드를 추가하는 방식
	void search(string key);

private:
	BSTNode* root;
};

