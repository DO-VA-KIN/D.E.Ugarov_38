// lb5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <cstdlib>

#include "Spell.h"
#include "Spell.h"
#include "Oponent.h"

using namespace std;


vector<RangeSpell> rangeSpells;
vector<MeleeSpell> meleeSpells;
vector<CurseSpell> curseSpells;
vector<SupportSpell> supportSpells;
Oponent oponent;

void Initialize()
{
	int num = 0;
	for (int j = 0; j < 4; j++)
	{
		srand(time(NULL) + num);
		for (int i = 1 + rand() % 10; i > 0; i--)
		{
			if (j == 0)
				rangeSpells.push_back(RangeSpell(i+j));
			else if (j == 1)
				meleeSpells.push_back(MeleeSpell(i+j));
			else if (j == 2)
				curseSpells.push_back(CurseSpell(i+j));
			else if (j == 3)
				supportSpells.push_back(SupportSpell(i+j));
		}
		num += 15;
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");//добавление возможности отображения русского языка
	cout << "\nWritten by Ghost: HI!\n";//автограф - приветствие

	Initialize();

	cout << "\nВыбирете действие\n";
	cout << "1 Применить дальнее заклинание\n";
	cout << "2 Применить ближнее заклинание\n";
	cout << "3 Применить проклятие\n";
	cout << "4 Применить заклинание поддержки\n";
	cout << "5 Состояние противника\n";
	cout << "6 Количество оставшихся заклинаний\n";
	cout << "7 Пересоздать заклинания\n";
	cout << "8 Обновить противника\n";
	cout << "9 Выход\n";

	while (true)
	{
		int num;
		cin >> num;

		if (num == 1)
		{
			num = rangeSpells.size();
			if (num == 0)
				cout << "заклинания кончились\n";
			else
			{
				RangeSpell rangeSpell = rangeSpells[num-1];
				Spell spell;
				spell.Distance = rangeSpell.Distance;
				spell.Effect = rangeSpell.Effect;
				spell.Level = rangeSpell.Level;
				spell.ManaCost = rangeSpell.ManaCost;
				spell.Name = rangeSpell.Name;
				spell.TimeCast = rangeSpell.TimeCast;
				if (oponent.AddUsedSpell(spell))
					cout << "заклинание применено\n";
				rangeSpells.pop_back();
			}
			continue;
		}
		if (num == 2)
		{
			num = meleeSpells.size();
			if (num == 0)
				cout << "заклинания кончились\n";
			else
			{
				MeleeSpell meleeSpell = meleeSpells[num-1];
				Spell spell;
				spell.Distance = meleeSpell.Distance;
				spell.Effect = meleeSpell.Effect;
				spell.Level = meleeSpell.Level;
				spell.ManaCost = meleeSpell.ManaCost;
				spell.Name = meleeSpell.Name;
				spell.TimeCast = meleeSpell.TimeCast;
				if(oponent.AddUsedSpell(spell))
					cout << "заклинание применено\n";
				meleeSpells.pop_back();
			}
			continue;
		}
		if (num == 3)
		{
			num = curseSpells.size();
			if (num == 0)
				cout << "заклинания кончились\n";
			else
			{
				CurseSpell curseSpell = curseSpells[num-1];
				Spell spell;
				spell.Distance = curseSpell.Distance;
				spell.Effect = curseSpell.Effect;
				spell.Level = curseSpell.Level;
				spell.ManaCost = curseSpell.ManaCost;
				spell.Name = curseSpell.Name;
				spell.TimeCast = curseSpell.TimeCast;
				if(oponent.AddUsedSpell(spell))
					cout << "заклинание применено\n";
				curseSpells.pop_back();
			}
			continue;
		}
		if (num == 4)
		{
			num = supportSpells.size();
			if (num == 0)
				cout << "заклинания кончились\n";
			else
			{
				SupportSpell supportSpell = supportSpells[num-1];
				Spell spell;
				spell.Distance = supportSpell.Distance;
				spell.Effect = supportSpell.Effect;
				spell.Level = supportSpell.Level;
				spell.ManaCost = supportSpell.ManaCost;
				spell.Name = supportSpell.Name;
				spell.TimeCast = supportSpell.TimeCast;
				if(oponent.AddUsedSpell(spell))
					cout << "заклинание применено\n";
				supportSpells.pop_back();
			}
			continue;
		}
		if (num == 5)
		{
			oponent.GetInfoSpelsConsole();
			continue;
		}
		if (num == 6)
		{
			cout << "\nколичество заклинаний дальнего боя: " << rangeSpells.size();
			cout << "\nколичество заклинаний ближнего боя: " << meleeSpells.size();
			cout << "\nколичество проклятий: " << curseSpells.size();
			cout << "\nколичество заклинаний поддержки: " << supportSpells.size() << "\n";
			continue;
		}
		if (num == 7)
		{
			rangeSpells.clear();
			meleeSpells.clear();
			curseSpells.clear();
			supportSpells.clear();
			Initialize();
			cout << "Заклинания созданы заново\n";
			continue;
		}
		if (num == 8)
		{
			oponent = Oponent();
			cout << "На поле выходит новый противник!\n";
			continue;
		}
		if (num == 11)
		{


			continue;
		}
		if (num == 9)
			break;
	}
}
