#pragma once
#include "WithIndex.h"
#include "Bucket.h"
#include <stdlib.h>
#include <string>

// 인덱스 사용 검색 알고리즘
// 책의 수만큼 Bucket 생성
class Hash :
	public WithIndex
{
public:
	Hash();
	Hash(vector<Book*>* booklist);
	~Hash();
	void buildIndex();
	// bookList에 저장된 책들을 책 이름을 키로 사용하여 hashTable에 저장함
	vector<Book*> search(string key);

private:
	vector<Bucket*> hashTable; // Bucket의 집합 -> Bucket이 실제 데이터를 담는 곳
	int hashFunction(string key);
};