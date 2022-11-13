#include "pch.h"
#include "Weapon.h"


Weapon::Weapon()
{	
}


Weapon::~Weapon()
{
}

void Weapon::GetRandomWeapon(int i)
{
	setlocale(LC_ALL, "Russian");//добавление возможности отображения русского языка

	BaseWeapons baseWeapons;

	srand(time(NULL) + i);
	//int num = min + rand() % (max - min + 1);
	int ind = rand() % 3;
	Name = baseWeapons.Names[ind];
	Cost = baseWeapons.Cost[ind] + rand() % 20;

	srand(time(NULL) - 2*i);
	ind = rand() % 3;
	Rarity = baseWeapons.Rarity[ind];
	Cost += (ind+1) * 150;

	srand(time(NULL) - ind * i);
	Damage = baseWeapons.DamageDefence[(rand() % 3) + (2 *(ind+1))];

	if (Name == "Щит")
	{
		Defence = Damage;
		Damage /= 2.5;
	}
	else Defence = Damage / 2.5;

	srand(time(NULL) + ind * i);
	ind = (rand() % 2);
	AttackSpeed =  baseWeapons.AttackSpeed[ind + (2 * (ind+1))];

	srand(time(NULL) - ind * i);
	ind = (rand() % 8);
	AbilityName = baseWeapons.Abilities.Name[ind];
	AbilityDescription = baseWeapons.Abilities.Description[ind];
}
