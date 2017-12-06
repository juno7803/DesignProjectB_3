#include "App.h"



App::App()
{
	sa->setblist(&bookList);
}


App::~App()
{
}

void App::run()
{
	while (1)
	{
		//int num = Getcommand() ������ �ٲ���
		int num = 0;
		cout << "���� �б� ��� ����" << endl;
		cout << "1. Binary ���" << endl;
		cout << "0. Text ���" << endl;
		cin >> num;
		readFile(num);
		login();
	}
}

void App::startmenu()
{
	while (1)
	{
		int num;
		cout << "1. ���� �˻� �� �뿩" << endl;
		cout << "2. ���� �ݳ�" << endl;
		switch (num)
		{
		case 1:
			searchBook();
			break;
		case 2:
			returnBook();
			break;
		}
	}
}

void App::login()
{
	int id;
	string pw;

	cout << "�����̵� �Է��ϼ��� : ";
	cin >> id;
	cout << "����й�ȣ�� �Է��ϼ��� : ";
	cin >> pw;
	for (int i = 0; i < userList.size(); i++)
	{
		if (id == userList[i]->getid())
		{
			if (pw == userList[i]->getpw())
			{
				cout << "��" << userList[i]->getname() << "�� ȯ���մϴ�!" << endl;
				cout << "����������������������������������" << endl;
				loginedUser = userList[i];
				startmenu();
			}
			else
			{
				cout << "��й�ȣ�� ��ġ���� �ʽ��ϴ�" << endl;
				return;
			}
		}
	}
	cout << "��ġ�ϴ� ���̵� �����ϴ�" << endl;
	return;
}

void App::readFile(bool isBinary)
{
	switch (isBinary)
	{
	case true:
		fr = new BinaryReader();
		fr->readUserFile(&userList);
		fr->readBookFile(&bookList);
		break;
	case false:
		fr = new TextReader();
		fr->readUserFile(&userList);
		fr->readBookFile(&bookList);
		break;
	}
}

void App::writeFile(bool isBinary)
{
}

void App::searchBook()
{
	string key;
	cout << "å �̸� �Է�: ";
	cin >> key;
	sa->search(key);
	if (sa->search(key) == nullptr)
	{
		cout << "ã�� ������ �����ϴ�." << endl;
	}
}

void App::borrowBook()
{
}

void App::returnBook()
{
}

void App::buildIndex()
{
	int command;
	cout << "1. Binary Search Tree" << endl;
	cout << "2. Hash" << endl;
	cout << "3. Binary Search" << endl;
	cin >> command;

	switch (command)
	{
	case 1:
		sa = new BST();
		((BST*)sa)->buildIndex();
		break;
	case 2:
		sa = new Hash();
		((Hash*)sa)->buildIndex();
		break;
	case 3:
		sa = new BinarySearch();
		break;
	}
}
