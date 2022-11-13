#include "Stanok.h"

void Stanok::Create()
{
	ReplacementTime = 4;

	Otchet_.PanRepairCount = 0;
	Otchet_.HeadsRepairCount = 0;
	Otchet_.RepairElectroMotorsCount = 0;
	Otchet_.RepairShaftsCount = 0;

	Otchet_.TeriminatePanCount = 0;
	Otchet_.TeriminateHeadsCount = 0;
	Otchet_.TeriminateMotorsCount = 0;
	Otchet_.ShaftsTeriminateCount = 0;
	Otchet_.RepairCost = 0;

	//рандом на количество запчастей
	srand(time(NULL));
	//int num = min + rand() % (max - min + 1);
	int randNum = 1 + rand() % 5;

	for (int i = 0; i < randNum; i++)
	{
		Val val;
		val.Create();
		Vals.push_back(val);
	}

	srand(time(NULL)+1);
	randNum = 1 + rand() % 5;

	for (int i = 0; i < randNum; i++)
	{
		Motor motor;
		motor.Create();
		Motors.push_back(motor);
	}

	srand(time(NULL)-5);
	randNum = 1 + rand() % 5;

	for (int i = 0; i < randNum; i++)
	{
		Panel panel;
		panel.Create();
		Panels.push_back(panel);
	}

	srand(time(NULL)/2);
	randNum = 1 + rand() % 5;

	for (int i = 0; i < randNum; i++)
	{
		Head head;
		head.Create();
		Heads.push_back(head);
	}
}

void Stanok::DoWork(long workTime, int useFrequency, bool changeFreq)
{
	long TotalHour = workTime;

	int downTime = 0;//время простоя
	int chFreq = 30*12;

	for (long i = 0; i < TotalHour; i++)
	{
		//изменение интенсивности(если bool changeFreq true)
		if (i > changeFreq && changeFreq)//случайная смена производства
		{
			srand(time(NULL) + i);
			//int num = min + rand() % (max - min + 1);
			useFrequency = 40 + rand() % 100;
			chFreq += 30 * 12;
		}

		long timeSkip = 0;

		for (int k = 0; k < Vals.size(); k++)
		{
			if (Vals[k].Breakdown(i))
			{
				timeSkip = max(Vals[k].RepairTime, timeSkip);

				Otchet_.RepairShaftsCount += 1;
				Otchet_.RepairCost += Vals[k].RepairCost;
			}
			if (!Vals[k].DoWork(useFrequency, i))
			{
				timeSkip = max(ReplacementTime, timeSkip);
				Otchet_.RepairCost += Vals[k].ReplacementCost;
				Otchet_.ShaftsTeriminateCount += 1;
				Vals[k] = Val();
				Vals[k].Create();
			}
		}

		for (Motor motor : Motors)
		{
			if (motor.Breakdown(i))
			{
				timeSkip = max(motor.RepairTime, timeSkip);

				motor.Life = 100;
				Otchet_.RepairElectroMotorsCount += 1;
				Otchet_.RepairCost += motor.RepairCost;
			}
			if (!motor.DoWork(useFrequency, i))
			{
				timeSkip = max(ReplacementTime, timeSkip);
				Otchet_.RepairCost += motor.ReplacementCost;
				Otchet_.TeriminateMotorsCount += 1;
				motor = Motor();
				motor.Create();
			}
		}

		for (Head head : Heads)
		{
			if (head.Breakdown(i))
			{
				timeSkip = max(head.RepairTime, timeSkip);

				head.Life = 100;
				Otchet_.HeadsRepairCount += 1;
				Otchet_.RepairCost += head.RepairCost;
			}
			if (!head.DoWork(useFrequency, i))
			{
				timeSkip = max(ReplacementTime, timeSkip);
				Otchet_.RepairCost += head.ReplacementCost;
				Otchet_.TeriminateHeadsCount += 1;
				head = Head();
				head.Create();
			}
		}

		for (Panel panel : Panels)
		{
			if (panel.Breakdown(i))
			{
				timeSkip = max(panel.RepairTime, timeSkip);

				panel.Life = 100;
				Otchet_.PanRepairCount += 1;
				Otchet_.RepairCost += panel.RepairCost;
			}
			if (!panel.DoWork(useFrequency, i))
			{
				timeSkip = max(ReplacementTime, timeSkip);
				Otchet_.RepairCost += panel.ReplacementCost;
				Otchet_.TeriminatePanCount += 1;
				panel = Panel();
				panel.Create();
			}

			downTime += timeSkip;
		}

	}
	long workTimeHours = TotalHour - downTime;
	Otchet_.WorkTime = workTimeHours;
	Otchet_.DownTime = downTime;
}

