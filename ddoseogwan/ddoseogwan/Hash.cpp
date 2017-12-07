#include "Hash.h"

Hash::Hash()
{
	for (int i = 0; i < _bookList->size(); i++)
	{
		hashTable[i] = new Bucket; // 책 개수만큼 빈방을 미리 만들어 준다.
	}
}

Hash::~Hash()
{
}

void Hash::buildIndex()
{
	int b_num; // 버켓 넘버!
	for (int i = 0; i < _bookList->size(); i++)
	{
		b_num = hashFunction(_bookList->at(i)->Getname()); // 버켓넘버를 구하고
		hashTable.at(b_num)->getbooks().push_back(_bookList->at(i));
		// 그 넘버에 해당하는 버켓의 books에 책을 저장한다.
	}
}

vector<Book*>* Hash::search(string key)
// 여기선 버켓 하나만 찾으면 된다! (이름이 중복된것도 같이 가져옴)
{
	return &((hashTable.at(hashFunction(key)))->getbooks());
}

int Hash::hashFunction(string key)
{
	int temp;
	for (int i = 0; i < key.length(); i++)
	{
		temp += stoi(key.substr(i, i + 1)); // 한자리씩 읽어오기
		// atoi 사용하려면 c_str함수를 사용해야 함
	}
	return temp%(_bookList->size());
	// https://www.acmicpc.net/board/view/2994
}
