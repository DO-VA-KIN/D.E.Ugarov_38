#include "Target.h"


double TargetCircle::HitChance()
{
	double chance = 1 - (double)Size / Distance * Glare;
	return chance;
}

void TargetCircle::HitAdd(int shoots)
{
	Endurance -= shoots;
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

void TargetSquare::HitAdd(int shoots)
{
	Endurance -= shoots;
}

bool TargetSquare::Availability()
{
	if (Endurance > 0)
		return true;
	else return false;
}
