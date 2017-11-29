#pragma once
#include "NoIndex.h"

// (1) 직접 접근 가능
// (2) 정렬되어 있어야 함
class BinarySearch :
	public NoIndex
	// 인덱스를 사용하지 않으므로 NoIndex 상속받음
{
public:
	BinarySearch();
	BinarySearch(vector<Book*>* _bookList); // 생성자에서 정렬시켜야 함
											// 여러개 찾는 경우도 생각해 봐야함. 반으로 나눴을때 왼쪽에서도 찾고 오른쪽에서도 찾고. 정렬되어 있으니까 알수있을것.
	~BinarySearch();

	void search(string key);
};

