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
		cout << "▶ : ";
		cin >> command;

		if (cin.fail())
		{
			cout << "│올바르지 않은 입력입니다" << endl;
			cin.clear();
			cin.ignore(256, '\n'); // cin시 오류잡아주는 코드 
		}
		else
		{
			if (command <= maxCommand && command >= 0)
			{
				return command;
			}
			else
			{
				cout << "│올바르지 않은 입력입니다" << endl;
			}
		}
	}
	cout << "─────────────────" << endl;
}

void App::run()
{
	while (1)
	{
		//int num = Getcommand() 식으로 바꾸자
		int num = GetCommand(1);
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
		cout << "1. 도서 검색 및 대여" << endl;
		cout << "2. 도서 반납" << endl;
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
	vector<Book*>tempResult1;

	if (sa->search(key) == nullptr)
	{
		cout << "찾는 도서가 없습니다." << endl;
	}
	tempResult1 = *(sa->search(key)); // 책 이름으 로 검색

	string author;
	int year;
	vector<Book*>tempResult2; // 저자명으로 추가 검색
	vector<Book*>finalResult; // 출판년도로 추가 검색
	
	for (int i = 0; i < tempResult1.size(); i++)
	{
		if (author == tempResult1[i]->Getauthor())
		{
			tempResult2.push_back(tempResult1[i]);
		}
	}
	// 저자명 검색

	for (int i = 0; i < tempResult2.size(); i++)
	{
		if (year == tempResult2[i]->Getyear())
		{
			finalResult.push_back(tempResult2[i]);
		}
	}
	// 출판년도 검색
	while (1)
	{
		for (int i = 0; i < finalResult.size(); i++)
		{
			cout << i << ". ";
			cout << "책 이름: " << finalResult[i]->Getname();
			cout << "저자명: " << finalResult[i]->Getauthor();
			cout << "출판 연도: " << finalResult[i]->Getyear() << endl;
		}
		cout << endl;
		cout << "1. 도서 대여" << endl;
		cout << "0. 뒤로 가기" << endl;
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
	cout << "대여할 책 선택: " << endl;
	for (int i = 0; i < searchbook.size(); i++)
	{
		cout << i << ". ";
		cout << "책 이름: " << searchbook[i]->Getname();
		cout << "저자명: " << searchbook[i]->Getauthor();
		cout << "출판 연도: " << searchbook[i]->Getyear() << endl;
	}
	int num = GetCommand(searchbook.size());
	if (loginedUser->GetborrowingList().size() > 5)
	{
		cout << "더 이상 대여할 수 없습니다! 한번에 다섯권 이상 대여하실 수 없습니다." << endl;
	}
	loginedUser->GetborrowingList().push_back(searchbook[num]->Getbookid()); // 로그인한 유저의 대여책 리스트에 저장
	searchbook[num]->SetBorrowed(true); // 대여된 책임을 명시
	searchbook[num]->SetBorrowerID(loginedUser->getid()); // 책에 대여자의 아이디 명시
	cout << "책 대여가 완료되었습니다." << endl;
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