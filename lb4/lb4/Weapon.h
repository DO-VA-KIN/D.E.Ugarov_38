#pragma once
#include <string>
#include <time.h>
#include <stdlib.h>
#include <cstdlib>
#include <cmath>

using namespace std;


struct BaseAbilities
{
private:

public:
	string Name[8] = { "Лёд и холод","Пламя и поджег","Гром и молния","Неуязвимость","Агрессия","Ярость",
		"Комбо","Везунчик" };
	string Description[8] = {
		"Обморожение(замедление) противника на 20% при защите, заморозка на 1 сек. при атаке",
		"Поджог противника при защите и атаке",
		"Уменьшение брони противника на 30% при атаке, 25% урона обратно противнику при защите",
		"10% Шанс не получить урон",
		"10% Шанс нанести 5х урон",
		"10% Шанс увеличения скорости атаки на следующие 10 секунд",
		"После 5 последовательных атак множитель урона становится 2х",
		"5% Шанс мгновенно убить любого противника кроме босса"
	};
};

struct BaseWeapons
{
private:

public:
	const string Names[3] = {"Щит", "Лук", "Меч"};
	const int DamageDefence[9] = { 4,5,6, 8,9,10, 12,14,15 };
	const double AttackSpeed[6] = { 1.4, 1.3,  1.1, 1.0,  0.8, 0.65 };
	const string Rarity[3] = { "Обычный", "Редкий", "Эпический" };
	BaseAbilities Abilities;
	const int Cost[3] = {100, 150, 120 };
};



class Weapon
{
private:

public:
	Weapon();
	~Weapon();

	string Name;
	int Damage;
	int Defence;
	double AttackSpeed;
	string Rarity;
	string AbilityName;
	string AbilityDescription;
	int Cost;

	void GetRandomWeapon(int i);

};

