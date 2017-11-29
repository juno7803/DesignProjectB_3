#pragma once
#include "WithIndex.h"
#include "Bucket.h"

// �ε��� ��� �˻� �˰���
class Hash :
	public WithIndex
{
public:
	Hash();
	~Hash();

	void buildIndex();
	void search(string key);

private:
	vector<Bucket*> hashTable; // Bucket�� ���� -> Bucket�� ���� �����͸� ��� ��
	int hashFunction(string key);
};