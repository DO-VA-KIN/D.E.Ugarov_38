#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <math.h>

#include "SparePart.h"

using namespace std;

struct Report
{
	int RepairControlPanelsCount;//Отремонтированные панели
	int RepairCuttingHeadsCount;
	int RepairElectroMotorsCount;
	int RepairShaftsCount;

	int DestroyShaftsCount;//Замененные Валы
	int DestroyElectroMotorsCount;//Замененные Двигатели
	int DestroyControlPanelsCount;//Панели
	int DestroyCuttingHeadsCount;//Резаки
	long WorkTime;//Время работы
	long DownTime;//Время простоя

	long RepairCost;//стоимость ремнта
};

class Machine
{
public:
	vector<Shaft> Shafts;
	vector<ElectroMotor> ElectroMotors;
	vector<ControlPanel> ControlPanels;
	vector<CuttingHead> CuttingHeads;
	long ReplacementTime;//время на замену


	void Initialize();
	void Work(long workTime, int useFrequency, bool changeFreq);
	Report Report_;//структура отчета
};
