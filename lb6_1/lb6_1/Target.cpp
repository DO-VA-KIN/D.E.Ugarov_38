#include "Target.h"


double TargetCircle::HitChance()
{
	double chance = 1 - (double)Size / Distance * Glare;
	return chance;
}

void TargetCircle::HitAdd()
{
	Endurance--;
}

bool TargetCircle::Availability()
{
	if (Endurance > 0)
		return true;
	else return false;
}





double TargetSquare::HitChance()
{
	double chance = 1 - (double)Size / Distance * Mobility;
	return chance;
}

void TargetSquare::HitAdd()
{
	Endurance--;
}

bool TargetSquare::Availability()
{
	if (Endurance > 0)
		return true;
	else return false;
}
