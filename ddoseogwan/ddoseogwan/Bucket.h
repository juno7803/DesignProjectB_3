#pragma once
#include "Book.h"
#include <vector>
using namespace std;
class Bucket
{
public:
	Bucket();
	~Bucket();
	vector<Book*> getbooks();

private:
	vector<Book*> books;
	// ���� �ؽð��� ���� å���� ����
	// �ؽ����̺����� "��"�� �ش��Ѵ�.
};