#pragma once
#include "BST.h"
#include "Hash.h"
#include "BinarySearch.h"
#include "BinaryReader.h"
#include "TextReader.h"
#include <iostream>
using namespace std;

class App
{
public:
	App();
	~App();

	int GetCommand(int maxCommand);

	void run();
	void startmenu();

private:
	void login(); // 1명 로그인
	void readFile(bool isBinary);
	void writeFile(bool isBinary); // Book Binary 파일에서는 아예 지우고 다시쓰면 안됨!! 업데이트할 부분만 고쳐쓴다
	void searchBook();
	void borrowBook(vector<Book*> searchbook);
	void returnBook();
	void buildIndex(); // 어떤 인덱스를 쓰겠다고 사용자가 선택하도록 하는 함수로 만들었다고 함
	//여기서 전략패턴 쓴다음!
	//searchBook에선 sa->search만 하면 될듯.

	FileReader* fr;
	SearchAlgorithm* sa;

	vector<User*> userList;
	vector<Book*> bookList;
	///
	User* loginedUser;
};