#include "BinaryReader.h"



BinaryReader::BinaryReader()
{
}


BinaryReader::~BinaryReader()
{
}

void BinaryReader::readUserFile(vector<User*>* _userList)
// ���� UserDB��� ���غ�
{
	ifstream ifs;
	ifs.open("UserBinary.dat", ios::binary | ios::in);
	int id, pwString, nString, borrowNum, bookID;
	string pw, name;
	vector<int> borrowlist;
	//id(����) ��й�ȣ����(����) ��й�ȣ(��Ʈ��) �̸�����(����) �̸�(��Ʈ��) �뿩��å�Ǽ�(����) �뿩��å�Ǿ��̵�(��������Ʈ)
	int oldID = -1;

	while (1)
	{
		ifs.read((char*)&id, sizeof(int));
		if (oldID == id)
		{
			break; // ��������
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
	//id(����) å�̸�����(����) å�̸�(��Ʈ��) �����̸�����(����) �����̸�(��Ʈ��) ���ǳ⵵(����) �뿩����(����) �뿩�ھ��̵�(����)

	//ifs.seekg(0, ios::beg); // ��ó���� ����Ű�� ��
	int oldID=-2;

	while (1)  // ��� 2
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
			temp->SetBorrowerID(-1); // �뿩�ڰ� ���°�� ���̵�� -1�� �Ѵ�.
		}
		_bookList->push_back(temp);
		oldID = id;
	}
	ifs.close();
}
