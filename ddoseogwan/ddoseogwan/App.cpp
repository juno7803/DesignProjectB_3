#include "App.h"

App::App()
{
}


App::~App()
{
}

int App::GetCommand(int maxCommand)
{
	while (true)
	{
		int command;
		cout << "�� : ";
		cin >> command;

		if (cin.fail())
		{
			cout << "���ùٸ��� ���� �Է��Դϴ�" << endl;
			cin.clear();
			cin.ignore(256, '\n'); // cin�� ��������ִ� �ڵ� 
		}
		else
		{
			if (command <= maxCommand && command >= 0)
			{
				return command;
			}
			else
			{
				cout << "���ùٸ��� ���� �Է��Դϴ�" << endl;
			}
		}
	}
	cout << "����������������������������������" << endl;
}

void App::run()
{
	while (1)
	{
		//int num = Getcommand() ������ �ٲ���
		int num = GetCommand(1);
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
		cout << "1. ���� �˻� �� �뿩" << endl;
		cout << "2. ���� �ݳ�" << endl;
		int num = GetCommand(2);
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
	vector<Book*>tempResult1;

	if (sa->search(key) == nullptr)
	{
		cout << "ã�� ������ �����ϴ�." << endl;
	}
	tempResult1 = *(sa->search(key)); // å �̸��� �� �˻�

	string author;
	int year;
	vector<Book*>tempResult2; // ���ڸ����� �߰� �˻�
	vector<Book*>finalResult; // ���ǳ⵵�� �߰� �˻�
	
	for (int i = 0; i < tempResult1.size(); i++)
	{
		if (author == tempResult1[i]->Getauthor())
		{
			tempResult2.push_back(tempResult1[i]);
		}
	}
	// ���ڸ� �˻�

	for (int i = 0; i < tempResult2.size(); i++)
	{
		if (year == tempResult2[i]->Getyear())
		{
			finalResult.push_back(tempResult2[i]);
		}
	}
	// ���ǳ⵵ �˻�
	while (1)
	{
		for (int i = 0; i < finalResult.size(); i++)
		{
			cout << i << ". ";
			cout << "å �̸�: " << finalResult[i]->Getname();
			cout << "���ڸ�: " << finalResult[i]->Getauthor();
			cout << "���� ����: " << finalResult[i]->Getyear() << endl;
		}
		cout << endl;
		cout << "1. ���� �뿩" << endl;
		cout << "0. �ڷ� ����" << endl;
		int cmd1 = GetCommand(1);
		switch (cmd1)
		{
		case 1:
			system("pause");
			system("cls");
			borrowBook(finalResult);
			break;
		case 2:
			return;  
		}
	}
}

void App::borrowBook(vector<Book*> searchbook)
{
	cout << "�뿩�� å ����: " << endl;
	for (int i = 0; i < searchbook.size(); i++)
	{
		cout << i << ". ";
		cout << "å �̸�: " << searchbook[i]->Getname();
		cout << "���ڸ�: " << searchbook[i]->Getauthor();
		cout << "���� ����: " << searchbook[i]->Getyear() << endl;
	}
	int num = GetCommand(searchbook.size());
	if (loginedUser->GetborrowingList().size() > 5)
	{
		cout << "�� �̻� �뿩�� �� �����ϴ�! �ѹ��� �ټ��� �̻� �뿩�Ͻ� �� �����ϴ�." << endl;
	}
	loginedUser->GetborrowingList().push_back(searchbook[num]->Getbookid()); // �α����� ������ �뿩å ����Ʈ�� ����
	searchbook[num]->SetBorrowed(true); // �뿩�� å���� ���
	searchbook[num]->SetBorrowerID(loginedUser->getid()); // å�� �뿩���� ���̵� ���
	cout << "å �뿩�� �Ϸ�Ǿ����ϴ�." << endl;
}

void App::returnBook()
{
	loginedUser->
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
		sa = new BST(&bookList);
		((BST*)sa)->buildIndex();
		break;
	case 2:
		sa = new Hash(&bookList);
		((Hash*)sa)->buildIndex();
		break;
	case 3:
		sa = new BinarySearch();
		break;
	}
}