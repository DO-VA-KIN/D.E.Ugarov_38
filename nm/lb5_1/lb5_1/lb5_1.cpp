// lb5_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>

#include "Machine.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");//добавление возможности отображения русского языка

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
            cout << "1 - работать день (12 часов)\n";
            cout << "2 - работать месяц\n";
            cout << "3 - работать год\n";
            cin >> num;

            switch (num)
            {       
            case 1: time = 12; break;
            case 2: time = 12 * 30; break;
            case 3: time = 12 * 30 * 12; break;
            default:
                continue;
            }

            Machine machine;
            machine.Initialize();
            machine.Work(time, useFreq, false);

            cout << "\nвремя работы: " << machine.Report_.WorkTime;
            cout << "\nвремя простоя: " << machine.Report_.DownTime;

            cout << "\nотремонтированно Валов: " << machine.Report_.RepairShaftsCount;
            cout << "\nотремонтированно Панелей: " << machine.Report_.RepairControlPanelsCount;
            cout << "\nотремонтированно Резаков: " << machine.Report_.RepairCuttingHeadsCount;
            cout << "\nотремонтированно Двигателей: " << machine.Report_.RepairElectroMotorsCount;

            cout << "\nзаменено Валов: " << machine.Report_.DestroyShaftsCount;
            cout << "\nзаменено Панелей: " << machine.Report_.DestroyControlPanelsCount;
            cout << "\nзаменено Резаков: " << machine.Report_.DestroyCuttingHeadsCount;
            cout << "\nзаменено Двигателей: " << machine.Report_.DestroyElectroMotorsCount;

            cout << "\nзатраты: " << machine.Report_.RepairCost << "\n\n";
        }
        else if (num == 2)
        {
            int useFreq = 0;
            int countMachine = 0;
            long time = 0;

            cout << "введите загрузку цеха\n";
            cin >> useFreq;
            cout << "введите количество станков\n";
            cin >> countMachine;

            Machine *machines = new Machine[countMachine];

            cout << "1 - работать день (12 часов)\n";
            cout << "2 - работать месяц\n";
            cout << "3 - работать год\n";
            cin >> num;

            switch (num)
            {
            case 1: time = 12; break;
            case 2: time = 12 * 30; break;
            case 3: time = 12 * 30 * 12; break;
            default:
                continue;
            }
            for (int i = 0; i < countMachine; i++)
            {
                Machine machine;
                machine.Initialize();
                machines[i] = machine;
            }

            for (int i = 0; i < countMachine; i++)
            {
                machines[i].Work(time, useFreq, true);
            }
            Report report{};
            for (int i = 0; i < countMachine; i++)
            {
                cout << "\nстанок " << i << "\n";
                cout << "\nвремя работы: " << machines[i].Report_.WorkTime;
                cout << "\nвремя простоя: " << machines[i].Report_.DownTime;

                cout << "\nотремонтированно Валов: " << machines[i].Report_.RepairShaftsCount;
                cout << "\nотремонтированно Панелей: " << machines[i].Report_.RepairControlPanelsCount;
                cout << "\nотремонтированно Резаков: " << machines[i].Report_.RepairCuttingHeadsCount;
                cout << "\nотремонтированно Двигателей: " << machines[i].Report_.RepairElectroMotorsCount;

                cout << "\nзаменено Валов: " << machines[i].Report_.DestroyShaftsCount;
                cout << "\nзаменено Панелей: " << machines[i].Report_.DestroyControlPanelsCount;
                cout << "\nзаменено Резаков: " << machines[i].Report_.DestroyCuttingHeadsCount;
                cout << "\nзаменено Двигателей: " << machines[i].Report_.DestroyElectroMotorsCount;

                cout << "\nзатраты: " << machines[i].Report_.RepairCost << "\n\n";

                report.DestroyControlPanelsCount += machines[i].Report_.DestroyControlPanelsCount;
                report.DestroyCuttingHeadsCount += machines[i].Report_.DestroyCuttingHeadsCount;
                report.DestroyElectroMotorsCount += machines[i].Report_.DestroyElectroMotorsCount;
                report.DestroyShaftsCount += machines[i].Report_.DestroyShaftsCount;
                report.RepairControlPanelsCount += machines[i].Report_.RepairControlPanelsCount;
                report.RepairCuttingHeadsCount += machines[i].Report_.RepairCuttingHeadsCount;
                report.RepairElectroMotorsCount += machines[i].Report_.RepairElectroMotorsCount;
                report.RepairShaftsCount += machines[i].Report_.RepairShaftsCount;
                report.RepairCost += machines[i].Report_.RepairCost;

                report.DownTime += machines[i].Report_.DownTime;
                report.WorkTime += machines[i].Report_.WorkTime;
            }

            cout << "\nвсе станки" << "\n";
            cout << "\nвремя работы: " << report.WorkTime;
            cout << "\nвремя простоя: " << report.DownTime;

            cout << "\nотремонтированно Валов: " << report.RepairShaftsCount;
            cout << "\nотремонтированно Панелей: " << report.RepairControlPanelsCount;
            cout << "\nотремонтированно Резаков: " << report.RepairCuttingHeadsCount;
            cout << "\nотремонтированно Двигателей: " << report.RepairElectroMotorsCount;

            cout << "\nзаменено Валов: " << report.DestroyShaftsCount;
            cout << "\nзаменено Панелей: " << report.DestroyControlPanelsCount;
            cout << "\nзаменено Резаков: " << report.DestroyCuttingHeadsCount;
            cout << "\nзаменено Двигателей: " << report.DestroyElectroMotorsCount;

            cout << "\nзатраты: " << report.RepairCost << "\n\n";
        }
    }

}

