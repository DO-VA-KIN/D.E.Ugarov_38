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
	int ReplacementCost;//��������� ������
	int RepairCost;//��������� �������
	long RepairTime;//����� �� �������

	bool BreakdownDetail(int i);
	bool WorkDetail(int useFrequency, int i);

	int Life;//���������(��������)
	int TimeForZamena;
};

class Val: public Part//���
{
public:
	int TimeForZamena = 200;
	void Create();
	bool Breakdown(int i);
	bool DoWork(int useFrequency,int i);
private:
};

class Motor : public Part//����������������
{
public:
	int TimeForZamena = 250;
	void Create();
	bool Breakdown(int i);
	bool DoWork(int useFrequency, int i);
private:
};

class Panel : public Part//������ ����������
{
public:
	int TimeForZamena = 400;
	void Create();
	bool Breakdown(int i);
	bool DoWork(int useFrequency, int i);
private:
};

class Head : public Part//������� �������
{
public:
	int TimeForZamena = 200;
	void Create();
	bool Breakdown(int i);
	bool DoWork(int useFrequency, int i);
private:
};