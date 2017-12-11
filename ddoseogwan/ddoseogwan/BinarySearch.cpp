#include "BinarySearch.h"



BinarySearch::BinarySearch()
{
}

BinarySearch::BinarySearch(vector<Book*>* _bookList)
{
	this->_bookList = _bookList; // �����͸� �Űܹް�,
	// å �̸� ������� ����!
	for (int i = 0; i < _bookList->size(); i++)
	{
		int tmp = i;
		for (int j = i + 1; j < _bookList->size(); j++)
		{
			if (_bookList->at(tmp)->Getname() >= _bookList->at(j)->Getname())
				// å �̸�(string) ���� ��
			{
				tmp = j;
			}
			Book* temp;
			temp = _bookList->at(i);
			_bookList->at(i) = _bookList->at(tmp);
			_bookList->at(tmp) = temp;
			// swap
		}
	}
	// Bubble Sort
}


BinarySearch::~BinarySearch()
{
}

vector<Book*> BinarySearch::search(string key)
{
	vector<Book*> temp;
	int first = 0;
	int last = _bookList->size();
	int mid;
	while (first <= last)
	{
		mid = (first + last) / 2;
		if (key > (_bookList->at(mid)->Getname()))
			first = mid + 1;
		else if (key < (_bookList->at(mid)->Getname()))
			last = mid - 1;
		else
			first = last + 1;
	}
	if (key != _bookList->at(mid)->Getname())
	{
		cout << "ã�� ������ ����!" << endl;
	}
	else
	{
		temp.push_back(_bookList->at(mid));
		//ã�� ��ġ�� mid ��!
		for (int i = 0; i < mid; i++)
		{
			if (key == _bookList->at(i)->Getname())
				temp.push_back(_bookList->at(i));
		}
		for (int i = mid; i < _bookList->size(); i++)
		{
			if (key == _bookList->at(i)->Getname())
				temp.push_back(_bookList->at(i));
		}
		return temp;
	}
}