/*
�̹� ������Ʈ�� �����ϸ鼭 ���̳ʸ� ���Ͽ� ����� �Ϸ��� �ϸ� ���� �����Ͱ� ��� �������� ������ ���� ���� �ֽ��ϴ�.
https://stackoverflow.com/questions/15063985/opening-a-binary-output-file-stream-without-truncation
�� ��ũ�� �����ϸ� ������ �ɰ̴ϴ�.
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
	lastNames.push_back("��");
	lastNames.push_back("��");
	lastNames.push_back("��");
	lastNames.push_back("��");	
	lastNames.push_back("��");
	lastNames.push_back("��");
	lastNames.push_back("��");
	lastNames.push_back("��");
	lastNames.push_back("��");
	lastNames.push_back("��");

	vector<string> firstNames;
	firstNames.push_back("�浿");
	firstNames.push_back("����");
	firstNames.push_back("�¿�");
	firstNames.push_back("����");
	firstNames.push_back("��ȣ");
	firstNames.push_back("ä��");
	firstNames.push_back("����");
	firstNames.push_back("ö��");
	firstNames.push_back("�μ�");
	firstNames.push_back("�Ƹ�");

	fstream binaryFile;
	binaryFile.open("BookBinary.dat", ios::out|ios::binary);
	fstream textFile;
	textFile.open("BookText.txt", ios::out|ios::trunc);

	//������ å�� ����
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