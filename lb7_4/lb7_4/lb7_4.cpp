#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include "Library.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	int num = -1;//выбор действия
	int numsBook = 5;
	int numsVisitor = 10;

	while (true)
	{
		num = -1;

		cout << "введите количество книг (до 30)" << endl;
		cin >> numsBook;
		cout << "введите количество посетителей" << endl;
		cin >> numsVisitor;

		Library library(numsBook, numsVisitor);
		library.Work(30);
		
		for (int i = 0; i < library.Report.Books.size(); i++)
		{
			if (library.Report.Books[i].CountRead == 0) continue;
			cout << "\nНазвание: " << library.Report.Books[i].Name << endl;
			cout << "Рейтинг: " << library.Report.Books[i].Rating << endl;
			cout << "Среднее время на прочтение: " << library.Report.Books[i].TimeRead << endl;
			cout << "Количество прочтений: " << library.Report.Books[i].CountRead << endl;
		}

		for (size_t i = 0; i < library.Report.Authors.size(); i++)
		{
			if (library.Report.Authors[i].CountRead == 0) continue;
			cout << "\nАвтор: " << library.Report.Authors[i].Author << endl;
			cout << "Количество прочтений: " << library.Report.Authors[i].CountRead << endl;
		}

		cout << "\nenter 9 to exit\n";
		cin >> num;
		if (num == 9) break;
	}

}