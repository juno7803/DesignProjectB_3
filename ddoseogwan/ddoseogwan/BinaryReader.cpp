#include "BinaryReader.h"



BinaryReader::BinaryReader()
{
}


BinaryReader::~BinaryReader()
{
}

void BinaryReader::readUserFile(vector<User*>* _userList)
// 아직 UserDB없어서 못해봄
{
	ifstream ifs;
	ifs.open("UserBinary.dat", ios::binary | ios::in);
	int id, pwString, nString, borrowNum, bookID;
	string pw, name;
	vector<int> borrowlist;
	//id(정수) 비밀번호길이(정수) 비밀번호(스트링) 이름길이(정수) 이름(스트링) 대여한책의수(정수) 대여한책의아이디(정수리스트)
	int oldID = -1;

	while (1)
	{
		ifs.read((char*)&id, sizeof(int));
		if (oldID == id)
		{
			break; // 종료조건
		}
		ifs.read((char*)&pwString, sizeof(int));
		
		pw.resize(pwString);
		ifs.read(&pw[0], pwString);

		ifs.read((char*)&nString, sizeof(int));

		name.resize(nString);
		ifs.read(&name[0], nString);

		ifs.read((char*)&borrowNum, sizeof(int));
		User* temp = new User(id, pw, name);
		for (int i = 0; i < borrowNum; i++)
		{
			ifs.read((char*)&bookID, sizeof(int));
			temp->setborrowingList(bookID);
		}
		_userList->push_back(temp);
		oldID = id;
	}
	ifs.close();
}

void BinaryReader::readBookFile(vector<Book*>* _bookList)
{
	ifstream ifs;
	ifs.open("BookBinary.dat",ios::binary | ios::in);
	int id, bString, auString, year, borrowerID;
	bool isborrowed;
	string bname, author;
	//id(정수) 책이름길이(정수) 책이름(스트링) 저자이름길이(정수) 저자이름(스트링) 출판년도(정수) 대여여부(정수) 대여자아이디(정수)

	//ifs.seekg(0, ios::beg); // 맨처음을 가르키게 함
	int oldID=-2;

	while (1)  // 방법 2
	{
		ifs.read((char*)&id, sizeof(int));
		if (oldID == id)
		{
			break;
		}

		ifs.read((char*)&bString, sizeof(int));
		bname.resize(bString);
		ifs.read(&bname[0], bString);

		ifs.read((char*)&auString, sizeof(int));
		author.resize(auString);
		ifs.read(&author[0], auString);
		
		ifs.read((char*)&year, sizeof(int));
		ifs.read((char*)&isborrowed, sizeof(bool));
		ifs.read((char*)&borrowerID, sizeof(int));

		Book* temp = new Book(id, bname, author, year, isborrowed);
		if (isborrowed == true)
		{
			temp->SetBorrowerID(borrowerID);
		}
		else if (isborrowed == false)
		{
			temp->SetBorrowerID(-1); // 대여자가 없는경우 아이디는 -1로 한다.
		}
		_bookList->push_back(temp);
		oldID = id;
	}
	ifs.close();
}
