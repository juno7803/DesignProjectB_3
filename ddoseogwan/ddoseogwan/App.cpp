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
		//int num = Getcommand() 식으로 바꾸자
		int num = 0;
		cout << "파일 읽기 모드 설정" << endl;
		cout << "1. Binary 모드" << endl;
		cout << "0. Text 모드" << endl;
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
		cout << "1. 도서 검색 및 대여" << endl;
		cout << "2. 도서 반납" << endl;
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

	cout << "┌아이디를 입력하세요 : ";
	cin >> id;
	cout << "└비밀번호를 입력하세요 : ";
	cin >> pw;
	for (int i = 0; i < userList.size(); i++)
	{
		if (id == userList[i]->getid())
		{
			if (pw == userList[i]->getpw())
			{
				cout << "▷" << userList[i]->getname() << "님 환영합니다!" << endl;
				cout << "─────────────────" << endl;
				loginedUser = userList[i];
				startmenu();
			}
			else
			{
				cout << "비밀번호가 일치하지 않습니다" << endl;
				return;
			}
		}
	}
	cout << "일치하는 아이디가 없습니다" << endl;
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
	cout << "책 이름 입력: ";
	cin >> key;
	sa->search(key);
	if (sa->search(key) == nullptr)
	{
		cout << "찾는 도서가 없습니다." << endl;
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
