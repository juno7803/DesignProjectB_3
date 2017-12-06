/*
이번 프로젝트를 진행하면서 바이너리 파일에 덮어쓰기 하려고 하면 기존 데이터가 모두 지워지는 문제를 만날 수도 있습니다.
https://stackoverflow.com/questions/15063985/opening-a-binary-output-file-stream-without-truncation
위 링크를 참조하면 도움이 될겁니다.
*/

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

void main()	
{
	vector<string> words;
	fstream dictionary;
	dictionary.open("dictionary.txt");
	while (!dictionary.eof()) {
		string temp;
		dictionary >> temp;
		words.push_back(temp);
	}
	dictionary.close();

	vector<string> lastNames;
	lastNames.push_back("강");
	lastNames.push_back("권");
	lastNames.push_back("김");
	lastNames.push_back("박");	
	lastNames.push_back("백");
	lastNames.push_back("오");
	lastNames.push_back("이");
	lastNames.push_back("임");
	lastNames.push_back("정");
	lastNames.push_back("최");

	vector<string> firstNames;
	firstNames.push_back("길동");
	firstNames.push_back("영희");
	firstNames.push_back("태연");
	firstNames.push_back("태희");
	firstNames.push_back("찬호");
	firstNames.push_back("채련");
	firstNames.push_back("형민");
	firstNames.push_back("철수");
	firstNames.push_back("민수");
	firstNames.push_back("아름");

	fstream binaryFile;
	binaryFile.open("BookBinary.dat", ios::out|ios::binary);
	fstream textFile;
	textFile.open("BookText.txt", ios::out|ios::trunc);

	//생성할 책의 개수
	int totalBookCount = 1000;
	int bookID = 1;
	for (int i = 0; i < totalBookCount; i++)
	{
		if (i % 1000 == 0)
			cout << "generating " << i << "th book..." << endl;

		int randomWord1 = rand() % words.size();
		int randomWord2 = rand() % words.size();
		string bookName;
		bookName.append(words[randomWord1]);
		bookName.append("_");
		bookName.append(words[randomWord2]);		

		int randomWord3 = rand() % firstNames.size();
		int randomWord4 = rand() % lastNames.size();
		string authorName;
		authorName.append(lastNames[randomWord4]);
		authorName.append(firstNames[randomWord3]);

		int publishedYear = 1900 + rand() % 111;

		bool isBorrowed = false;
		int borrowerID = -1;

		binaryFile.write((char*)&bookID,sizeof(int));
		int bookNameSize = bookName.size();
		binaryFile.write((char*)&bookNameSize,sizeof(int));
		binaryFile.write(&bookName[0], bookNameSize);
		int authorNameSize = authorName.size();
		binaryFile.write((char*)&authorNameSize, sizeof(int));
		binaryFile.write(&authorName[0], authorNameSize);
		binaryFile.write((char*)&publishedYear,sizeof(int));
		binaryFile.write((char*)&isBorrowed,sizeof(bool));
		binaryFile.write((char*)&borrowerID, sizeof(int));

		textFile << bookID << "\t" << bookName << "\t" << authorName << "\t" << publishedYear << "\t" << isBorrowed << endl;

		bookID++;
	}
	binaryFile.close();
	textFile.close();
} 