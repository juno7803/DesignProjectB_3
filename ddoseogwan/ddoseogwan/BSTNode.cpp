#include "BSTNode.h"



BSTNode::BSTNode()
{
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

const bool BSTNode::operator<(string& key) const
{
	if (this->key < key) return true;
	else return false;
}
