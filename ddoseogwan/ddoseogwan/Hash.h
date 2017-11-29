#pragma once
#include "WithIndex.h"
#include "Bucket.h"

// 인덱스 사용 검색 알고리즘
class Hash :
	public WithIndex
{
public:
	Hash();
	~Hash();

	void buildIndex();
	void search(string key);

private:
	vector<Bucket*> hashTable; // Bucket의 집합 -> Bucket이 실제 데이터를 담는 곳
	int hashFunction(string key);
};