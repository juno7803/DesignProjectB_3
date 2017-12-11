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
		cout << "���� �б� ��� ����" << endl;
		cout << "1. Binary ���" << endl;
		cout << "0. Text ���" << endl;
		int num = GetCommand(1);
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

void App::writeFile()
// UserT,UserB,BookT�� �ƿ� ÷���� �ٽ� ���ְ�
// BookB�� �ٲ𶧸��� ���ָ� �ȴ�!
{
	ofstream ofs("UserText.txt");
	for (int i = 0; i < userList.size(); i++)
	{
		ofs << userList[i]->getid() << "\t";
		ofs << userList[i]->getpw() << "\t";
		ofs << userList[i]->getname() << "\t";
		ofs << userList[i]->GetborrowingList().size() << "\t";
		for (int j = 0; j < userList[i]->GetborrowingList().size(); j++)
		{
			if (j == userList[i]->GetborrowingList().size())
				ofs << userList[i]->GetborrowingList()[j] << "\n";
			ofs << userList[i]->GetborrowingList()[j] << "\t";
		}
	}
	ofs.close();
	// Write UserText

	ofstream ofs2("UserBinary.dat", ios::binary);

	ofstream ofs3("BookText.txt");
	for (int i = 0; i < bookList.size(); i++)
	{
		ofs << bookList[i]->Getbookid() << "\t";
		ofs << bookList[i]->Getname() << "\t";
		ofs << bookList[i]->Getauthor() << "\t";
		ofs << bookList[i]->Getyear() << "\t";
		if (bookList[i]->Getisborrowed() == true)
		{
			ofs << bookList[i]->Getisborrowed() << "\t";
			ofs << bookList[i]->GetborrwedID() << "\n";
		}
		// �뿩�ڰ� �ִ� ���
		else
		{
			ofs << bookList[i]->Getisborrowed() << "\n";
		}
		// �뿩�ڰ� ������ �뿩�� ID�� �������� �ʴ´�.
	}
}

void App::searchBook()
{
	buildIndex();
	string key;
	cout << "å �̸� �Է�: ";
	cin >> key;
	vector<Book*> tempResult1;
	tempResult1 = (sa->search(key)); // å �̸����� �˻� ���
	if (tempResult1.size() == 0)
	{
		cout << "ã�� ������ �����ϴ�." << endl;
		return;
	}

	string author;
	int year;
	vector<Book*> tempResult2; // ���ڸ����� �߰� �˻�
	vector<Book*> finalResult; // ���ǳ⵵�� �߰� �˻�
	
	cout << "ã�� å�� ���ڸ�: ";
	cin >> author;
	for (int i = 0; i < tempResult1.size(); i++)
	{
		if (author == tempResult1.at(i)->Getauthor())
		{
			tempResult2.push_back(tempResult1.at(i));
		}
	}
	// ���ڸ� �˻�

	cout << "ã�� å�� ���ǳ⵵: ";
	cin >> year;
	for (int i = 0; i < tempResult2.size(); i++)
	{
		if (year == tempResult2.at(i)->Getyear())
		{
			finalResult.push_back(tempResult2.at(i));
		}
	}
	// ���ǳ⵵ �˻�
	while (1)
	{
		for (int i = 0; i < finalResult.size(); i++)
		{
			cout << i << ". ";
			cout << "å �̸�: " << finalResult.at(i)->Getname();
			cout << "���ڸ�: " << finalResult.at(i)->Getauthor();
			cout << "���� ����: " << finalResult.at(i)->Getyear() << endl;
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
	int num = GetCommand(searchbook.size()) + 1;
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
	vector<Book*>* BorrowedBook; // ���� �ּҸ� ��ƾ� �� �ӽú��Ϳ��� �뿩���� ������ �ٲ㵵 �ٲ�
	for (int i = 0; i < bookList.size(); i++)
	{
		if (loginedUser->GetborrowingList()[i] == bookList[i]->Getbookid())
		{
			BorrowedBook->push_back(bookList[i]);
		}
	}
	cout << loginedUser->getname() << "���� �뿩���" << endl;
	for (int i = 0; i < BorrowedBook->size(); i++)
	{
		cout << i + 1 << ". ";
		cout << "å �̸�: " << BorrowedBook->at(i)->Getname() << endl;
		cout << "���ڸ�: " << BorrowedBook->at(i)->Getauthor() << endl;
		cout << "���� ����: " << BorrowedBook->at(i)->Getyear() << endl << endl;
	}
	int num = GetCommand(BorrowedBook->size()) + 1;
	for (int j = 0; j < BorrowedBook->size(); j++)
	{
		if (loginedUser->GetborrowingList().at(num-1) == BorrowedBook->at(j)->Getbookid())
		{
			loginedUser->GetborrowingList().erase(loginedUser->GetborrowingList().begin() + num - 1); // �ش� ������ �뿩��Ͽ��� �����Ѵ�.
			BorrowedBook->at(j)->SetBorrowerID(-1); // �ݳ��� å�� �뿩��ID�� -1�� �Ѵ�.
			BorrowedBook->at(j)->SetBorrowed(false); // �ݳ��� å�� �뿩���δ� false�� �ٲ۴�.
		}
	}
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