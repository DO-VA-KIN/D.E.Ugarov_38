#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <math.h>

using namespace std;

class Visitor
{
private:
	int LeftRead;
	int ReadNow;
public:
	int Age;
	string Type;
	int MinSize;
	int MaxSize;
	int ReadSpeed;//скорость чтения(страниц в день)
	vector<string> ReadBooks;

	Visitor(int i)
	{
		LeftRead = 0;
		ReadNow = false;
		ReadBooks.reserve(10);

		srand(time(NULL) + i);
		//int num = min + rand() % (max - min + 1);
		Age = 7 + rand() % (90 - 7 + 1);

		srand(time(NULL) + 2*i);
		ReadSpeed = 50 + rand() % (400 - 50 + 1);

		srand(time(NULL) + 3*i);
		int n = 0 + rand() % 3;
		switch (n)
		{
		case 0:
			MinSize = 0;
			MaxSize = 99;
			break;
		case 1:
			MinSize = 100;
			MaxSize = 500;
			break;
		case 2:
			MinSize = 501;
			MaxSize = 99999;
			break;
		default:
			//посетитель любит бокс, а не читать
			MinSize = 0;
			MaxSize = 0;
			break;
		}

		srand(time(NULL) + 3 * i);
		n = 0 + rand() % 6;
		switch (n)
		{
		case 0: Type = "Детектив"; break;
		case 1: Type = "Роман"; break;
		case 2: Type = "Фентези"; break;
		case 3: Type = "Фантастика"; break;
		case 4: Type = "Историческое"; break;
		default: Type = "Любой"; break;
		}
	};
	
	int SetBook(string bookName, int size)
	{
		if (ReadNow) return -1;

		ReadBooks.push_back(bookName);
		LeftRead = ceil((double)size / ReadSpeed);
		ReadNow = true;
		return LeftRead;
	}

	int Read(int i) 
	{ 
		if (!ReadNow) return -1;

		if (LeftRead > 0)
		{
			LeftRead -= ReadSpeed;
			return -1;
		}
		else
		{
			ReadNow = false;
			srand(time(NULL) + 3 * i);
			return (1 + rand() % 10);
		}
	};

	bool IsReadNow() { return ReadNow; };

};

