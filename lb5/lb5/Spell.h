#pragma once
#include <ctime>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

///<remarks>Класс "заклинание"</remarks>
class Spell
{
public:
	struct EffectStruct
	{
		string baseNegativeNames[5] = {
		"Отсутсвует",
		"Поджег",
		"Замедление",
		"Истощение",
		"Безмолвие"
		};

		string basePositiveNames[5] = {
		"Исцеление",
		"Снятие негативных эффектов",
		"Восстановление сил"
		};

		string Name; // обозначение эфекта
		int Duration;// время длительности в раундах (1-10)
		int AOE;	 // радиус от точки срабатывания (1-10)
	};
///<summary>
///<param name="name">Принимает строку - название заклинания,</param>
///<param name="distance">Принимает int - дальность применения,</param>
///<param name="effectName">Принимает строку - название ефекта,</param>
///</summary>
	void Initialize(string name, int distance, string effectName, int i);

	string Name; // описание
	int ManaCost;// стоимость от 1 до 100
	int Level;   // сложность от 1 до 10
	tm TimeCast; // время каста от 1 сек. до 1 часа
	int Distance;// дальность от 1 до 100
	EffectStruct Effect; // накладываемый эфект

};

class RangeSpell:public Spell
{
private:

public:
	RangeSpell(int i);
};


class MeleeSpell :public Spell
{
private:

public:
	MeleeSpell(int i);
};


class SupportSpell :public Spell
{
private:

public:
	SupportSpell(int i);
};


class CurseSpell :public Spell
{
private:

public:
	CurseSpell(int i);
};


