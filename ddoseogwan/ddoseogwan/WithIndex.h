#pragma once
#include "SearchAlgorithm.h"
class WithIndex :
	public SearchAlgorithm
{
public:
	WithIndex();
	~WithIndex();

	virtual void buildIndex() = 0;
	// BST면 부모에 있는 책리스트를 하나씩 읽으면서 노드를 추가
	// HASH면 거기에 맞는 hash table을 만들 것
};

