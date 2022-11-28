#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>

#include"Book.h"
#include"Visitor.h"

using namespace std;

class Library
{
private:
	struct ReportStruct
	{
		struct BookStruct 
		{
			string Name = "";
			double Rating = 0;
			int TimeRead = 0;
			int CountRead = 0;
		};
		struct AuthorsStruct
		{
			string Author = "";
			int CountRead = 0;
		};
		vector<BookStruct> Books;
		vector<AuthorsStruct> Authors;
	};
	vector<Book> Books;
	vector<Visitor> Visitors;
	void SelectBook();

public:
	ReportStruct Report = ReportStruct();
	Library(int countBooks, int countVisitors);
	void Work(int timeW);//сколько работать в днях
};


