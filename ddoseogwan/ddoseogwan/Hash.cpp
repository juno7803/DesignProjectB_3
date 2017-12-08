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
		hashTable.at(b_num)->getbooks().push_back(_bookList->at(i));
		// �� �ѹ��� �ش��ϴ� ������ books�� å�� �����Ѵ�.
	}
}

vector<Book*>* Hash::search(string key)
// ���⼱ ���� �ϳ��� ã���� �ȴ�! (�̸��� �ߺ��Ȱ͵� ���� ������)
{
	return &((hashTable.at(hashFunction(key)))->getbooks());
}

void Hash::setblist(vector<Book*>* booklist)
{
	_bookList = booklist;
}

int Hash::hashFunction(string key)
{
	int temp;
	for (int i = 0; i < key.length(); i++)
	{
		temp += stoi(key.substr(i, i + 1)); // ���ڸ��� �о����
		// atoi ����Ϸ��� c_str�Լ��� ����ؾ� ��
	}
	return temp%(_bookList->size());
	// https://www.acmicpc.net/board/view/2994
}
