#include "App.h"

App::App()
{
}

App::~App()
{
	writeFile();
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
		cout << "����������������������������������" << endl;
		cout << "��                              ��" << endl;
		cout << "��     ��   DDoseogwan   ��     ��" << endl;
		cout << "��                              ��" << endl;
		cout << "����������������������������������" << endl;
		cout << "����������������������������������" << endl;
		cout << "���� �б� ��� ����" << endl;
		cout << "1. Binary ���" << endl;
		cout << "2. Text ���" << endl;
		cout << "0. ���α׷� ����" << endl;
		cout << "����������������������������������" << endl;
		int num = GetCommand(2);
		if (num == 0)
		{
			return;
		}
		else
		{
			readFile(num);
			login();
		}
	}
}

void App::startmenu()
{
	while (1)
	{
		system("cls");
		cout << "����������������������������������" << endl;
		cout << "��                              ��" << endl;
		cout << "��     ��   DDoseogwan   ��     ��" << endl;
		cout << "��                              ��" << endl;
		cout << "����������������������������������" << endl;
		cout << "����������������������������������" << endl;
		cout << "��" << loginedUser->getname() << "�� ȯ���մϴ�!" << endl;
		cout << "����������������������������������" << endl;
		cout << "1. ���� �˻� �� �뿩" << endl;
		cout << "2. ���� �ݳ�" << endl;
		cout << "0. �ڷ� ����" << endl;
		cout << "����������������������������������" << endl;
		int num = GetCommand(2);
		cout << "����������������������������������" << endl;
		switch (num)
		{
		case 1:
			searchBook();
			break;
		case 2:
			returnBook();
			break;
		case 0:
			loginedUser = nullptr;
			cout << "�ڵ� �α׾ƿ� �Ǿ����ϴ�" << endl;
			cout << "����������������������������������" << endl;
			system("pause");
			system("cls");
			return;
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
				loginedUser = userList[i];
				system("pause");
				startmenu();
				return;
			}
			else
			{
				cout << "��й�ȣ�� ��ġ���� �ʽ��ϴ�" << endl;
				system("pause");
				system("cls");
				return;
			}
		}
	}
	cout << "��ġ�ϴ� ���̵� �����ϴ�" << endl;
	system("pause");
	system("cls");
	return;
}

