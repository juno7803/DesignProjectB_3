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
		cout << "파일 읽기 모드 설정" << endl;
		cout << "1. Binary 모드" << endl;
		cout << "0. Text 모드" << endl;
		int num = GetCommand(1);
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

void App::writeFile()
// UserT,UserB,BookT는 아예 첨부터 다시 써주고
// BookB만 바뀔때마다 써주면 된다!
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
		// 대여자가 있는 경우
		else
		{
			ofs << bookList[i]->Getisborrowed() << "\n";
		}
		// 대여자가 없으면 대여자 ID는 저장하지 않는다.
	}
}

void App::searchBook()
{
	buildIndex();
	string key;
	cout << "책 이름 입력: ";
	cin >> key;
	vector<Book*> tempResult1;
	tempResult1 = (sa->search(key)); // 책 이름으로 검색 결과
	if (tempResult1.size() == 0)
	{
		cout << "찾는 도서가 없습니다." << endl;
		return;
	}

	string author;
	int year;
	vector<Book*> tempResult2; // 저자명으로 추가 검색
	vector<Book*> finalResult; // 출판년도로 추가 검색
	
	cout << "찾는 책의 저자명: ";
	cin >> author;
	for (int i = 0; i < tempResult1.size(); i++)
	{
		if (author == tempResult1.at(i)->Getauthor())
		{
			tempResult2.push_back(tempResult1.at(i));
		}
	}
	// 저자명 검색

	cout << "찾는 책의 출판년도: ";
	cin >> year;
	for (int i = 0; i < tempResult2.size(); i++)
	{
		if (year == tempResult2.at(i)->Getyear())
		{
			finalResult.push_back(tempResult2.at(i));
		}
	}
	// 출판년도 검색
	while (1)
	{
		for (int i = 0; i < finalResult.size(); i++)
		{
			cout << i << ". ";
			cout << "책 이름: " << finalResult.at(i)->Getname();
			cout << "저자명: " << finalResult.at(i)->Getauthor();
			cout << "출판 연도: " << finalResult.at(i)->Getyear() << endl;
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
	int num = GetCommand(searchbook.size()) + 1;
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
	vector<Book*>* BorrowedBook; // 여기 주소를 담아야 이 임시벡터에서 대여여부 변수를 바꿔도 바뀜
	for (int i = 0; i < bookList.size(); i++)
	{
		if (loginedUser->GetborrowingList()[i] == bookList[i]->Getbookid())
		{
			BorrowedBook->push_back(bookList[i]);
		}
	}
	cout << loginedUser->getname() << "님의 대여목록" << endl;
	for (int i = 0; i < BorrowedBook->size(); i++)
	{
		cout << i + 1 << ". ";
		cout << "책 이름: " << BorrowedBook->at(i)->Getname() << endl;
		cout << "저자명: " << BorrowedBook->at(i)->Getauthor() << endl;
		cout << "출판 연도: " << BorrowedBook->at(i)->Getyear() << endl << endl;
	}
	int num = GetCommand(BorrowedBook->size()) + 1;
	for (int j = 0; j < BorrowedBook->size(); j++)
	{
		if (loginedUser->GetborrowingList().at(num-1) == BorrowedBook->at(j)->Getbookid())
		{
			loginedUser->GetborrowingList().erase(loginedUser->GetborrowingList().begin() + num - 1); // 해당 유저의 대여목록에서 제외한다.
			BorrowedBook->at(j)->SetBorrowerID(-1); // 반납한 책의 대여자ID는 -1로 한다.
			BorrowedBook->at(j)->SetBorrowed(false); // 반납한 책의 대여여부는 false로 바꾼다.
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