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

#include "Part.h"

using namespace std;

struct Otchet
{
	int PanRepairCount;//Отремонтированные панели
	int HeadsRepairCount;
	int RepairElectroMotorsCount;
	int RepairShaftsCount;

	int ShaftsTeriminateCount;//Замененные Валы
	int TeriminateMotorsCount;//Замененные Двигатели
	int TeriminatePanCount;//Панели
	int TeriminateHeadsCount;//Резаки
	long WorkTime;//Время работы
	long DownTime;//Время простоя

	long RepairCost;//стоимость ремнта
};

class Stanok
{
public:
	vector<Val> Vals;
	vector<Motor> Motors;
	vector<Panel> Panels;
	vector<Head> Heads;
	long ReplacementTime;//время на замену


	void Create();
	void DoWork(long workTime, int useFrequency, bool changeFreq);
	Otchet Otchet_;//структура отчета
};
