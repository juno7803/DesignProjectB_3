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
		cout << "Ⅱ : ";
		cin >> command;

		if (cin.fail())
		{
			cout << "弛螢夥腦雖 彊擎 殮溘殮棲棻" << endl;
			cin.clear();
			cin.ignore(256, '\n'); // cin衛 螃盟濩嬴輿朝 囀萄 
		}
		else
		{
			if (command <= maxCommand && command >= 0)
			{
				return command;
			}
			else
			{
				cout << "弛螢夥腦雖 彊擎 殮溘殮棲棻" << endl;
			}
		}
	}
	cout << "式式式式式式式式式式式式式式式式式" << endl;
}

void App::run()
{
	while (1)
	{
		cout << "忙式式式式式式式式式式式式式式式忖" << endl;
		cout << "弛                              弛" << endl;
		cout << "弛     Ⅱ   DDoseogwan   ９     弛" << endl;
		cout << "弛                              弛" << endl;
		cout << "戌式式式式式式式式式式式式式式式戎" << endl;
		cout << "式式式式式式式式式式式式式式式式式" << endl;
		cout << "だ橾 檗晦 賅萄 撲薑" << endl;
		cout << "1. Binary 賅萄" << endl;
		cout << "2. Text 賅萄" << endl;
		cout << "0. Щ煎斜極 謙猿" << endl;
		cout << "式式式式式式式式式式式式式式式式式" << endl;
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
		cout << "忙式式式式式式式式式式式式式式式忖" << endl;
		cout << "弛                              弛" << endl;
		cout << "弛     Ⅱ   DDoseogwan   ９     弛" << endl;
		cout << "弛                              弛" << endl;
		cout << "戌式式式式式式式式式式式式式式式戎" << endl;
		cout << "式式式式式式式式式式式式式式式式式" << endl;
		cout << "Ⅰ" << loginedUser->getname() << "椒 �紊腎桭炴�!" << endl;
		cout << "式式式式式式式式式式式式式式式式式" << endl;
		cout << "1. 紫憮 匐儀 塽 渠罹" << endl;
		cout << "2. 紫憮 奩陶" << endl;
		cout << "0. 菴煎 陛晦" << endl;
		cout << "式式式式式式式式式式式式式式式式式" << endl;
		int num = GetCommand(2);
		cout << "式式式式式式式式式式式式式式式式式" << endl;
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
			cout << "濠翕 煎斜嬴醒 腎歷蝗棲棻" << endl;
			cout << "式式式式式式式式式式式式式式式式式" << endl;
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

	cout << "忙嬴檜蛤蒂 殮溘ж撮蹂 : ";
	cin >> id;
	cout << "戌綠塵廓�ㄧ� 殮溘ж撮蹂 : ";
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
				cout << "綠塵廓�ㄟ� 橾纂ж雖 彊蝗棲棻" << endl;
				system("pause");
				system("cls");
				return;
			}
		}
	}
	cout << "橾纂ж朝 嬴檜蛤陛 橈蝗棲棻" << endl;
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
// UserT,UserB,BookT朝 嬴蕨 繩睡攪 棻衛 賦輿堅
// BookB虜 夥莞陽葆棻 賦輿賊 脹棻!
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
		// 渠罹濠陛 氈朝 唳辦
		if (i != (int)bookList.size() - 1)
		{
			ofs3 << endl;
		}
		// 渠罹濠陛 橈戲賊 渠罹濠 ID朝 盪濰ж雖 彊朝棻.
	}
	ofs3.close();
	// Write BookText

	ofstream ofs2("UserBinary.dat", ios::binary | ios::out);
	for (int i = 0; i < userList.size(); i++)
	{
		int id = userList[i]->getid();
		int p_len = userList[i]->getpw().size();
		int n_len = userList[i]->getname().size();
		int borrowed_num = userList[i]->GetborrowingList().size();
		string pw = userList[i]->getpw();
		string name = userList[i]->getname();

		ofs2.write((char*)&id, sizeof(int)); // 嬴檜蛤
		ofs2.write((char*)&p_len, sizeof(int)); // 綠塵廓�� 望檜
		ofs2.write(pw.c_str(), p_len); // 綠塵廓��
		ofs2.write((char*)&n_len, sizeof(int)); // 檜葷 望檜
		ofs2.write(name.c_str(), n_len); // 檜葷
		ofs2.write((char*)&borrowed_num, sizeof(int)); // 渠罹и 疇曖 熱
		for (int j = 0; j < borrowed_num; j++)
		{
			int borrowedID = userList[i]->GetborrowingList()[j];
			ofs2.write((char*)&borrowedID, sizeof(int));
		}
	}
	ofs2.close();
	// Write UserBinary
}

