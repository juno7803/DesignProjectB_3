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
		if (root == nullptr) // ��Ʈ�� ���� �̸� ����
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
// ���� ��带 ��� �ٲ��ָ鼭 ���Ž��
// ��忡 �̸��� ����å�� ������ ��������� �����Ƿ�, ������ü�� ��ȯ�ϵ��� �Ѵ�
{
	vector<Book*> result;
	BSTNode* Cur = this->root;
	while (1)
	{
		if (Cur->getkey() == key)
		{
			return result = Cur->getbooks(); // �������� 1 - ��ġ�ϴ� Ű ���� �ִ� ���
		}
		if (Cur->getkey().compare(key) > 0)
		{
			if (Cur->getleft() == nullptr)
				return result; // �������� 2 - �ش� ��ġ�� �ڼ��� ���� ���
			Cur = Cur->getleft();
		}
		else if (Cur->getkey().compare(key) < 0)
		{
			if (Cur->getright() == nullptr)
				return result; // �������� 2 - �ش� ��ġ�� �ڼ��� ���� ���
			Cur = Cur->getright();
		}
	}
}
//http://robodream.tistory.com/201 ����Ž��Ʈ�� ���� ���� ����..

void BST::insert(BSTNode* current, Book* book)
{
	if (current->getkey() == book->Getname())
	{
		current->setbooks(book);
	}
	else if (current->getkey().compare(book->Getname()) > 0) // string ������ �� �Լ� compare
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
