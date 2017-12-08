#pragma once
#include "WithIndex.h"
#include "Bucket.h"
#include <cstdlib>
#include <string>

// �ε��� ��� �˻� �˰���
// å�� ����ŭ Bucket ����
class Hash :
	public WithIndex
{
public:
	Hash();
	Hash(vector<Book*>* booklist);
	~Hash();
	void buildIndex();
	// bookList�� ����� å���� å �̸��� Ű�� ����Ͽ� hashTable�� ������
	vector<Book*>* search(string key);
	void setblist(vector<Book*>* booklist);

private:
	vector<Bucket*> hashTable; // Bucket�� ���� -> Bucket�� ���� �����͸� ��� ��
	int hashFunction(string key);
};