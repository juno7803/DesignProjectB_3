#include "BSTNode.h"



BSTNode::BSTNode()
{
	left = nullptr;
	right = nullptr;
}

BSTNode::BSTNode(string _key, BSTNode * _left, BSTNode * _right)
{
	key = _key;
	left = _left;
	right = _right;
	//books = _books;
}


BSTNode::~BSTNode()
{
}

vector<Book*> BSTNode::getbooks()
{
	return books;
}

string BSTNode::getkey()
{
	return key;
}

BSTNode * BSTNode::getleft()
{
	return left;
}

BSTNode * BSTNode::getright()
{
	return right;
}

void BSTNode::setleft(BSTNode * l)
{
	left = l;
}

void BSTNode::setright(BSTNode * r)
{
	right = r;
}

void BSTNode::setbooks(Book * b)
{
	books.push_back(b);
}

void BSTNode::setkey(string k)
{
	key = k;
}