void App::readFile(int num)
{
	switch (num)
	{
	case 1:
		fr = new BinaryReader();
		fr->readUserFile(&userList);
		fr->readBookFile(&bookList);
		break;
	case 2:
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
	for (int i = 0; i < (int)userList.size(); i++)
	{
		ofs << userList[i]->getid() << "\t";
		ofs << userList[i]->getpw() << "\t";
		ofs << userList[i]->getname() << "\t";
		ofs << userList[i]->GetborrowingList().size();
		for (int j = 0; j < userList[i]->GetborrowingList().size(); j++)
		{
			ofs << "\t" << userList[i]->GetborrowingList()[j];
		}
		if (i != (int)userList.size() - 1)
		{
			ofs << endl;
		}
	}
	ofs.close();
	// Write UserText

	ofstream ofs2("UserBinary.dat", ios::binary | ios::out);
	for (int i = 0; i < userList.size(); i++)
	{
		int id = userList[i]->getid();
		int p_len = userList[i]->getpw().size();
		int n_len = userList[i]->getname().size();
		int borrowed_num = userList[i]->GetborrowingList().size();
		string pw = userList[i]->getpw();
		string name = userList[i]->getname();

		ofs2.write((char*)&id, sizeof(int)); // ���̵�
		ofs2.write((char*)&p_len, sizeof(int)); // ��й�ȣ ����
		ofs2.write(pw.c_str(), p_len); // ��й�ȣ
		ofs2.write((char*)&n_len, sizeof(int)); // �̸� ����
		ofs2.write(name.c_str(), n_len); // �̸�
		ofs2.write((char*)&borrowed_num, sizeof(int)); // �뿩�� å�� ��
		for (int j = 0; j < borrowed_num; j++)
		{
			int borrowedID = userList[i]->GetborrowingList()[j];
			ofs2.write((char*)&borrowedID, sizeof(int));
		}
	}
	ofs2.close();
	// Write UserBinary

	ofstream ofs3("BookText.txt");
	for (int i = 0; i < bookList.size(); i++)
	{
		ofs3 << bookList[i]->Getbookid() << "\t";
		ofs3 << bookList[i]->Getname() << "\t";
		ofs3 << bookList[i]->Getauthor() << "\t";
		ofs3 << bookList[i]->Getyear() << "\t";
		ofs3 << bookList[i]->Getisborrowed();
		if (bookList[i]->Getisborrowed() == true)
		{
			ofs3 << "\t" << bookList[i]->GetborrwedID();
		}
		// �뿩�ڰ� �ִ� ���
		if (i != (int)bookList.size() - 1)
		{
			ofs3 << endl;
		}
		// �뿩�ڰ� ������ �뿩�� ID�� �������� �ʴ´�.
	}
	ofs3.close();
	// Write BookText
}

void App::searchBook()
{
	buildIndex();
	string key;
	cout << "�������� �Է��� �ּ���" << endl;
	cout << "�� : ";
	cin >> key;
	cout << "����������������������������������" << endl;
	vector<Book*> tempResult1;
	tempResult1 = (sa->search(key)); // å �̸����� �˻� ���
	if (tempResult1.size() == 0)
	{
		cout << "ã�� ������ �����ϴ�." << endl;
		cout << "����������������������������������" << endl;
		return;
	}

	string author;
	int year;
	vector<Book*> tempResult2; // ���ڸ����� �߰� �˻�
	vector<Book*> finalResult; // ���ǳ⵵�� �߰� �˻�
	
	cout << "���ڸ��� �Է��� �ּ���" << endl;
	cout << "�� : ";
	cin >> author;
	cout << "����������������������������������" << endl;
	for (int i = 0; i < tempResult1.size(); i++)
	{
		if (author == tempResult1.at(i)->Getauthor())
		{
			tempResult2.push_back(tempResult1.at(i));
		}
	}
	// ���ڸ� �˻�

	cout << "���ǳ⵵�� �Է��� �ּ���" << endl;
	cout << "�� : ";
	cin >> year;
	cout << "����������������������������������" << endl;
	for (int i = 0; i < tempResult2.size(); i++)
	{
		if (year == tempResult2.at(i)->Getyear())
		{
			finalResult.push_back(tempResult2.at(i));
		}
	}
	// ���ǳ⵵ �˻�
	if (finalResult.size() != 0)
	{
		cout << "����������ã�� ���� ��Ϧ���������" << endl;
	}
	while (1)
	{
		for (int i = 0; i < finalResult.size(); i++)
		{
			cout << i+1 << ". ";
			cout << "������: " << finalResult.at(i)->Getname() << endl;
			cout << "   ���ڸ�: " << finalResult.at(i)->Getauthor() << endl;
			cout << "   ���� ����: " << finalResult.at(i)->Getyear() << endl;
		}
		cout << "����������������������������������" << endl;
		cout << "1. ���� �뿩" << endl;
		cout << "0. �ڷ� ����" << endl;
		int cmd1 = GetCommand(1);
		switch (cmd1)
		{
		case 1:
			borrowBook(finalResult);
			finalResult.clear();
			return;
		case 0:
			return;
		}
	}
}

void App::borrowBook(vector<Book*> searchbook)
{
	// �Ķ������ searchbook�� search �Լ��� ��������� ���� ����Ʈ�� ������ ����
	system("pause");
	system("cls");
	cout << "����������������������������������" << endl;
	cout << "��                              ��" << endl;
	cout << "��     ��   ���� �뿩    ��     ��" << endl;
	cout << "��                              ��" << endl;
	cout << "����������������������������������" << endl;
	cout << "����������������������������������" << endl;
	cout << "�뿩�� ������ �����ϼ���" << endl;
	for (int i = 0; i < searchbook.size(); i++)
	{
		cout << i+1 << ". ";
		cout << "������: " << searchbook[i]->Getname() << endl;
		cout << "   ���ڸ�: " << searchbook[i]->Getauthor() << endl;
		cout << "   ���� ����: " << searchbook[i]->Getyear() << endl;
	}
	int num = GetCommand(searchbook.size()) -1;
	if (searchbook[num]->Getisborrowed() == true)
	{
		cout << "�̹� �뿩�� å �Դϴ�" << endl;
		cout << "����������������������������������" << endl;
		return;
	}
	else if (loginedUser->GetborrowingList().size() > 5)
	{
		cout << "�� �̻� �뿩�� �� �����ϴ�" << endl;
		cout << "����������������������������������" << endl;
		return;
	}
	/// Bookbinary Code
	fstream fs("BookBinary.dat", ios::binary | ios::in | ios::out); // ���̳ʸ�/�б�/����
	int BookID;
	int BNameLength;
	int AuthorLength;
	bool Borrow = true; // �뿩
	int BorrowID = loginedUser->getid(); // �뿩�� id
	for (int i = 0; i < bookList.size(); i++)
	{
		fs.read((char*)&BookID, sizeof(int)); // å�� ���̵� �о��(�뿩�� å�� ���ϱ� ����)
		fs.read((char*)&BNameLength, sizeof(int)); // å �̸� ���̸�ŭ �о
		fs.seekg(BNameLength, ios::cur); // seekg�Լ��� �ǳʶ� (å �̸��� BNameLength��ŭ�� �����̸�, �ѹ��ڴ� char�� �ش��ϹǷ� 1byte�̴�. ���� *1 ���ִ°Ͱ� ����)
		fs.read((char*)&AuthorLength, sizeof(int)); // ���� �̸� ���� �о
		fs.seekg(AuthorLength + sizeof(int), ios::cur); // �����̸�+���ǿ��� �ǳʶ�

		if (BookID == searchbook[num]->Getbookid())
			// �뿩�� å�� �ش�
			// ������ġ�� �뿩���ο� �뿩�� ���̵� �����!
		{
			fs.write((char*)&Borrow, sizeof(bool)); // �뿩�ߴ� : true�� ����
			fs.write((char*)&BorrowID, sizeof(int)); // �뿩�� ���̵� : �α����� ������ ID�� ����
		}
		else
		{
			fs.seekg(sizeof(bool) + sizeof(int), ios::cur);
			// ã�� ������ �ƴ� ��� �뿩����(bool) + �뿩�ھ��̵�(int) �ǳʶ�
		}
	}

	for (int j = 0; j < bookList.size(); j++)
	{
		if (bookList[j]->Getbookid() == searchbook[num]->Getbookid()) // ���� bookList���� ������ �����ϱ� ���� searchbook�� �����Ͽ� ������ ã�´�.
		{
			loginedUser->setborrowingList(bookList[j]->Getbookid());
			bookList[j]->SetBorrowed(true);
			bookList[j]->SetBorrowerID(loginedUser->getid());
			// å�� ������ ����
		}
	}
	cout << "å �뿩�� �Ϸ�Ǿ����ϴ�." << endl;
	cout << "����������������������������������" << endl;
	system("pause");

	return;
}

void App::returnBook()
{
	vector<Book*> BorrowedBook; // �α����� ������ �뿩����� ��� �ӽ� ����
	for (int i = 0; i < bookList.size(); i++)
	{
		for (int j = 0; j < loginedUser->GetborrowingList().size(); j++)
		{
  			if (loginedUser->GetborrowingList()[j] == bookList[i]->Getbookid())
			{
				BorrowedBook.push_back(bookList[i]);
			}
		}
	}
	system("pause");
	system("cls");
	cout << "����������������������������������" << endl;
	cout << "��                              ��" << endl;
	cout << "��     ��   ���� �ݳ�    ��     ��" << endl;
	cout << "��                              ��" << endl;
	cout << "����������������������������������" << endl;
	cout << "����������������������������������" << endl;
	if (BorrowedBook.size() == 0)
	{
		cout << "�ݳ��� ������ �����ϴ�" << endl;
		cout << "����������������������������������" << endl;
		return;
	}
	cout <<"������" << loginedUser->getname() << "���� �뿩��Ϧ�����" << endl;
	for (int i = 0; i < BorrowedBook.size(); i++)
	{
		cout << i + 1 << ". ";
		cout << "å �̸�: " << BorrowedBook.at(i)->Getname() << endl;
		cout << "���ڸ�: " << BorrowedBook.at(i)->Getauthor() << endl;
		cout << "���� ����: " << BorrowedBook.at(i)->Getyear() << endl << endl;
		// å�� ������ ���
	}
	cout << "����������������������������������" << endl;
	cout << "�ݳ��� ������ �����ϼ���" << endl;
	int num = GetCommand(BorrowedBook.size()) - 1;

	/// bookList���� �ش� ������ ���ڵ� ����
	vector<int> list = loginedUser->GetborrowingList();
	for (int i = 0; i < bookList.size(); i++)
	{
		if (bookList[i]->Getbookid() == BorrowedBook[num]->Getbookid())
		{
			// �ݳ��� å�� ã�Ҵ�!
			for (int j = 0; j < loginedUser->GetborrowingList().size(); j++)
			{
				if (loginedUser->GetborrowingList()[j] == bookList[i]->Getbookid())
				{
					list.erase(list.begin() + j);
					loginedUser->ResetBorrowingList(list);
					//loginedUser->GetborrowingList().erase(loginedUser->GetborrowingList().begin() + j); // ������ ���� ����??
				}
				// �뿩��Ͽ��� �����
			}
			bookList[i]->SetBorrowed(false);
			bookList[i]->SetBorrowerID(-1);
		 	// å�� �����͸� �����Ѵ�.
		}
	}

	/// Bookbinary Code
	fstream fs("BookBinary.dat", ios::binary | ios::in | ios::out); // ���̳ʸ�/�б�/����
	int BookID;
	int BNameLength;
	int AuthorLength;
	bool returned = false;
	int returnedID = -1;
	for (int i = 0; i < bookList.size(); i++)
	{
		fs.read((char*)&BookID, sizeof(int));
		fs.read((char*)&BNameLength, sizeof(int)); // å �̸� ���̸�ŭ �о
		fs.seekg(BNameLength, ios::cur); // seekg�Լ��� �ǳʶ�
		fs.read((char*)&AuthorLength, sizeof(int)); // ���� �̸� ���� �о
		fs.seekg(AuthorLength + sizeof(int), ios::cur); // �����̸�+���ǿ��� �ǳʶ�

														/// ������ؼ� read �Լ��ᵵ curpointer�� �̵��ϴ��� Ȯ��
		if (BookID == BorrowedBook[num]->Getbookid())
			// �ݳ��� �ش��ϴ� �����
			// ������ġ�� �뿩���ο� �뿩�� ���̵� �����!
		{
			fs.write((char*)&returned, sizeof(bool));
			fs.write((char*)&returnedID, sizeof(int));
		}
		else
		{
			fs.seekg(sizeof(bool) + sizeof(int), ios::cur);
			// ã�� ������ �ƴ� ��� �뿩����(bool) + �뿩�ھ��̵�(int) �ǳʶ�
		}
	}

	cout << "���� �ݳ��� �Ϸ��Ͽ����ϴ�." << endl;
	cout << "����������������������������������" << endl;
	system("pause");
}

void App::buildIndex()
{
	cout << "1. Binary Search Tree" << endl;
	cout << "2. Hash" << endl;
	cout << "3. Binary Search" << endl;
	int command = GetCommand(3);

	switch (command)
	{
	case 1:
		system("cls");
		cout << "����������������������������������" << endl;
		cout << "��                              ��" << endl;
		cout << "��   �� Binary Search Tree ��   ��" << endl;
		cout << "��                              ��" << endl;
		cout << "����������������������������������" << endl;
		cout << "����������������������������������" << endl;
		sa = new BST(&bookList);
		((BST*)sa)->buildIndex();
		break;
	case 2:
		system("cls");
		cout << "����������������������������������" << endl;
		cout << "��                              ��" << endl;
		cout << "��          �� Hash ��          ��" << endl;
		cout << "��                              ��" << endl;
		cout << "����������������������������������" << endl;
		cout << "����������������������������������" << endl;
		sa = new Hash(&bookList);
		((Hash*)sa)->buildIndex();
		break;
	case 3:
		system("cls");
		cout << "����������������������������������" << endl;
		cout << "��                              ��" << endl;
		cout << "��     ��  Binary Search ��     ��" << endl;
		cout << "��                              ��" << endl;
		cout << "����������������������������������" << endl;
		cout << "����������������������������������" << endl;
		sa = new BinarySearch(&bookList);
		break;
	}
}