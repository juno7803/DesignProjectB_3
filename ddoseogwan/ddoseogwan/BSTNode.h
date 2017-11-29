#pragma once
#include <string>
#include <vector>
#include "Book.h"
using namespace std;
class BSTNode
{
public:
	BSTNode();
	~BSTNode();

private:
	string key;
	BSTNode* left;
	BSTNode* right;
	vector<Book*> books;
};

