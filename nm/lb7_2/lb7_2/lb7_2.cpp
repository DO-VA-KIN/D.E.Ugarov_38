#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>

#include "Clinic.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	int num = -1;//выбор действия
	int numsWindow = 5;
	int numsVisitor = 10;

	while (true)
	{
		cout << "введите количество окон" << endl;
		cin >> numsWindow;
		cout << "введите начальное количество посетителей" << endl;
		cin >> numsVisitor;

		Clinic clinic(numsWindow, numsVisitor);
		clinic.Work(540, 240, 300);

		//int processedVisitors = clinic.Report.Queue.Enrollment.Child + clinic.Report.Queue.A. + clinic.Report.Queue.Live;
		cout << "\nКоличество обработанных посетителей: " << clinic.Report.Reception.GetAllVisitors() << endl;
		cout << "Количество необработанных посетителей: " << clinic.Report.Queue.GetAll() - 
			clinic.Report.Reception.GetAllVisitors() << endl;
		cout << "\nВремя затраченное на детей: " << clinic.Report.Reception.GetSpentTimeChildren() << endl;
		cout << "Время затраченное на взрослых: " << clinic.Report.Reception.GetSpentTimeAdults() << endl;
		cout << "Время затраченное на пожилых: " << clinic.Report.Reception.GetSpentTimeOld() << endl;

		cout << "\nПосетители ресепшена: " << endl;
		for (int i = 0; i < clinic.Report.Reception.Windows.size(); i++)
		{
			cout << "\nОкно №: " << i + 1 << endl;
			cout << "Дети: " << clinic.Report.Reception.Windows[i].Child.Count << endl;
			cout << "Взрослые: " << clinic.Report.Reception.Windows[i].Adult.Count << endl;
			cout << "Пожилые: " << clinic.Report.Reception.Windows[i].Old.Count << endl;
		}

		cout << "\nПосетители по записи: " << endl;
		cout << "Дети: " << clinic.Report.Queue.Enrollment.Child << endl;
		cout << "Взрослые: " << clinic.Report.Queue.Enrollment.Adult << endl;
		cout << "Пожилые: " << clinic.Report.Queue.Enrollment.Old << endl;

		cout << "\nПосетители без записи: " << endl;
		cout << "Дети: " << clinic.Report.Queue.Live.Child << endl;
		cout << "Взрослые: " << clinic.Report.Queue.Live.Adult << endl;
		cout << "Пожилые: " << clinic.Report.Queue.Live.Old << endl;

		cout << "\n\nповторное моделирование - 0\nвыход - 1" << endl;
		cin >> num;
		if (num == 1) break;
	}	

}


