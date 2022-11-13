#pragma once
#include <vector>
#include <iostream>
#include "Spell.h"

using namespace std;

class Oponent
{
private:
	string Name;
	int Shield = 100;
	vector<Spell> UsedSpells;
public:
	Oponent();

	bool AddUsedSpell(Spell spell);
	void GetInfoSpelsConsole();
};







