#include "pch.h"
#include "Bancnote.h"



Bancnote::Bancnote()
{
	setlocale(LC_ALL, "Russian");//добавление возможности отображения русского языка
}

Bancnote::~Bancnote()
{
}


BancnoteStruct Bancnote::RandomBancnote(int i)
{
	srand(time(NULL) + i);
	//int num = min + rand() % (max - min + 1);
	int randNum1 = rand() % (5);

	srand(time(NULL) - 2 * i);
	int randNum2 = rand() % (5);

	BancnoteStruct bancnote;
	bancnote.Name = Names[randNum1];
	bancnote.Nominal = Nominals[randNum2];
	bancnote.kurs = kurses[randNum1];


	return bancnote;
}



int Bancnote::CountMoney(vector<BancnoteStruct> bancnotes)
{
	int count = 0;

	for (BancnoteStruct bancnote : bancnotes)
		count += bancnote.Nominal * bancnote.kurs;

	return count;
}

vector<BancnoteStruct> Bancnote::SortBancnotes(vector<BancnoteStruct> bancnotes)
{
	vector<BancnoteStruct> newBancnotes;
	vector<BancnoteStruct> localCont;

	for (size_t i = 0; i < 5; i++)
	{
		for (BancnoteStruct bancnote : bancnotes)
		{
			if (bancnote.Name == Names[i])
				localCont.push_back(bancnote);
		}

		for (size_t j = 0; j < 5; j++)
		{
			for (BancnoteStruct bancnote : localCont)
			{
				if (bancnote.Nominal == Nominals[i])
					newBancnotes.push_back(bancnote);
			}
		}

		localCont.clear();
	}
	bancnotes.clear();

	return newBancnotes;
}

