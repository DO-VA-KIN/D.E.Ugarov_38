#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <random>

using namespace std;


class Target
{
protected:
	virtual double HitChance() = 0;//���� ���������
	virtual void HitAdd() = 0;//����������� ���������
	virtual bool Availability() = 0;//����������� ��� ��������
};


class TargetCircle:public Target
{
public:
	double HitChance();//���� ���������
	void HitAdd();//����������� ���������
	bool Availability();//����������� ��� ��������
	int Endurance = 5;//���������
private:
	const int Distance = 20;//���������� �� ����
	const int Size = 4;//������(�����)
	const int Glare = 2;//����������/���������������(0-10)
};


class TargetSquare:public Target
{
public:
	double HitChance();//���� ���������
	void HitAdd();//����������� ���������
	bool Availability();//����������� ��� ��������
	int Endurance = 7;//���������
private:
	const int Distance = 30;//���������� �� ����
	const int Size = 5;//������(�����)
	const int Mobility = 3;//�������� ������(0-10)
};