#include "BST.h"



BST::BST()
{
	root = nullptr;
}


BST::~BST()
{
}

void BST::buildIndex()
{
	for (int i = 0; i < _bookList->size(); i++)
	{
		insert(_bookList->at(i));
	}
}

vector<Book*>* BST::search(string key)
// 루트를 계속 바꿔주면서 재귀탐색
// 노드에 이름이 같은책이 여러개 들어있을수 있으므로, 벡터자체를 반환하도록 한다
{
	if (root->getkey() == key)
	{
		return &(root->getbooks());
	}
	// 종료조건 1 - 탐색중인 노드와 값이 같은 경우

	else if(root->getleft() == nullptr && root->getright() == nullptr)
	{
		return nullptr;
	}
	// 종료조건2 - 자식 노드가 없는 경우(찾는 값이 없는경우)

	else
	{
		if (root->getkey() > key)
		{
			root = root->getleft();
			search(key);
		}
		else if (root->getkey() < key)
		{
			root = root->getright();
			search(key);
		}
	}
	// 종료조건 1 or 2가 될때까지 root를 바꿔가며 재귀호출
}

void BST::insert(Book* book)
{
	if (isEmpty()) // root가 nullptr 일 경우 - 새로운 노드를 추가시켜줘야 한다.(빈 노드를 채워줘야 한다.)
	{
		BSTNode* newnode = new BSTNode(book->Getname(), nullptr, nullptr);
		newnode->getbooks().push_back(book);
		root = newnode;
	}
	else
	{
		if (root->getkey() > book->Getname())
		{
			root = root->getleft();
			insert(book);
		}
		else if (root->getkey() < book->Getname())
		{
			root = root->getright();
			insert(book);
		}
		else if (root->getkey() == book->Getname())
		{
			root->getbooks().push_back(book);
			insert(book);
		}
	}
}

bool BST::isEmpty() const
{
	return root == nullptr;
}
