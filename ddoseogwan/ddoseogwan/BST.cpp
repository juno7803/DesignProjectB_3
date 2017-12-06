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
// ��Ʈ�� ��� �ٲ��ָ鼭 ���Ž��
// ��忡 �̸��� ����å�� ������ ��������� �����Ƿ�, ������ü�� ��ȯ�ϵ��� �Ѵ�
{
	if (root->getkey() == key)
	{
		return &(root->getbooks());
	}
	// �������� 1 - Ž������ ���� ���� ���� ���

	else if(root->getleft() == nullptr && root->getright() == nullptr)
	{
		return nullptr;
	}
	// ��������2 - �ڽ� ��尡 ���� ���(ã�� ���� ���°��)

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
	// �������� 1 or 2�� �ɶ����� root�� �ٲ㰡�� ���ȣ��
}

void BST::insert(Book* book)
{
	if (isEmpty()) // root�� nullptr �� ��� - ���ο� ��带 �߰�������� �Ѵ�.(�� ��带 ä����� �Ѵ�.)
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
