// lb5_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>

#include "Stanok.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int num = 0;
    while (true)
    {
        cout << "1 - работа 1 станка\n";
        cout << "2 - работа цеха\n";
        cin >> num;

        if (num == 1)
        {
            int useFreq = 0;
            long time = 0;

            cout << "введите загрузку станка\n";
            cin >> useFreq;
            cout << "1 - сколько часов работать\n";
            cin >> num;

            Stanok stanok;
            stanok.Create();
            stanok.DoWork(num, useFreq, false);

            cout << "\nвремя работы: " << stanok.Otchet_.WorkTime;
            cout << "\nвремя простоя: " << stanok.Otchet_.DownTime;
            cout << "\nзаменено Валов: " << stanok.Otchet_.ShaftsTeriminateCount;
            cout << "\nзаменено Панелей: " << stanok.Otchet_.TeriminatePanCount;
            cout << "\nзаменено Резаков: " << stanok.Otchet_.TeriminateHeadsCount;
            cout << "\nзаменено Двигателей: " << stanok.Otchet_.TeriminateMotorsCount;
            cout << "\nотремонтированно Валов: " << stanok.Otchet_.RepairShaftsCount;
            cout << "\nотремонтированно Панелей: " << stanok.Otchet_.PanRepairCount;
            cout << "\nотремонтированно Резаков: " << stanok.Otchet_.HeadsRepairCount;
            cout << "\nотремонтированно Двигателей: " << stanok.Otchet_.RepairElectroMotorsCount;
            cout << "\nзатраты: " << stanok.Otchet_.RepairCost << "\n\n";
        }
        else if (num == 2)
        {
            int useFreq = 0;
            int countMachine = 0;
            long time = 12*30*12;

            cout << "введите загрузку цеха\n";
            cin >> useFreq;
            cout << "введите количество станков\n";
            cin >> countMachine;

            Stanok *stanoks = new Stanok[countMachine];
            cout << "год работы:\n";

            for (int i = 0; i < countMachine; i++)
            {
                Stanok stanok;
                stanok.Create();
                stanoks[i] = stanok;
            }

            for (int i = 0; i < countMachine; i++)
            {
                stanoks[i].DoWork(time, useFreq, true);
            }
            Otchet report{};
            for (int i = 0; i < countMachine; i++)
            {
                cout << "\nстанок " << i << "\n";
                cout << "\nвремя работы: " << stanoks[i].Otchet_.WorkTime;
                cout << "\nвремя простоя: " << stanoks[i].Otchet_.DownTime;
                cout << "\nзаменено Валов: " << stanoks[i].Otchet_.ShaftsTeriminateCount;
                cout << "\nзаменено Панелей: " << stanoks[i].Otchet_.TeriminatePanCount;
                cout << "\nзаменено Резаков: " << stanoks[i].Otchet_.TeriminateHeadsCount;
                cout << "\nзаменено Двигателей: " << stanoks[i].Otchet_.TeriminateMotorsCount;
                cout << "\nотремонтированно Валов: " << stanoks[i].Otchet_.RepairShaftsCount;
                cout << "\nотремонтированно Панелей: " << stanoks[i].Otchet_.PanRepairCount;
                cout << "\nотремонтированно Резаков: " << stanoks[i].Otchet_.HeadsRepairCount;
                cout << "\nотремонтированно Двигателей: " << stanoks[i].Otchet_.RepairElectroMotorsCount;
                cout << "\nзатраты: " << stanoks[i].Otchet_.RepairCost << "\n\n";

                report.TeriminatePanCount += stanoks[i].Otchet_.TeriminatePanCount;
                report.TeriminateHeadsCount += stanoks[i].Otchet_.TeriminateHeadsCount;
                report.TeriminateMotorsCount += stanoks[i].Otchet_.TeriminateMotorsCount;
                report.ShaftsTeriminateCount += stanoks[i].Otchet_.ShaftsTeriminateCount;
                report.PanRepairCount += stanoks[i].Otchet_.PanRepairCount;
                report.HeadsRepairCount += stanoks[i].Otchet_.HeadsRepairCount;
                report.RepairElectroMotorsCount += stanoks[i].Otchet_.RepairElectroMotorsCount;
                report.RepairShaftsCount += stanoks[i].Otchet_.RepairShaftsCount;
                report.RepairCost += stanoks[i].Otchet_.RepairCost;
                report.DownTime += stanoks[i].Otchet_.DownTime;
                report.WorkTime += stanoks[i].Otchet_.WorkTime;
            }

            cout << "\nвсе станки" << "\n";
            cout << "\nвремя работы: " << report.WorkTime;
            cout << "\nвремя простоя: " << report.DownTime;
            cout << "\nзаменено Валов: " << report.ShaftsTeriminateCount;
            cout << "\nзаменено Панелей: " << report.TeriminatePanCount;
            cout << "\nзаменено Резаков: " << report.TeriminateHeadsCount;
            cout << "\nзаменено Двигателей: " << report.TeriminateMotorsCount;
            cout << "\nотремонтированно Валов: " << report.RepairShaftsCount;
            cout << "\nотремонтированно Панелей: " << report.PanRepairCount;
            cout << "\nотремонтированно Резаков: " << report.HeadsRepairCount;
            cout << "\nотремонтированно Двигателей: " << report.RepairElectroMotorsCount;
            cout << "\nзатраты: " << report.RepairCost << "\n\n";
        }
    }

}

