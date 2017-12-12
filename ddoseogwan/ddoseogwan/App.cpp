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
		cout << "¢º : ";
		cin >> command;

		if (cin.fail())
		{
			cout << "¦¢¿Ã¹Ù¸£Áö ¾ÊÀº ÀÔ·ÂÀÔ´Ï´Ù" << endl;
			cin.clear();
			cin.ignore(256, '\n'); // cin½Ã ¿À·ùÀâ¾ÆÁÖ´Â ÄÚµå 
		}
		else
		{
			if (command <= maxCommand && command >= 0)
			{
				return command;
			}
			else
			{
				cout << "¦¢¿Ã¹Ù¸£Áö ¾ÊÀº ÀÔ·ÂÀÔ´Ï´Ù" << endl;
			}
		}
	}
	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
}

void App::run()
{
	while (1)
	{
		cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
		cout << "¦¢                              ¦¢" << endl;
		cout << "¦¢     ¢º   DDoseogwan   ¢¸     ¦¢" << endl;
		cout << "¦¢                              ¦¢" << endl;
		cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		cout << "ÆÄÀÏ ÀÐ±â ¸ðµå ¼³Á¤" << endl;
		cout << "1. Binary ¸ðµå" << endl;
		cout << "2. Text ¸ðµå" << endl;
		cout << "0. ÇÁ·Î±×·¥ Á¾·á" << endl;
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
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
		cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
		cout << "¦¢                              ¦¢" << endl;
		cout << "¦¢     ¢º   DDoseogwan   ¢¸     ¦¢" << endl;
		cout << "¦¢                              ¦¢" << endl;
		cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		cout << "¢¹" << loginedUser->getname() << "´Ô È¯¿µÇÕ´Ï´Ù!" << endl;
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		cout << "1. µµ¼­ °Ë»ö ¹× ´ë¿©" << endl;
		cout << "2. µµ¼­ ¹Ý³³" << endl;
		cout << "0. µÚ·Î °¡±â" << endl;
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		int num = GetCommand(2);
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
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
			cout << "ÀÚµ¿ ·Î±×¾Æ¿ô µÇ¾ú½À´Ï´Ù" << endl;
			cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
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

	cout << "¦£¾ÆÀÌµð¸¦ ÀÔ·ÂÇÏ¼¼¿ä : ";
	cin >> id;
	cout << "¦¦ºñ¹Ð¹øÈ£¸¦ ÀÔ·ÂÇÏ¼¼¿ä : ";
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
				cout << "ºñ¹Ð¹øÈ£°¡ ÀÏÄ¡ÇÏÁö ¾Ê½À´Ï´Ù" << endl;
				system("pause");
				system("cls");
				return;
			}
		}
	}
	cout << "ÀÏÄ¡ÇÏ´Â ¾ÆÀÌµð°¡ ¾ø½À´Ï´Ù" << endl;
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
// UserT,UserB,BookT´Â ¾Æ¿¹ Ã·ºÎÅÍ ´Ù½Ã ½áÁÖ°í
// BookB¸¸ ¹Ù²ð¶§¸¶´Ù ½áÁÖ¸é µÈ´Ù!
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

		ofs2.write((char*)&id, sizeof(int)); // ¾ÆÀÌµð
		ofs2.write((char*)&p_len, sizeof(int)); // ºñ¹Ð¹øÈ£ ±æÀÌ
		ofs2.write(pw.c_str(), p_len); // ºñ¹Ð¹øÈ£
		ofs2.write((char*)&n_len, sizeof(int)); // ÀÌ¸§ ±æÀÌ
		ofs2.write(name.c_str(), n_len); // ÀÌ¸§
		ofs2.write((char*)&borrowed_num, sizeof(int)); // ´ë¿©ÇÑ Ã¥ÀÇ ¼ö
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
		// ´ë¿©ÀÚ°¡ ÀÖ´Â °æ¿ì
		if (i != (int)bookList.size() - 1)
		{
			ofs3 << endl;
		}
		// ´ë¿©ÀÚ°¡ ¾øÀ¸¸é ´ë¿©ÀÚ ID´Â ÀúÀåÇÏÁö ¾Ê´Â´Ù.
	}
	ofs3.close();
	// Write BookText
}

