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
	int PanRepairCount;//����������������� ������
	int HeadsRepairCount;
	int RepairElectroMotorsCount;
	int RepairShaftsCount;

	int ShaftsTeriminateCount;//���������� ����
	int TeriminateMotorsCount;//���������� ���������
	int TeriminatePanCount;//������
	int TeriminateHeadsCount;//������
	long WorkTime;//����� ������
	long DownTime;//����� �������

	long RepairCost;//��������� ������
};

class Stanok
{
public:
	vector<Val> Vals;
	vector<Motor> Motors;
	vector<Panel> Panels;
	vector<Head> Heads;
	long ReplacementTime;//����� �� ������


	void Create();
	void DoWork(long workTime, int useFrequency, bool changeFreq);
	Otchet Otchet_;//��������� ������
};
