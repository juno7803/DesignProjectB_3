#pragma once
#include "NoIndex.h"
#include <iostream>
using namespace std;

// (1) ���� ���� ����
// (2) ���ĵǾ� �־�� ��
class BinarySearch :
	public NoIndex
	// �ε����� ������� �����Ƿ� NoIndex ��ӹ���
{
public:
	BinarySearch();
	BinarySearch(vector<Book*>* _bookList);
	// �����ڿ��� ���Ľ��Ѿ� ��
	// ������ ã�� ��쵵 ������ ������. 
	// ������ �������� ���ʿ����� ã�� �����ʿ����� ã��! ���ĵǾ� �����ϱ� �� �� ������.
	~BinarySearch();

	vector<Book*>* search(string key);
};