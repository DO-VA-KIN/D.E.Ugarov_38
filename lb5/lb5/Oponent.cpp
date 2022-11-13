#include "pch.h"
#include "Oponent.h"


Oponent::Oponent()
{
}

bool Oponent::AddUsedSpell(Spell spell)
{
	if (Shield < 1)
	{
		cout << "\n Игрок " << Name << " не может продолжать, получен критический урон\n";
		return false;
	}

	UsedSpells.push_back(spell);
	Shield -= spell.ManaCost / 2;

	if (Shield < 1)
		cout << "\n Игрок " << Name <<" выбывает\n";
}

void Oponent::GetInfoSpelsConsole()
{
	if (UsedSpells.size() == 0)
	{
		cout << "Противник еще не получил урон\n";
		return;
	}
	for (Spell spell : UsedSpells)
	{
		cout << "\n\nНазвание: " << spell.Name;
		cout << "\nДистанция: " << spell.Distance;
		cout << "\nЗатраты маны: " << spell.ManaCost;
		cout << "\nВремя на каст: " << spell.TimeCast.tm_hour << "ч " 
			<< spell.TimeCast.tm_min << "мин " << spell.TimeCast.tm_sec << "с";
		cout << "\nУровень заклинания: " << spell.Level;
		cout << "\nНакладываемый эфект: " << spell.Effect.Name;
		if (spell.Effect.Name != "Отсутсвует")
		{
			cout << "\nДлительность эфекта: " << spell.Effect.Duration << " ходов";
			cout << "\nРадиус эфекта: " << spell.Effect.AOE;
		}
	}
	cout << "\n";

	return;
}


