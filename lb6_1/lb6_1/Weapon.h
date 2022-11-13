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


struct Report//структура отчета
{
	int Shoots = 0;//выстрелов сделано
	int HitsCount = 0;//количество попаданий
	double Accuracy() { return ((double)HitsCount / Shoots) * 100; };//меткость

	int AllTargets = 0;//всего мишеней
	int DestroyedTargets = 0;//уничтоженно мишений
	int RemainingTargets() { return (AllTargets - DestroyedTargets); };//осталось мишений
};

class Weapons//класс со структурами оружий
{
private:
	static struct AK47Struct
	{
		const int Capacity = 30;//вместимость обоймы
		int Magazine = Capacity;//текущий магазин

		double ReloadTime = 2.73;//перезарядка
		double FiringRateAuto = 10;//скорострельность авто(в секунду)
		double FiringRateSingle = 1;//скорострельность одиночными(в секунду)
	};
public:
	AK47Struct AK47;
};


class Tir//класс стрельбища
{
public:
	Weapons Weapon;
	vector<TargetCircle> TargetCircles = vector<TargetCircle>(10);
	vector<TargetSquare> TargetSquares = vector<TargetSquare>(10);
};

