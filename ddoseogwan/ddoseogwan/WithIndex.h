#pragma once
#include "SearchAlgorithm.h"
class WithIndex :
	public SearchAlgorithm
{
public:
	WithIndex();
	~WithIndex();

	virtual void buildIndex() = 0;
	// BST�� �θ� �ִ� å����Ʈ�� �ϳ��� �����鼭 ��带 �߰�
	// HASH�� �ű⿡ �´� hash table�� ���� ��
};

