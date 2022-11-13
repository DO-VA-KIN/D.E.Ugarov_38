#include "Machine.h"

void Machine::Initialize()
{
	ReplacementTime = 4;

	Report_.RepairControlPanelsCount = 0;
	Report_.RepairCuttingHeadsCount = 0;
	Report_.RepairElectroMotorsCount = 0;
	Report_.RepairShaftsCount = 0;

	Report_.DestroyControlPanelsCount = 0;
	Report_.DestroyCuttingHeadsCount = 0;
	Report_.DestroyElectroMotorsCount = 0;
	Report_.DestroyShaftsCount = 0;
	Report_.RepairCost = 0;

	//рандом на количество запчастей
	srand(time(NULL));
	//int num = min + rand() % (max - min + 1);
	int randNum = 1 + rand() % 5;

	for (int i = 0; i < randNum; i++)
	{
		Shaft shaft;
		shaft.Initialize();
		Shafts.push_back(shaft);
	}

	srand(time(NULL)+1);
	randNum = 1 + rand() % 5;

	for (int i = 0; i < randNum; i++)
	{
		ElectroMotor electroMotor;
		electroMotor.Initialize();
		ElectroMotors.push_back(electroMotor);
	}

	srand(time(NULL)-5);
	randNum = 1 + rand() % 5;

	for (int i = 0; i < randNum; i++)
	{
		ControlPanel controlPanel;
		controlPanel.Initialize();
		ControlPanels.push_back(controlPanel);
	}

	srand(time(NULL)/2);
	randNum = 1 + rand() % 5;

	for (int i = 0; i < randNum; i++)
	{
		CuttingHead cuttingHead;
		cuttingHead.Initialize();
		CuttingHeads.push_back(cuttingHead);
	}
}

void Machine::Work(long workTime, int useFrequency, bool changeFreq)
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

		for(Shaft shaft : Shafts)
		{
			if (shaft.Breakdown(i))
			{
				timeSkip = max(shaft.RepairTime, timeSkip);

				Report_.RepairShaftsCount += 1;
				Report_.RepairCost += shaft.RepairCost;
			}
			if (!shaft.Work(useFrequency, i))
			{
				timeSkip = max(ReplacementTime, timeSkip);
				Report_.RepairCost += shaft.ReplacementCost;
				Report_.DestroyShaftsCount += 1;
				shaft = Shaft();
				shaft.Initialize();
			}
		}

		for (ElectroMotor electroMotor : ElectroMotors)
		{
			if (electroMotor.Breakdown(i))
			{
				timeSkip = max(electroMotor.RepairTime, timeSkip);

				electroMotor.Life = 100;
				Report_.RepairElectroMotorsCount += 1;
				Report_.RepairCost += electroMotor.RepairCost;
			}
			if (!electroMotor.Work(useFrequency, i))
			{
				timeSkip = max(ReplacementTime, timeSkip);
				Report_.RepairCost += electroMotor.ReplacementCost;
				Report_.DestroyElectroMotorsCount += 1;
				electroMotor = ElectroMotor();
				electroMotor.Initialize();
			}
		}

		for (CuttingHead cuttingHead : CuttingHeads)
		{
			if (cuttingHead.Breakdown(i))
			{
				timeSkip = max(cuttingHead.RepairTime, timeSkip);

				cuttingHead.Life = 100;
				Report_.RepairCuttingHeadsCount += 1;
				Report_.RepairCost += cuttingHead.RepairCost;
			}
			if (!cuttingHead.Work(useFrequency, i))
			{
				timeSkip = max(ReplacementTime, timeSkip);
				Report_.RepairCost += cuttingHead.ReplacementCost;
				Report_.DestroyCuttingHeadsCount += 1;
				cuttingHead = CuttingHead();
				cuttingHead.Initialize();
			}
		}

		for (ControlPanel controlPanel : ControlPanels)
		{
			if (controlPanel.Breakdown(i))
			{
				timeSkip = max(controlPanel.RepairTime, timeSkip);

				controlPanel.Life = 100;
				Report_.RepairControlPanelsCount += 1;
				Report_.RepairCost += controlPanel.RepairCost;
			}
			if (!controlPanel.Work(useFrequency, i))
			{
				timeSkip = max(ReplacementTime, timeSkip);
				Report_.RepairCost += controlPanel.ReplacementCost;
				Report_.DestroyControlPanelsCount += 1;
				controlPanel = ControlPanel();
				controlPanel.Initialize();
			}

			downTime += timeSkip;
		}

	}
	long workTimeHours = TotalHour - downTime;
	Report_.WorkTime = workTimeHours;
	Report_.DownTime = downTime;
}