void App::searchBook()
{
	buildIndex();
	string key;
	cout << "紫憮貲擊 殮溘п 輿撮蹂" << endl;
	cout << "Ⅱ : ";
	cin >> key;
	cout << "式式式式式式式式式式式式式式式式式" << endl;
	vector<Book*> tempResult1;
	tempResult1 = (sa->search(key)); // 疇 檜葷戲煎 匐儀 唸婁
	if (tempResult1.size() == 0)
	{
		cout << "瓊朝 紫憮陛 橈蝗棲棻." << endl;
		cout << "式式式式式式式式式式式式式式式式式" << endl;
		system("pause");
		return;
	}

	string author;
	int year;
	vector<Book*> tempResult2; // 盪濠貲戲煎 蹺陛 匐儀
	vector<Book*> finalResult; // 轎っ喇紫煎 蹺陛 匐儀
	
	cout << "盪濠貲擊 殮溘п 輿撮蹂" << endl;
	cout << "Ⅱ : ";
	cin >> author;
	cout << "式式式式式式式式式式式式式式式式式" << endl;
	for (int i = 0; i < tempResult1.size(); i++)
	{
		if (author == tempResult1.at(i)->Getauthor())
		{
			tempResult2.push_back(tempResult1.at(i));
		}
	}
	if (tempResult2.size() == 0)
	{
		cout << "瓊朝 紫憮陛 橈蝗棲棻." << endl;
		cout << "式式式式式式式式式式式式式式式式式" << endl;
		system("pause");
		return;
	}
	// 盪濠貲 匐儀

	cout << "轎っ喇紫蒂 殮溘п 輿撮蹂" << endl;
	cout << "Ⅱ : ";
	cin >> year;
	cout << "式式式式式式式式式式式式式式式式式" << endl;
	for (int i = 0; i < tempResult2.size(); i++)
	{
		if (year == tempResult2.at(i)->Getyear())
		{
			finalResult.push_back(tempResult2.at(i));
		}
	}
	if (finalResult.size() == 0)
	{
		cout << "瓊朝 紫憮陛 橈蝗棲棻." << endl;
		cout << "式式式式式式式式式式式式式式式式式" << endl;
		system("pause");
		return;
	}
	// 轎っ喇紫 匐儀
	if (finalResult.size() != 0)
	{
		cout << "式式式式式瓊擎 紫憮 跡煙式式式式式" << endl;
	}
	while (1)
	{
		for (int i = 0; i < finalResult.size(); i++)
		{
			cout << i+1 << ". ";
			cout << "紫憮貲: " << finalResult.at(i)->Getname() << endl;
			cout << "   盪濠貲: " << finalResult.at(i)->Getauthor() << endl;
			cout << "   轎っ 翱紫: " << finalResult.at(i)->Getyear() << endl;
		}
		cout << "式式式式式式式式式式式式式式式式式" << endl;
		cout << "1. 紫憮 渠罹" << endl;
		cout << "0. 菴煎 陛晦" << endl;
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
	// だ塭嘐攪曖 searchbook擎 search л熱曖 譆謙唸婁煎 釭螞 葬蝶お蒂 氬堅螃朝 漱攪
	system("pause");
	system("cls");
	cout << "忙式式式式式式式式式式式式式式式忖" << endl;
	cout << "弛                              弛" << endl;
	cout << "弛     Ⅱ   紫憮 渠罹    ９     弛" << endl;
	cout << "弛                              弛" << endl;
	cout << "戌式式式式式式式式式式式式式式式戎" << endl;
	cout << "式式式式式式式式式式式式式式式式式" << endl;
	cout << "渠罹й 紫憮蒂 摹鷗ж撮蹂" << endl;
	for (int i = 0; i < searchbook.size(); i++)
	{
		cout << i+1 << ". ";
		cout << "紫憮貲: " << searchbook[i]->Getname() << endl;
		cout << "   盪濠貲: " << searchbook[i]->Getauthor() << endl;
		cout << "   轎っ 翱紫: " << searchbook[i]->Getyear() << endl;
	}
	int num = GetCommand(searchbook.size()) -1;
	if (searchbook[num]->Getisborrowed() == true)
	{
		cout << "檜嘐 渠罹脹 疇 殮棲棻" << endl;
		cout << "式式式式式式式式式式式式式式式式式" << endl;
		return;
	}
	else if (loginedUser->GetborrowingList().size() > 5)
	{
		cout << "渦 檜鼻 渠罹й 熱 橈蝗棲棻" << endl;
		cout << "式式式式式式式式式式式式式式式式式" << endl;
		return;
	}

	for (int j = 0; j < bookList.size(); j++)
	{
		if (bookList[j]->Getbookid() == searchbook[num]->Getbookid()) // 錳楚 bookList縑憮 薑爾蒂 熱薑ж晦 嬪п searchbook婁 渠褻ж罹 錳獄擊 瓊朝棻.
		{
			loginedUser->setborrowingList(bookList[j]->Getbookid());
			bookList[j]->SetBorrowed(true);
			bookList[j]->SetBorrowerID(loginedUser->getid());
			// 疇曖 等檜攪 熱薑
		}
	}
	
	/// Bookbinary Code
	fstream fs("BookBinary.dat", ios::binary | ios::in | ios::out); // 夥檜傘葬/檗晦/噙晦
	int BookID;
	int BNameLength;
	int AuthorLength;
	bool Borrow = true; // 渠罹
	int BorrowID = loginedUser->getid(); // 渠罹濠 id
	for (int i = 0; i < bookList.size(); i++)
	{
		fs.read((char*)&BookID, sizeof(int)); // 疇曖 嬴檜蛤蒂 檗橫褥(渠罹й 疇婁 綠掖ж晦 嬪л)
		fs.read((char*)&BNameLength, sizeof(int)); // 疇 檜葷 望檜虜躑 檗橫憮
		fs.seekg(BNameLength, ios::cur); // seekgл熱煎 勒傘嗎 (疇 檜葷擎 BNameLength虜躑曖 望檜檜貊, и僥濠朝 char縑 п渡ж嘎煎 1byte檜棻. 評塭憮 *1 п輿朝匙婁 偽棻)
		fs.read((char*)&AuthorLength, sizeof(int)); // 盪濠 檜葷 望檜 檗橫憮
		fs.seekg(AuthorLength + sizeof(int), ios::cur); // 盪濠檜葷+轎っ翱紫 勒傘嗎

		if (BookID == searchbook[num]->Getbookid())
			// 渠罹й 疇縑 п渡
			// ⑷營嬪纂縑 渠罹罹睡諦 渠罹濠 嬴檜蛤 竣橫噹棻!
		{
			fs.write((char*)&Borrow, sizeof(bool)); // 渠罹ц棻 : true蒂 噹棻
			fs.write((char*)&BorrowID, sizeof(int)); // 渠罹濠 嬴檜蛤 : 煎斜檣и 嶸盪曖 ID蒂 噹棻
		}
		else
		{
			fs.seekg(sizeof(bool) + sizeof(int), ios::cur);
			// 瓊湍 紫憮陛 嬴棍 唳辦 渠罹罹睡(bool) + 渠罹濠嬴檜蛤(int) 勒傘嗎
		}
	}
	fs.close();

	cout << "疇 渠罹陛 諫猿腎歷蝗棲棻." << endl;
	cout << "式式式式式式式式式式式式式式式式式" << endl;
	system("pause");
}

void App::returnBook()
{
	vector<Book*> BorrowedBook; // 煎斜檣и 嶸盪曖 渠罹跡煙擊 氬朝 歜衛 漱攪
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
	cout << "忙式式式式式式式式式式式式式式式忖" << endl;
	cout << "弛                              弛" << endl;
	cout << "弛     Ⅱ   紫憮 奩陶    ９     弛" << endl;
	cout << "弛                              弛" << endl;
	cout << "戌式式式式式式式式式式式式式式式戎" << endl;
	cout << "式式式式式式式式式式式式式式式式式" << endl;
	if (BorrowedBook.size() == 0)
	{
		cout << "奩陶й 紫憮陛 橈蝗棲棻" << endl;
		cout << "式式式式式式式式式式式式式式式式式" << endl;
		return;
	}
	cout <<"式式式" << loginedUser->getname() << "椒曖 渠罹跡煙式式式" << endl;
	for (int i = 0; i < BorrowedBook.size(); i++)
	{
		cout << i + 1 << ". ";
		cout << "疇 檜葷: " << BorrowedBook.at(i)->Getname() << endl;
		cout << "盪濠貲: " << BorrowedBook.at(i)->Getauthor() << endl;
		cout << "轎っ 翱紫: " << BorrowedBook.at(i)->Getyear() << endl << endl;
		// 疇曖 等檜攪 轎溘
	}
	cout << "式式式式式式式式式式式式式式式式式" << endl;
	cout << "奩陶й 紫憮蒂 摹鷗ж撮蹂" << endl;
	int num = GetCommand(BorrowedBook.size()) - 1;

	/// bookList縑憮 п渡 紫憮曖 溯囀萄 熱薑
	vector<int> list = loginedUser->GetborrowingList();
	for (int i = 0; i < bookList.size(); i++)
	{
		if (bookList[i]->Getbookid() == BorrowedBook[num]->Getbookid())
		{
			// 奩陶й 疇擊 瓊懊棻!
			for (int j = 0; j < loginedUser->GetborrowingList().size(); j++)
			{
				if (loginedUser->GetborrowingList()[j] == bookList[i]->Getbookid())
				{
					list.erase(list.begin() + j);
					loginedUser->ResetBorrowingList(list);
					//loginedUser->GetborrowingList().erase(loginedUser->GetborrowingList().begin() + j); // 縑楝陛 釭朝 檜嶸??
				}
				// 渠罹跡煙縑憮 雖辦堅
			}
			bookList[i]->SetBorrowed(false);
			bookList[i]->SetBorrowerID(-1);
		 	// 疇曖 等檜攪蒂 熱薑и棻.
		}
	}

	/// Bookbinary Code
	fstream fs("BookBinary.dat", ios::binary | ios::in | ios::out); // 夥檜傘葬/檗晦/噙晦
	int BookID;
	int BNameLength;
	int AuthorLength;
	bool returned = false;
	int returnedID = -1;
	for (int i = 0; i < bookList.size(); i++)
	{
		fs.read((char*)&BookID, sizeof(int));
		fs.read((char*)&BNameLength, sizeof(int)); // 疇 檜葷 望檜虜躑 檗橫憮
		fs.seekg(BNameLength, ios::cur); // seekgл熱煎 勒傘嗎
		fs.read((char*)&AuthorLength, sizeof(int)); // 盪濠 檜葷 望檜 檗橫憮
		fs.seekg(AuthorLength + sizeof(int), ios::cur); // 盪濠檜葷+轎っ翱紫 勒傘嗎

														/// 蛤幗斜п憮 read л熱賦紫 curpointer陛 檜翕ж朝雖 �挫�
		if (BookID == BorrowedBook[num]->Getbookid())
			// 奩陶縑 п渡ж朝 唳辦歜
			// ⑷營嬪纂縑 渠罹罹睡諦 渠罹濠 嬴檜蛤 竣橫噹棻!
		{
			fs.write((char*)&returned, sizeof(bool));
			fs.write((char*)&returnedID, sizeof(int));
		}
		else
		{
			fs.seekg(sizeof(bool) + sizeof(int), ios::cur);
			// 瓊湍 紫憮陛 嬴棍 唳辦 渠罹罹睡(bool) + 渠罹濠嬴檜蛤(int) 勒傘嗎
		}
	}

	cout << "紫憮 奩陶擊 諫猿ж艘蝗棲棻." << endl;
	cout << "式式式式式式式式式式式式式式式式式" << endl;
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
		cout << "忙式式式式式式式式式式式式式式式忖" << endl;
		cout << "弛                              弛" << endl;
		cout << "弛   Ⅱ Binary Search Tree ９   弛" << endl;
		cout << "弛                              弛" << endl;
		cout << "戌式式式式式式式式式式式式式式式戎" << endl;
		cout << "式式式式式式式式式式式式式式式式式" << endl;
		sa = new BST(&bookList);
		((BST*)sa)->buildIndex();
		break;
	case 2:
		system("cls");
		cout << "忙式式式式式式式式式式式式式式式忖" << endl;
		cout << "弛                              弛" << endl;
		cout << "弛          Ⅱ Hash ９          弛" << endl;
		cout << "弛                              弛" << endl;
		cout << "戌式式式式式式式式式式式式式式式戎" << endl;
		cout << "式式式式式式式式式式式式式式式式式" << endl;
		sa = new Hash(&bookList);
		((Hash*)sa)->buildIndex();
		break;
	case 3:
		system("cls");
		cout << "忙式式式式式式式式式式式式式式式忖" << endl;
		cout << "弛                              弛" << endl;
		cout << "弛     Ⅱ  Binary Search ９     弛" << endl;
		cout << "弛                              弛" << endl;
		cout << "戌式式式式式式式式式式式式式式式戎" << endl;
		cout << "式式式式式式式式式式式式式式式式式" << endl;
		sa = new BinarySearch(&bookList);
		break;
	}
}