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
	void login(); // 1�� �α���
	void readFile(bool isBinary);
	void writeFile(bool isBinary); // Book Binary ���Ͽ����� �ƿ� ����� �ٽþ��� �ȵ�!! ������Ʈ�� �κи� ���ľ���
	void searchBook();
	void borrowBook(vector<Book*> searchbook);
	void returnBook();
	void buildIndex(); // � �ε����� ���ڴٰ� ����ڰ� �����ϵ��� �ϴ� �Լ��� ������ٰ� ��
	//���⼭ �������� ������!
	//searchBook���� sa->search�� �ϸ� �ɵ�.

	FileReader* fr;
	SearchAlgorithm* sa;

	vector<User*> userList;
	vector<Book*> bookList;
	///
	User* loginedUser;
};