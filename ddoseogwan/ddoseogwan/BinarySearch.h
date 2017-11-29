#pragma once
#include "NoIndex.h"

// (1) ���� ���� ����
// (2) ���ĵǾ� �־�� ��
class BinarySearch :
	public NoIndex
	// �ε����� ������� �����Ƿ� NoIndex ��ӹ���
{
public:
	BinarySearch();
	BinarySearch(vector<Book*>* _bookList); // �����ڿ��� ���Ľ��Ѿ� ��
											// ������ ã�� ��쵵 ������ ������. ������ �������� ���ʿ����� ã�� �����ʿ����� ã��. ���ĵǾ� �����ϱ� �˼�������.
	~BinarySearch();

	void search(string key);
};

