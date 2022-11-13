#include "SparePart.h"

bool SparePart::BreakdownDetail(int i)
{
	srand(time(NULL) + i);
	//int num = min + rand() % (max - min + 1);
	int Incident = 1 + rand() % 101;

	if (Life < Incident)
		return true;
	else return false;
}

bool SparePart::WorkDetail(int useFrequency, int i)
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


void Shaft::Initialize()
{
	TimeForReplacement = 700;
	Life = 100;
	ReplacementCost = 500;
	RepairCost = 200;
	RepairTime = 1;
}

bool Shaft::Breakdown(int i)
{
	return BreakdownDetail(i);
}

bool Shaft::Work(int useFrequency, int i)
{
	return WorkDetail(useFrequency/1.1, i);
}


void ElectroMotor::Initialize()
{
	TimeForReplacement = 750;
	Life = 100;
	RepairCost = 450;
	ReplacementCost = 780;
	RepairTime = 3;
}

bool ElectroMotor::Breakdown(int i)
{
	return BreakdownDetail(i);
}

bool ElectroMotor::Work(int useFrequency, int i)
{
	return WorkDetail(useFrequency / 1.2, i);
}


void ControlPanel::Initialize()
{
	TimeForReplacement = 1000;
	Life = 100;
	ReplacementCost = 250;
	RepairCost = 150;
	RepairTime = 1;
}

bool ControlPanel::Breakdown(int i)
{
	return BreakdownDetail(i);
}

bool ControlPanel::Work(int useFrequency, int i)
{
	return WorkDetail(useFrequency / 1.5, i);
}


void CuttingHead::Initialize()
{
	TimeForReplacement = 700;
	Life = 100;
	ReplacementCost = 300;
	RepairCost = 210;
	RepairTime = 2;
}

bool CuttingHead::Breakdown(int i)
{
	return BreakdownDetail(i);
}

bool CuttingHead::Work(int useFrequency, int i)
{
	return WorkDetail(useFrequency / 1.3, i);
}
