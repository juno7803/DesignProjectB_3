#pragma once
#include "WithIndex.h"
#include "Bucket.h"

// �ε��� ��� �˻� �˰���
// å�� ����ŭ Bucket ����
class Hash :
	public WithIndex
{
public:
	Hash();
	~Hash();

	void buildIndex();
	vector<Book*>* search(string key);

private:
	vector<Bucket*> hashTable; // Bucket�� ���� -> Bucket�� ���� �����͸� ��� ��
	int hashFunction(string key);
};