void App::searchBook()
{
	buildIndex();
	string key;
	cout << "µµ¼­¸íÀ» ÀÔ·ÂÇØ ÁÖ¼¼¿ä" << endl;
	cout << "¢º : ";
	cin >> key;
	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
	vector<Book*> tempResult1;
	tempResult1 = (sa->search(key)); // Ã¥ ÀÌ¸§À¸·Î °Ë»ö °á°ú
	if (tempResult1.size() == 0)
	{
		cout << "Ã£´Â µµ¼­°¡ ¾ø½À´Ï´Ù." << endl;
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		return;
	}

	string author;
	int year;
	vector<Book*> tempResult2; // ÀúÀÚ¸íÀ¸·Î Ãß°¡ °Ë»ö
	vector<Book*> finalResult; // ÃâÆÇ³âµµ·Î Ãß°¡ °Ë»ö
	
	cout << "ÀúÀÚ¸íÀ» ÀÔ·ÂÇØ ÁÖ¼¼¿ä" << endl;
	cout << "¢º : ";
	cin >> author;
	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
	for (int i = 0; i < tempResult1.size(); i++)
	{
		if (author == tempResult1.at(i)->Getauthor())
		{
			tempResult2.push_back(tempResult1.at(i));
		}
	}
	// ÀúÀÚ¸í °Ë»ö

	cout << "ÃâÆÇ³âµµ¸¦ ÀÔ·ÂÇØ ÁÖ¼¼¿ä" << endl;
	cout << "¢º : ";
	cin >> year;
	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
	for (int i = 0; i < tempResult2.size(); i++)
	{
		if (year == tempResult2.at(i)->Getyear())
		{
			finalResult.push_back(tempResult2.at(i));
		}
	}
	// ÃâÆÇ³âµµ °Ë»ö
	if (finalResult.size() != 0)
	{
		cout << "¦¡¦¡¦¡¦¡¦¡Ã£Àº µµ¼­ ¸ñ·Ï¦¡¦¡¦¡¦¡¦¡" << endl;
	}
	while (1)
	{
		for (int i = 0; i < finalResult.size(); i++)
		{
			cout << i+1 << ". ";
			cout << "µµ¼­¸í: " << finalResult.at(i)->Getname() << endl;
			cout << "   ÀúÀÚ¸í: " << finalResult.at(i)->Getauthor() << endl;
			cout << "   ÃâÆÇ ¿¬µµ: " << finalResult.at(i)->Getyear() << endl;
		}
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		cout << "1. µµ¼­ ´ë¿©" << endl;
		cout << "0. µÚ·Î °¡±â" << endl;
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
	// ÆÄ¶ó¹ÌÅÍÀÇ searchbookÀº search ÇÔ¼öÀÇ ÃÖÁ¾°á°ú·Î ³ª¿Â ¸®½ºÆ®¸¦ ´ã°í¿À´Â º¤ÅÍ
	system("pause");
	system("cls");
	cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
	cout << "¦¢                              ¦¢" << endl;
	cout << "¦¢     ¢º   µµ¼­ ´ë¿©    ¢¸     ¦¢" << endl;
	cout << "¦¢                              ¦¢" << endl;
	cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
	cout << "´ë¿©ÇÒ µµ¼­¸¦ ¼±ÅÃÇÏ¼¼¿ä" << endl;
	for (int i = 0; i < searchbook.size(); i++)
	{
		cout << i+1 << ". ";
		cout << "µµ¼­¸í: " << searchbook[i]->Getname() << endl;
		cout << "   ÀúÀÚ¸í: " << searchbook[i]->Getauthor() << endl;
		cout << "   ÃâÆÇ ¿¬µµ: " << searchbook[i]->Getyear() << endl;
	}
	int num = GetCommand(searchbook.size()) -1;
	if (searchbook[num]->Getisborrowed() == true)
	{
		cout << "ÀÌ¹Ì ´ë¿©µÈ Ã¥ ÀÔ´Ï´Ù" << endl;
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		return;
	}
	else if (loginedUser->GetborrowingList().size() > 5)
	{
		cout << "´õ ÀÌ»ó ´ë¿©ÇÒ ¼ö ¾ø½À´Ï´Ù" << endl;
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		return;
	}
	/// Bookbinary Code
	fstream fs("BookBinary.dat", ios::binary | ios::in | ios::out); // ¹ÙÀÌ³Ê¸®/ÀÐ±â/¾²±â
	int BookID;
	int BNameLength;
	int AuthorLength;
	bool Borrow = true; // ´ë¿©
	int BorrowID = loginedUser->getid(); // ´ë¿©ÀÚ id
	for (int i = 0; i < bookList.size(); i++)
	{
		fs.read((char*)&BookID, sizeof(int)); // Ã¥ÀÇ ¾ÆÀÌµð¸¦ ÀÐ¾î¿È(´ë¿©ÇÒ Ã¥°ú ºñ±³ÇÏ±â À§ÇÔ)
		fs.read((char*)&BNameLength, sizeof(int)); // Ã¥ ÀÌ¸§ ±æÀÌ¸¸Å­ ÀÐ¾î¼­
		fs.seekg(BNameLength, ios::cur); // seekgÇÔ¼ö·Î °Ç³Ê¶Ü (Ã¥ ÀÌ¸§Àº BNameLength¸¸Å­ÀÇ ±æÀÌÀÌ¸ç, ÇÑ¹®ÀÚ´Â char¿¡ ÇØ´çÇÏ¹Ç·Î 1byteÀÌ´Ù. µû¶ó¼­ *1 ÇØÁÖ´Â°Í°ú °°´Ù)
		fs.read((char*)&AuthorLength, sizeof(int)); // ÀúÀÚ ÀÌ¸§ ±æÀÌ ÀÐ¾î¼­
		fs.seekg(AuthorLength + sizeof(int), ios::cur); // ÀúÀÚÀÌ¸§+ÃâÆÇ¿¬µµ °Ç³Ê¶Ü

		if (BookID == searchbook[num]->Getbookid())
			// ´ë¿©ÇÒ Ã¥¿¡ ÇØ´ç
			// ÇöÀçÀ§Ä¡¿¡ ´ë¿©¿©ºÎ¿Í ´ë¿©ÀÚ ¾ÆÀÌµð µ¤¾î¾´´Ù!
		{
			fs.write((char*)&Borrow, sizeof(bool)); // ´ë¿©Çß´Ù : true¸¦ ¾´´Ù
			fs.write((char*)&BorrowID, sizeof(int)); // ´ë¿©ÀÚ ¾ÆÀÌµð : ·Î±×ÀÎÇÑ À¯ÀúÀÇ ID¸¦ ¾´´Ù
		}
		else
		{
			fs.seekg(sizeof(bool) + sizeof(int), ios::cur);
			// Ã£´ø µµ¼­°¡ ¾Æ´Ò °æ¿ì ´ë¿©¿©ºÎ(bool) + ´ë¿©ÀÚ¾ÆÀÌµð(int) °Ç³Ê¶Ü
		}
	}

	for (int j = 0; j < bookList.size(); j++)
	{
		if (bookList[j]->Getbookid() == searchbook[num]->Getbookid()) // ¿ø·¡ bookList¿¡¼­ Á¤º¸¸¦ ¼öÁ¤ÇÏ±â À§ÇØ searchbook°ú ´ëÁ¶ÇÏ¿© ¿øº»À» Ã£´Â´Ù.
		{
			loginedUser->setborrowingList(bookList[j]->Getbookid());
			bookList[j]->SetBorrowed(true);
			bookList[j]->SetBorrowerID(loginedUser->getid());
			// Ã¥ÀÇ µ¥ÀÌÅÍ ¼öÁ¤
		}
	}
	cout << "Ã¥ ´ë¿©°¡ ¿Ï·áµÇ¾ú½À´Ï´Ù." << endl;
	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
	system("pause");

	return;
}

void App::returnBook()
{
	vector<Book*> BorrowedBook; // ·Î±×ÀÎÇÑ À¯ÀúÀÇ ´ë¿©¸ñ·ÏÀ» ´ã´Â ÀÓ½Ã º¤ÅÍ
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
	cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
	cout << "¦¢                              ¦¢" << endl;
	cout << "¦¢     ¢º   µµ¼­ ¹Ý³³    ¢¸     ¦¢" << endl;
	cout << "¦¢                              ¦¢" << endl;
	cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
	if (BorrowedBook.size() == 0)
	{
		cout << "¹Ý³³ÇÒ µµ¼­°¡ ¾ø½À´Ï´Ù" << endl;
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		return;
	}
	cout <<"¦¡¦¡¦¡" << loginedUser->getname() << "´ÔÀÇ ´ë¿©¸ñ·Ï¦¡¦¡¦¡" << endl;
	for (int i = 0; i < BorrowedBook.size(); i++)
	{
		cout << i + 1 << ". ";
		cout << "Ã¥ ÀÌ¸§: " << BorrowedBook.at(i)->Getname() << endl;
		cout << "ÀúÀÚ¸í: " << BorrowedBook.at(i)->Getauthor() << endl;
		cout << "ÃâÆÇ ¿¬µµ: " << BorrowedBook.at(i)->Getyear() << endl << endl;
		// Ã¥ÀÇ µ¥ÀÌÅÍ Ãâ·Â
	}
	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
	cout << "¹Ý³³ÇÒ µµ¼­¸¦ ¼±ÅÃÇÏ¼¼¿ä" << endl;
	int num = GetCommand(BorrowedBook.size()) - 1;

	/// bookList¿¡¼­ ÇØ´ç µµ¼­ÀÇ ·¹ÄÚµå ¼öÁ¤
	vector<int> list = loginedUser->GetborrowingList();
	for (int i = 0; i < bookList.size(); i++)
	{
		if (bookList[i]->Getbookid() == BorrowedBook[num]->Getbookid())
		{
			// ¹Ý³³ÇÒ Ã¥À» Ã£¾Ò´Ù!
			for (int j = 0; j < loginedUser->GetborrowingList().size(); j++)
			{
				if (loginedUser->GetborrowingList()[j] == bookList[i]->Getbookid())
				{
					list.erase(list.begin() + j);
					loginedUser->ResetBorrowingList(list);
					//loginedUser->GetborrowingList().erase(loginedUser->GetborrowingList().begin() + j); // ¿¡·¯°¡ ³ª´Â ÀÌÀ¯??
				}
				// ´ë¿©¸ñ·Ï¿¡¼­ Áö¿ì°í
			}
			bookList[i]->SetBorrowed(false);
			bookList[i]->SetBorrowerID(-1);
		 	// Ã¥ÀÇ µ¥ÀÌÅÍ¸¦ ¼öÁ¤ÇÑ´Ù.
		}
	}

	/// Bookbinary Code
	fstream fs("BookBinary.dat", ios::binary | ios::in | ios::out); // ¹ÙÀÌ³Ê¸®/ÀÐ±â/¾²±â
	int BookID;
	int BNameLength;
	int AuthorLength;
	bool returned = false;
	int returnedID = -1;
	for (int i = 0; i < bookList.size(); i++)
	{
		fs.read((char*)&BookID, sizeof(int));
		fs.read((char*)&BNameLength, sizeof(int)); // Ã¥ ÀÌ¸§ ±æÀÌ¸¸Å­ ÀÐ¾î¼­
		fs.seekg(BNameLength, ios::cur); // seekgÇÔ¼ö·Î °Ç³Ê¶Ü
		fs.read((char*)&AuthorLength, sizeof(int)); // ÀúÀÚ ÀÌ¸§ ±æÀÌ ÀÐ¾î¼­
		fs.seekg(AuthorLength + sizeof(int), ios::cur); // ÀúÀÚÀÌ¸§+ÃâÆÇ¿¬µµ °Ç³Ê¶Ü

														/// µð¹ö±×ÇØ¼­ read ÇÔ¼ö½áµµ curpointer°¡ ÀÌµ¿ÇÏ´ÂÁö È®ÀÎ
		if (BookID == BorrowedBook[num]->Getbookid())
			// ¹Ý³³¿¡ ÇØ´çÇÏ´Â °æ¿ìÀÓ
			// ÇöÀçÀ§Ä¡¿¡ ´ë¿©¿©ºÎ¿Í ´ë¿©ÀÚ ¾ÆÀÌµð µ¤¾î¾´´Ù!
		{
			fs.write((char*)&returned, sizeof(bool));
			fs.write((char*)&returnedID, sizeof(int));
		}
		else
		{
			fs.seekg(sizeof(bool) + sizeof(int), ios::cur);
			// Ã£´ø µµ¼­°¡ ¾Æ´Ò °æ¿ì ´ë¿©¿©ºÎ(bool) + ´ë¿©ÀÚ¾ÆÀÌµð(int) °Ç³Ê¶Ü
		}
	}

	cout << "µµ¼­ ¹Ý³³À» ¿Ï·áÇÏ¿´½À´Ï´Ù." << endl;
	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
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
		cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
		cout << "¦¢                              ¦¢" << endl;
		cout << "¦¢   ¢º Binary Search Tree ¢¸   ¦¢" << endl;
		cout << "¦¢                              ¦¢" << endl;
		cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		sa = new BST(&bookList);
		((BST*)sa)->buildIndex();
		break;
	case 2:
		system("cls");
		cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
		cout << "¦¢                              ¦¢" << endl;
		cout << "¦¢          ¢º Hash ¢¸          ¦¢" << endl;
		cout << "¦¢                              ¦¢" << endl;
		cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		sa = new Hash(&bookList);
		((Hash*)sa)->buildIndex();
		break;
	case 3:
		system("cls");
		cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤" << endl;
		cout << "¦¢                              ¦¢" << endl;
		cout << "¦¢     ¢º  Binary Search ¢¸     ¦¢" << endl;
		cout << "¦¢                              ¦¢" << endl;
		cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥" << endl;
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		sa = new BinarySearch(&bookList);
		break;
	}
}