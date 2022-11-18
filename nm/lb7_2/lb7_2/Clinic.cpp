#include "pch.h"
#include "Clinic.h"


Clinic::Clinic(int countWindows, int countVisitors)//создание класса (получает кол-во посетителей)
{
	LivePriority.reserve(1500);//выделение памяти под предполагаемый размер списка
	EnrollmentPriority.reserve(1000);

	Windows.reserve(countWindows);
	Windows = vector<Window>(countWindows);//создание указанного кол-ва окон

	Report.Reception.Windows.resize(countWindows);

	for (int i = 0; countVisitors > 0; i++)//генерация посетителей
	{
		srand(time(NULL) + (double)i/2 - countVisitors);
		//int num = min + rand() % (max - min + 1);
		int chanceVisit = 0 + rand() % 101;

		srand(time(NULL) - (double)i/2 + countVisitors);
		int chanceEnrollment = 0 + rand() % 101;

		if (chanceVisit < ChildVisitor::VisitChance)//дети
		{
			countVisitors--;//создаем нужное кол-во посетителей, уменьшая счетчик до нуля

			Visitor visitor(ChildVisitor::Type(), ChildVisitor::VisitChance,
				ChildVisitor::TimeReceipt(i), ChildVisitor::EnrollmentChance);//Создание посетителя

			if (chanceEnrollment < visitor.EnrollmentChance)//проверка наличия записи
			{
				EnrollmentPriority.push_back(visitor);//добавление в список записанных посетителей
				Report.Queue.Enrollment.Child++;//увелечение счётчика отчёта
			}
			else
			{
				Report.Queue.Live.Child++;//добавление в список живой очереди
				LivePriority.push_back(visitor);//увелечение счётчика отчёта
			}
		}
		else if (chanceVisit < OldVisitor::VisitChance)//пожилые
		{
			countVisitors--;

			Visitor visitor(OldVisitor::Type(), OldVisitor::VisitChance,
				OldVisitor::TimeReceipt(i), OldVisitor::EnrollmentChance);

			if (chanceEnrollment < visitor.EnrollmentChance)
			{
				EnrollmentPriority.push_back(visitor);
				Report.Queue.Enrollment.Old++;
			}
			else
			{
				Report.Queue.Live.Old++;
				LivePriority.push_back(visitor);
			}
		}
		else if (chanceVisit < AdultVisitor::VisitChance)//взрослые
		{
			countVisitors--;

			Visitor visitor(AdultVisitor::Type(), AdultVisitor::VisitChance,
				AdultVisitor::TimeReceipt(i), AdultVisitor::EnrollmentChance);

			if (chanceEnrollment < visitor.EnrollmentChance)
			{
				EnrollmentPriority.push_back(visitor);
				Report.Queue.Enrollment.Adult++;
			}
			else
			{
				Report.Queue.Live.Adult++;
				LivePriority.push_back(visitor);
			}
		}

	}
}


