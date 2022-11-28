#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>


using namespace std;

struct MyStruct
{
	string Name[30]
	{ "q1", "w2", "e3", "r4", "t5", "y6", "u7", "i8", "o9", "p10", "a11", "s12", "d13", "f14", "g15",
		"h16", "j17", "k18", "l19", "z20", "x21", "c22", "v23", "b24", "n25", "m26", "bc27", "op28", "lh29", "rt30" };
	string Author[15]
	{ "qfg1", "wty2", "ey3", "rg4", "tfg5", "yy6", "au7", "fdi8", "afo9", "ergp10", "eva11", "evs12", "ed13", "mf14", "wg15" };
	string Type[5]{ "Детектив", "Роман", "Фентези", "Фантастика", "Историческое" };
	int Age[5]{ 12, 14, 16, 18, 23 };
};

class Book
{
public:
	bool Enabed;
	string Author;
	string Name;
	string Type;
	int Size;
	int Age;
	vector<int> Rating;

	Book(int i)
	{
		Enabed = true;
		Rating.resize(10);

		MyStruct my;
		Author = my.Author[i % 15];
		Name = my.Name[i % 30];
		Type = my.Type[(i+1) % 5];
		Age = my.Age[(i+2) % 5];

		srand(time(NULL) + i);
		//int num = min + rand() % (max - min + 1);
		Size = 50 + rand() % (1000 - 50 + 1);
	};

};



