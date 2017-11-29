#pragma once
#include "BST.h"
#include "Hash.h"
#include "BinarySearch.h"
#include "BinaryReader.h"
#include "TextReader.h"
class App
{
public:
	App();
	~App();

	void run();

private:
	void login(); // 1�� �α���
	void readFile(bool isBinary);
	void writeFile(bool isBinary); // Book Binary ���Ͽ����� �ƿ� ����� �ٽþ��� �ȵ�!! ������Ʈ�� �κи� ���ľ���
	void searchBook();
	void borrowBook();
	void returnBook();
	void buildIndex(); // � �ε����� ���ڴٰ� ����ڰ� �����ϵ��� �ϴ� �Լ��� ������ٰ� ��

	FileReader* fr;
	SearchAlgorithm* sa;

	vector<User*> userList;
	vector<Book*> bookList;
};