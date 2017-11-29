#pragma once
#include <string>
using namespace std;

// 데이터 클래스
class Book
{
public:
	Book();
	~Book();

private:
	int id;
	string bookName;
	string author;
	int publishedYear;
	int isBorrowed;
	int borrowerID; // 대여안된경우 -1로 설정
};

