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
	int RepairControlPanelsCount;//����������������� ������
	int RepairCuttingHeadsCount;
	int RepairElectroMotorsCount;
	int RepairShaftsCount;

	int DestroyShaftsCount;//���������� ����
	int DestroyElectroMotorsCount;//���������� ���������
	int DestroyControlPanelsCount;//������
	int DestroyCuttingHeadsCount;//������
	long WorkTime;//����� ������
	long DownTime;//����� �������

	long RepairCost;//��������� ������
};

class Machine
{
public:
	vector<Shaft> Shafts;
	vector<ElectroMotor> ElectroMotors;
	vector<ControlPanel> ControlPanels;
	vector<CuttingHead> CuttingHeads;
	long ReplacementTime;//����� �� ������


	void Initialize();
	void Work(long workTime, int useFrequency, bool changeFreq);
	Report Report_;//��������� ������
};
