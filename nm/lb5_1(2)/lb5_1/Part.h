#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>


class Part
{
public:
	int ReplacementCost;//стоимость замены
	int RepairCost;//стоимость ремонта
	long RepairTime;//врем€ на починку

	bool BreakdownDetail(int i);
	bool WorkDetail(int useFrequency, int i);

	int Life;//состо€ние(проценты)
	int TimeForZamena;
};

class Val: public Part//¬ал
{
public:
	int TimeForZamena = 200;
	void Create();
	bool Breakdown(int i);
	bool DoWork(int useFrequency,int i);
private:
};

class Motor : public Part//Ёлектродвигатель
{
public:
	int TimeForZamena = 250;
	void Create();
	bool Breakdown(int i);
	bool DoWork(int useFrequency, int i);
private:
};

class Panel : public Part//ѕанель ”правлени€
{
public:
	int TimeForZamena = 400;
	void Create();
	bool Breakdown(int i);
	bool DoWork(int useFrequency, int i);
private:
};

class Head : public Part//–ежуща€ головка
{
public:
	int TimeForZamena = 200;
	void Create();
	bool Breakdown(int i);
	bool DoWork(int useFrequency, int i);
private:
};