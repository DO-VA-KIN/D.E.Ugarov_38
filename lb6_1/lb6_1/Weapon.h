#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include "Target.h"

using namespace std;


struct Report//��������� ������
{
	int Shoots = 0;//��������� �������
	int HitsCount = 0;//���������� ���������
	double Accuracy() { return ((double)HitsCount / Shoots) * 100; };//��������

	int AllTargets = 0;//����� �������
	int DestroyedTargets = 0;//����������� �������
	int RemainingTargets() { return (AllTargets - DestroyedTargets); };//�������� �������
};

class Weapons//����� �� ����������� ������
{
private:
	static struct AK47Struct
	{
		const int Capacity = 30;//����������� ������
		int Magazine = Capacity;//������� �������

		double ReloadTime = 2.73;//�����������
		double FiringRateAuto = 10;//���������������� ����(� �������)
		double FiringRateSingle = 1;//���������������� ����������(� �������)
	};
public:
	AK47Struct AK47;
};


class Tir//����� ����������
{
public:
	Weapons Weapon;
	vector<TargetCircle> TargetCircles = vector<TargetCircle>(10);
	vector<TargetSquare> TargetSquares = vector<TargetSquare>(10);
};

