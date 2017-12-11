#include "BST.h"

BST::BST()
{
	root = nullptr;
}

BST::BST(vector<Book*>* booklist)
{
	_bookList = booklist;
	root = nullptr;
}


BST::~BST()
{
}

void BST::buildIndex()
{
	for (int i = 0; i < _bookList->size(); i++)
	{
		if (root == nullptr) // 루트는 따로 미리 설정
		{
			root = new BSTNode;
			root->setkey(_bookList->at(i)->Getname());
			root->setbooks(_bookList->at(i));
		}
		else
		{
			insert(root, _bookList->at(i));
		}
	}
}

vector<Book*> BST::search(string key)
// 현재 노드를 계속 바꿔주면서 재귀탐색
// 노드에 이름이 같은책이 여러개 들어있을수 있으므로, 벡터자체를 반환하도록 한다
{
	vector<Book*> result;
	BSTNode* Cur = this->root;
	while (1)
	{
		if (Cur->getkey() == key)
		{
			return result = Cur->getbooks(); // 종료조건 1 - 일치하는 키 값이 있는 경우
		}
		if (Cur->getkey().compare(key) > 0)
		{
			if (Cur->getleft() == nullptr)
				return result; // 종료조건 2 - 해당 위치에 자손이 없는 경우
			Cur = Cur->getleft();
		}
		else if (Cur->getkey().compare(key) < 0)
		{
			if (Cur->getright() == nullptr)
				return result; // 종료조건 2 - 해당 위치에 자손이 없는 경우
			Cur = Cur->getright();
		}
	}
}
//http://robodream.tistory.com/201 이진탐색트리 정말 쉽게 구현..

void BST::insert(BSTNode* current, Book* book)
{
	if (current->getkey() == book->Getname())
	{
		current->setbooks(book);
	}
	else if (current->getkey().compare(book->Getname()) > 0) // string 사전순 비교 함수 compare
	{
		if (current->getleft() == nullptr)
		{
			BSTNode* left = new BSTNode;
			left->setkey(book->Getname());
			current->setleft(left);
		}
		insert(current->getleft(), book);
	}
	else if (current->getkey().compare(book->Getname()) < 0)
	{
		if (current->getright() == nullptr)
		{
			BSTNode* right = new BSTNode;
			right->setkey(book->Getname());
			//right->setbooks(book);
			current->setright(right);
		}
		insert(current->getright(), book);
	}
}

bool BST::isEmpty() const
{
	return root == nullptr;
}
