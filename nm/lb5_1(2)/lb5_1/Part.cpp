#include "Part.h"

bool Part::BreakdownDetail(int i)
{
	srand(time(NULL) + i);
	//int num = min + rand() % (max - min + 1);
	int Incident = 1 + rand() % 101;

	if (Life < Incident)
		return true;
	else return false;
}

bool Part::WorkDetail(int useFrequency, int i)
{
	srand(time(NULL) + i);
	//int num = min + rand() % (max - min + 1);
	int LifeEnd = 1 + rand() % 100;

	Life -= useFrequency / 50;
	if (Life < LifeEnd)
		return false;
	else
	{
		return true;
	}
}


void Val::Create()
{
	TimeForZamena = 700;
	Life = 100;
	ReplacementCost = 500;
	RepairCost = 200;
	RepairTime = 1;
}

bool Val::Breakdown(int i)
{
	return BreakdownDetail(i);
}

bool Val::DoWork(int useFrequency, int i)
{
	return WorkDetail(useFrequency/1.1, i);
}


void Motor::Create()
{
	TimeForZamena = 750;
	Life = 100;
	RepairCost = 450;
	ReplacementCost = 780;
	RepairTime = 3;
}

bool Motor::Breakdown(int i)
{
	return BreakdownDetail(i);
}

bool Motor::DoWork(int useFrequency, int i)
{
	return WorkDetail(useFrequency / 1.2, i);
}


void Panel::Create()
{
	TimeForZamena = 1000;
	Life = 100;
	ReplacementCost = 250;
	RepairCost = 150;
	RepairTime = 1;
}

bool Panel::Breakdown(int i)
{
	return BreakdownDetail(i);
}

bool Panel::DoWork(int useFrequency, int i)
{
	return WorkDetail(useFrequency / 1.5, i);
}


void Head::Create()
{
	TimeForZamena = 700;
	Life = 100;
	ReplacementCost = 300;
	RepairCost = 210;
	RepairTime = 2;
}

bool Head::Breakdown(int i)
{
	return BreakdownDetail(i);
}

bool Head::DoWork(int useFrequency, int i)
{
	return WorkDetail(useFrequency / 1.3, i);
}
