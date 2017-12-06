#include "SearchAlgorithm.h"



SearchAlgorithm::SearchAlgorithm()
{
}

SearchAlgorithm::SearchAlgorithm(vector<Book*>* booklist)
{
	_bookList = booklist;
}


SearchAlgorithm::~SearchAlgorithm()
{
}

void SearchAlgorithm::setblist(vector<Book*>* booklist)
{
	_bookList = booklist;
}
