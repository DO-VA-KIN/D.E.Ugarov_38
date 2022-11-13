#include "pch.h"
#include "Oponent.h"


Oponent::Oponent()
{
}

bool Oponent::AddUsedSpell(Spell spell)
{
	if (Shield < 1)
	{
		cout << "\n ����� " << Name << " �� ����� ����������, ������� ����������� ����\n";
		return false;
	}

	UsedSpells.push_back(spell);
	Shield -= spell.ManaCost / 2;

	if (Shield < 1)
		cout << "\n ����� " << Name <<" ��������\n";
}

void Oponent::GetInfoSpelsConsole()
{
	if (UsedSpells.size() == 0)
	{
		cout << "��������� ��� �� ������� ����\n";
		return;
	}
	for (Spell spell : UsedSpells)
	{
		cout << "\n\n��������: " << spell.Name;
		cout << "\n���������: " << spell.Distance;
		cout << "\n������� ����: " << spell.ManaCost;
		cout << "\n����� �� ����: " << spell.TimeCast.tm_hour << "� " 
			<< spell.TimeCast.tm_min << "��� " << spell.TimeCast.tm_sec << "�";
		cout << "\n������� ����������: " << spell.Level;
		cout << "\n������������� �����: " << spell.Effect.Name;
		if (spell.Effect.Name != "����������")
		{
			cout << "\n������������ ������: " << spell.Effect.Duration << " �����";
			cout << "\n������ ������: " << spell.Effect.AOE;
		}
	}
	cout << "\n";

	return;
}