void Clinic::Work(int timeWork, int breakStart, int breakEnd)//работа в течении заданного времени(в минутах), break -интервал перерыва
{
	//обращение к локальной переменной быстрее вызова метода size
	//(а использовать придется часто, значение в пределах ф-ии не меняется)
	int windowsCount = Windows.size();//число окон
	//текущий посетитель
	Visitor visitor(AdultVisitor::Type(), AdultVisitor::VisitChance,
		AdultVisitor::TimeReceipt(0), AdultVisitor::EnrollmentChance);

	for (int i = 0; i < timeWork; i++)
	{
		srand(time(NULL) + (double)i / 2);
		//int num = min + rand() % (max - min + 1);
		int chanceVisit = 0 + rand() % 101;//шанс появления посетителя

		srand(time(NULL) - (double)i / 2);
		int chanceEnrollment = 0 + rand() % 101;//нанс записи посетителя

		if (chanceVisit < ChildVisitor::VisitChance)//дети
		{
			Visitor visitor(ChildVisitor::Type(), ChildVisitor::VisitChance,
				ChildVisitor::TimeReceipt(i), ChildVisitor::EnrollmentChance);//Создание посетителя

			if (chanceEnrollment < visitor.EnrollmentChance)//проверка наличия записи
			{
				EnrollmentPriority.push_back(visitor);//добавление в список записанных посетителей
				Report.Queue.Enrollment.Child++;//увелечение счётчика отчёта
			}
			else
			{
				Report.Queue.Live.Child++;//добавление в список живой очереди
				LivePriority.push_back(visitor);//увелечение счётчика отчёта
			}
		}
		if (chanceVisit < OldVisitor::VisitChance)//пожилые
		{
			Visitor visitor(OldVisitor::Type(), OldVisitor::VisitChance,
				OldVisitor::TimeReceipt(i), OldVisitor::EnrollmentChance);

			if (chanceEnrollment < visitor.EnrollmentChance)
			{
				EnrollmentPriority.push_back(visitor);
				Report.Queue.Enrollment.Old++;
			}
			else
			{
				Report.Queue.Live.Old++;
				LivePriority.push_back(visitor);
			}
		}
		if (chanceVisit < AdultVisitor::VisitChance)//взрослые
		{
			Visitor visitor(AdultVisitor::Type(), AdultVisitor::VisitChance,
				AdultVisitor::TimeReceipt(i), AdultVisitor::EnrollmentChance);

			if (chanceEnrollment < visitor.EnrollmentChance)
			{
				EnrollmentPriority.push_back(visitor);
				Report.Queue.Enrollment.Adult++;
			}
			else
			{
				Report.Queue.Live.Adult++;
				LivePriority.push_back(visitor);
			}
		}

		//перерыв
		if (i > breakStart && i < breakEnd)
		{
			if(i == breakStart + 1)
				for (int k = 0; k < windowsCount; k++)
					while (Windows[k].IsBusy());//окна дорабатывают
			continue;
		}


		for (int k = 0; k < windowsCount; k++)
		{
			if (!Windows[k].IsBusy())//если окно свободно
			{
				if (EnrollmentPriority.empty() && !LivePriority.empty())//по записи
				{
					visitor = LivePriority[0];
					LivePriority.erase(LivePriority.begin());//удаление посетителя из очереди
					if (visitor.Type == ChildVisitor::Type())//заполнение отчёта
					{
						Report.Reception.Windows[k].Child.Count++;
						Report.Reception.Windows[k].Child.TimeSpent += visitor.TimeReceipt;
					}
					else if (visitor.Type == AdultVisitor::Type())
					{
						Report.Reception.Windows[k].Adult.Count++;
						Report.Reception.Windows[k].Adult.TimeSpent += visitor.TimeReceipt;
					}
					else if (visitor.Type == OldVisitor::Type())
					{
						Report.Reception.Windows[k].Old.Count++;
						Report.Reception.Windows[k].Old.TimeSpent += visitor.TimeReceipt;
					}
				}
				else if (!EnrollmentPriority.empty())//живая очередь
				{
					visitor = EnrollmentPriority[0];
					EnrollmentPriority.erase(EnrollmentPriority.begin());
					if (visitor.Type == ChildVisitor::Type())//заполнение отчёта
					{
						Report.Reception.Windows[k].Child.Count++;
						Report.Reception.Windows[k].Child.TimeSpent += visitor.TimeReceipt;
					}
					else if (visitor.Type == AdultVisitor::Type())
					{
						Report.Reception.Windows[k].Adult.Count++;
						Report.Reception.Windows[k].Adult.TimeSpent += visitor.TimeReceipt;
					}
					else if (visitor.Type == OldVisitor::Type())
					{
						Report.Reception.Windows[k].Old.Count++;
						Report.Reception.Windows[k].Old.TimeSpent += visitor.TimeReceipt;
					}
				}
			}
		}
	}

}



//////Окна\\\\\\\

bool Window::IsBusy()//занято ли окно
{
	if (LeftTime > 0)
	{
		LeftTime--;
		return true;
	}
	else return false;
}

void Window::GetVisitor(Visitor visitor)//приём посетителя на обработку
{
	LeftTime = visitor.TimeReceipt;	
}
