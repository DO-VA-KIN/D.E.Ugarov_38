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
	virtual double HitChance() = 0;//шанс попадания
	virtual void HitAdd() = 0;//регистрация попадания
	virtual bool Availability() = 0;//доступность для стрельбы
};


class TargetCircle:public Target
{
public:
	double HitChance();//шанс попадания
	void HitAdd();//регистрация попадания
	bool Availability();//доступность для стрельбы
	int Endurance = 5;//прочность
private:
	const int Distance = 20;//расстояние до цели
	const int Size = 4;//размер(метры)
	const int Glare = 2;//слепимость/отсвечиваемость(0-10)
};


class TargetSquare:public Target
{
public:
	double HitChance();//шанс попадания
	void HitAdd();//регистрация попадания
	bool Availability();//доступность для стрельбы
	int Endurance = 7;//прочность
private:
	const int Distance = 30;//расстояние до цели
	const int Size = 5;//размер(метры)
	const int Mobility = 3;//движение мишени(0-10)
};