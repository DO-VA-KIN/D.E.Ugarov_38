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
	int ReplacementCost;//��������� ������
	int RepairCost;//��������� �������
	long RepairTime;//����� �� �������

	bool BreakdownDetail(int i);
	bool WorkDetail(int useFrequency, int i);

	int Life;//���������(��������)
	int TimeForReplacement;
};

class Shaft: public SparePart//���
{
public:
	int Life2 = 100;//���������(��������)
	int TimeForReplacement = 200;
	void Initialize();
	bool Breakdown(int i);
	bool Work(int useFrequency,int i);
private:
};

class ElectroMotor : public SparePart//����������������
{
public:
	int TimeForReplacement = 250;
	void Initialize();
	bool Breakdown(int i);
	bool Work(int useFrequency, int i);
private:
};

class ControlPanel : public SparePart//������ ����������
{
public:
	int TimeForReplacement = 400;
	void Initialize();
	bool Breakdown(int i);
	bool Work(int useFrequency, int i);
private:
};

class CuttingHead : public SparePart//������� �������
{
public:
	int TimeForReplacement = 200;
	void Initialize();
	bool Breakdown(int i);
	bool Work(int useFrequency, int i);
private:
};