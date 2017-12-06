#pragma once
#include <string>
#include <vector>
#include "Book.h"
using namespace std;
class BSTNode
{
public:
	BSTNode();
	BSTNode(string _key, BSTNode* _left,BSTNode* _right);
	~BSTNode();
	vector<Book*> getbooks();
	string getkey();
	BSTNode* getleft();
	BSTNode* getright();

	const bool operator<(string& key) const;

private:
	string key;
	BSTNode* left;
	BSTNode* right;
	vector<Book*> books;
};

