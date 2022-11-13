#include "pch.h"
#include "Spell.h"


void Spell::Initialize(string name, int distance, string effectName, int i)
{	
	Name = name;
	Distance = distance;
	Effect.Name = effectName;

	srand(time(NULL) + i);
	//int num = min + rand() % (max - min + 1);
	ManaCost = 1 + rand() % 100;

	i = Distance % 15;
	srand(time(NULL) + i);
	Level = 1 + rand() % 10;

	if (effectName == "Отсутсвует")
	{
		Effect.Duration = 0;
		Effect.AOE = 0;
	}
	else
	{
		i = Distance % 7;
		srand(time(NULL) + i);
		Effect.Duration = 1 + rand() % 10;

		i = Distance % 13;
		srand(time(NULL) + i);
		Effect.AOE = 1 + rand() % 10;
	}

	i = 1 + rand() % 3600;
	TimeCast.tm_hour = i / 3600;
	TimeCast.tm_min = i / 60;
	TimeCast.tm_sec = i % 60;
}




RangeSpell::RangeSpell(int i)
{
	string names[3] = {
		"Выстрел",
		"Притяжение",
		"Молния"
	};
	EffectStruct effects;

	srand(time(NULL) + i);
	//int num = min + rand() % (max - min + 1);
	int indName = 0 + rand() % 3;
	int distance = 51 + rand() % 50;
	int indEffect = 0 + rand() % 5;
	Initialize(names[indName], distance, effects.baseNegativeNames[indEffect], i);
}

MeleeSpell::MeleeSpell(int i)
{
	string names[3] = {
	"Удар",
	"Толчок",
	"Вспышка"
	};
	EffectStruct effects;

	srand(time(NULL) + i);
	//int num = min + rand() % (max - min + 1);
	int indName = 0 + rand() % 3;
	int distance = 1 + rand() % 50;
	int indEffect = 0 + rand() % 5;
	Initialize(names[indName], distance, effects.baseNegativeNames[indEffect], i);
}

SupportSpell::SupportSpell(int i)
{
	string names[3] = {
	"Восход",
	"Благославение",
	"Второе дыхание"
	};
	EffectStruct effects;

	srand(time(NULL) + i);
	//int num = min + rand() % (max - min + 1);
	int indName = 0 + rand() % 3;
	int distance = 1 + rand() % 10;
	Initialize(names[indName], distance, effects.basePositiveNames[indName], i);
}

CurseSpell::CurseSpell(int i)
{
	string names[4] = {
	"Уничтожение",
	"Презрение",
	"Исход",
	"Черное солнце"
	};
	EffectStruct effects;

	srand(time(NULL) + i);
	//int num = min + rand() % (max - min + 1);
	int indName = 0 + rand() % 4;
	int distance = 1 + rand() % 50;
	Initialize(names[indName], distance, effects.baseNegativeNames[indName], i);
}
