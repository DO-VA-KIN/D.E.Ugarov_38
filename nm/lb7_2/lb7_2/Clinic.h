#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>

#include "Visitor.h"
using namespace std;


//класс окна
class Window
{
public:
	bool IsBusy();//занято ли окно
	void GetVisitor(Visitor visitor);//прием посетителя на обработку
private:
	int LeftTime = 0;//время на посетителя
};


//класс мед учереждения
class Clinic
{
private:
	struct ReportStruct
	{
		struct ReceptionStruct
		{
			struct WindowStruct
			{
				struct ChildStruct
				{
					int Count = 0;
					long TimeSpent = 0;
				};
				struct AdultStruct
				{
					int Count = 0;
					long TimeSpent = 0;
				};
				struct OldStruct
				{
					int Count = 0;
					long TimeSpent = 0;
				};
				ChildStruct Child = ChildStruct();
				AdultStruct Adult = AdultStruct();
				OldStruct Old = OldStruct();

				long GetAllSpentTime() { return Child.TimeSpent + Adult.TimeSpent + Old.TimeSpent; }//всё рабочее(затраченное) время окна
				int GetAllCount() { return Child.Count + Adult.Count + Old.Count; }//все посетители окна
			};
			vector<WindowStruct> Windows = vector<WindowStruct>();//все окна
			long GetSpentTimeChildren()//время затраченное на всех детей (из всех окон)
			{
				long timeSpent = 0;
				for (WindowStruct window : Windows)
					timeSpent += window.Child.TimeSpent;
				return timeSpent;
			}
			long GetSpentTimeAdults()//время затраченное на всех взрослых (из всех окон)
			{
				long timeSpent = 0;
				for (WindowStruct window : Windows)
					timeSpent += window.Adult.TimeSpent;
				return timeSpent;
			}
			long GetSpentTimeOld()//время затраченное на всех пожилых (из всех окон)
			{
				long timeSpent = 0;
				for (WindowStruct window : Windows)
					timeSpent += window.Old.TimeSpent;
				return timeSpent;
			}
			int GetChildren()//все дети (из всех окон)
			{
				int children = 0;
				for (WindowStruct window : Windows)
					children += window.Child.Count;
				return children;
			}
			int GetAdults()//все взрослые (из всех окон)
			{
				int adults = 0;
				for (WindowStruct window : Windows)
					adults += window.Adult.Count;
				return adults;
			}
			int GetOld()//все пожилые (из всех окон)
			{
				int old = 0;
				for (WindowStruct window : Windows)
					old += window.Old.Count;
				return old;
			}
			int GetAllVisitors() { return GetChildren() + GetAdults() + GetOld(); }//все посетители из всех окон
		};
		struct QueueStruct
		{
			struct LiveStruct
			{
				long Child = 0;
				long Adult = 0;
				long Old = 0;
			};
			struct EnrollmentStruct
			{
				long Child = 0;
				long Adult = 0;
				long Old = 0;
			};
			LiveStruct Live = LiveStruct();
			EnrollmentStruct Enrollment = EnrollmentStruct();
			int GetAll()//все посетители 
			{
				return Live.Child + Live.Adult + Live.Old +
					Enrollment.Child + Enrollment.Adult + Enrollment.Old;
			};
		};
		QueueStruct Queue;//по очередям
		ReceptionStruct Reception = ReceptionStruct();//Посетители по окнам		
	};

	vector<Visitor> LivePriority = vector<Visitor>();
	vector<Visitor> EnrollmentPriority = vector<Visitor>();
	vector<Window> Windows = vector<Window>(5);

public:
	Clinic(int countWindows, int countVisitors);//создание класса (получает кол-во окон и посетителей)
	void Work(int timeWork, int breakStart, int breakEnd);//работа в течении заданного времени(в минутах), break -интервал перерыва
	ReportStruct Report = ReportStruct();//структура отчёта
};


