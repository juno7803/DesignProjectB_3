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

	void setleft(BSTNode* l);
	void setright(BSTNode* r);
	void setbooks(Book* b);
	void setkey(string k);

private:
	string key;
	BSTNode* left;
	BSTNode* right;
	vector<Book*> books;
};

