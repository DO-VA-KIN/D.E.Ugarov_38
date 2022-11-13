#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>//подключение библиотеки с генерацией рандомных чисел
#include <time.h>//подключение библиотеки для генерации рандомных чисел, отталкиваясь от времени

using namespace std;

struct BancnoteStruct
{
public:
	std::string Name;
	int Nominal;
	double kurs;
};


class Bancnote
{
public:
	Bancnote();
	~Bancnote();

	const string Names[5] = { "Доллар","Евро","Белорусский рубль","Бразильский реал","Казахтанский тенге" };
	const int Nominals[5] = { 5, 10, 25, 50, 100 };
	const double kurses[5] = { 63.68, 62.34, 24.64, 12.26, 13.45 };


	BancnoteStruct RandomBancnote(int i);
	
	int CountMoney(vector<BancnoteStruct> bancnotes);

	vector<BancnoteStruct> SortBancnotes(vector<BancnoteStruct> bancnotes);

};

