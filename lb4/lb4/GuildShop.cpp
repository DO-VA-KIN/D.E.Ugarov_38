#include "pch.h"
#include "GuildShop.h"


GuildShop::GuildShop()
{
}

GuildShop::~GuildShop()
{
}

void GuildShop::RefreshShop(int shopSize)
{
	Weapons.clear();
	for (size_t i = 0; i < shopSize; i++)
	{
		Weapon weapon;		
		weapon.GetRandomWeapon(i);

		Weapons.push_back(weapon);
	} 

}


