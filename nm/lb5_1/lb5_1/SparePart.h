#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>


class SparePart
{
public:
	int ReplacementCost;//стоимость замены
	int RepairCost;//стоимость ремонта
	long RepairTime;//врем€ на починку

	bool BreakdownDetail(int i);
	bool WorkDetail(int useFrequency, int i);

	int Life;//состо€ние(проценты)
	int TimeForReplacement;
};

class Shaft: public SparePart//¬ал
{
public:
	int Life2 = 100;//состо€ние(проценты)
	int TimeForReplacement = 200;
	void Initialize();
	bool Breakdown(int i);
	bool Work(int useFrequency,int i);
private:
};

class ElectroMotor : public SparePart//Ёлектродвигатель
{
public:
	int TimeForReplacement = 250;
	void Initialize();
	bool Breakdown(int i);
	bool Work(int useFrequency, int i);
private:
};

class ControlPanel : public SparePart//ѕанель ”правлени€
{
public:
	int TimeForReplacement = 400;
	void Initialize();
	bool Breakdown(int i);
	bool Work(int useFrequency, int i);
private:
};

class CuttingHead : public SparePart//–ежуща€ головка
{
public:
	int TimeForReplacement = 200;
	void Initialize();
	bool Breakdown(int i);
	bool Work(int useFrequency, int i);
private:
};