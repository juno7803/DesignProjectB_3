#include "Hash.h"

Hash::Hash()
{
	for (int i = 0; i < _bookList->size(); i++)
	{
		hashTable[i] = new Bucket; // å ������ŭ ����� �̸� ����� �ش�.
	}
}

Hash::Hash(vector<Book*>* booklist)
{
	_bookList = booklist;
	for (int i = 0; i < _bookList->size(); i++)
	{
		Bucket* temp = new Bucket;
		hashTable.push_back(temp);
		//hashTable[i] = new Bucket; // å ������ŭ ����� �̸� ����� �ش�.
	}
}

Hash::~Hash()
{
}

void Hash::buildIndex()
{
	int b_num; // ���� �ѹ�!
	for (int i = 0; i < _bookList->size(); i++)
	{
		b_num = hashFunction(_bookList->at(i)->Getname()); // ���ϳѹ��� ���ϰ�
		hashTable[b_num]->setbook(_bookList->at(i));
		// �� �ѹ��� �ش��ϴ� ������ books�� å�� �����Ѵ�.
	}
}

vector<Book*> Hash::search(string key)
// ���⼱ ���� �ϳ��� ã���� �ȴ�! (�̸��� �ߺ��Ȱ͵� ���� ������)
{
	return ((hashTable.at(hashFunction(key)))->getbooks());
}

int Hash::hashFunction(string key)
{
	int temp = 0;
	//int num = atoi(key.c_str());
	//string chr = key.substr(0, 1);
	for (int i = 0; i < key.length(); i++)
	{
		temp += (int)(*(key.substr(i,i+1)).c_str()); // ���ڸ��� �о����
		// atoi ����Ϸ��� c_str�Լ��� ����ؾ� ��
		// atoi �ʿ����..
	}
	return temp%(_bookList->size());
	// https://www.acmicpc.net/board/view/2994
}
