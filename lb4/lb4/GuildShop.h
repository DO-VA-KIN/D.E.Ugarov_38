#pragma once
#include <vector>
#include "Weapon.h"

using namespace std;

class GuildShop
{
private:

public:
	GuildShop();
	~GuildShop();

	vector<Weapon> Weapons;


	void RefreshShop(int shopSize);
};

