#pragma once
#include "SearchAlgorithm.h"

// 인덱스를 안쓰는 검색 알고리즘
// 중간에 놓여만 있고 그냥 인덱스를 안쓰는 검색 알고리즘을 상속하기만 하면 됨

class NoIndex :
	public SearchAlgorithm
{
public:
	NoIndex();
	~NoIndex();
};