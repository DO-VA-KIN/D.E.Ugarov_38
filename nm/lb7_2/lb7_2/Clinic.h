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


//����� ����
class Window
{
public:
	bool IsBusy();//������ �� ����
	void GetVisitor(Visitor visitor);//����� ���������� �� ���������
private:
	int LeftTime = 0;//����� �� ����������
};


//����� ��� �����������
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

				long GetAllSpentTime() { return Child.TimeSpent + Adult.TimeSpent + Old.TimeSpent; }//�� �������(�����������) ����� ����
				int GetAllCount() { return Child.Count + Adult.Count + Old.Count; }//��� ���������� ����
			};
			vector<WindowStruct> Windows = vector<WindowStruct>();//��� ����
			long GetSpentTimeChildren()//����� ����������� �� ���� ����� (�� ���� ����)
			{
				long timeSpent = 0;
				for (WindowStruct window : Windows)
					timeSpent += window.Child.TimeSpent;
				return timeSpent;
			}
			long GetSpentTimeAdults()//����� ����������� �� ���� �������� (�� ���� ����)
			{
				long timeSpent = 0;
				for (WindowStruct window : Windows)
					timeSpent += window.Adult.TimeSpent;
				return timeSpent;
			}
			long GetSpentTimeOld()//����� ����������� �� ���� ������� (�� ���� ����)
			{
				long timeSpent = 0;
				for (WindowStruct window : Windows)
					timeSpent += window.Old.TimeSpent;
				return timeSpent;
			}
			int GetChildren()//��� ���� (�� ���� ����)
			{
				int children = 0;
				for (WindowStruct window : Windows)
					children += window.Child.Count;
				return children;
			}
			int GetAdults()//��� �������� (�� ���� ����)
			{
				int adults = 0;
				for (WindowStruct window : Windows)
					adults += window.Adult.Count;
				return adults;
			}
			int GetOld()//��� ������� (�� ���� ����)
			{
				int old = 0;
				for (WindowStruct window : Windows)
					old += window.Old.Count;
				return old;
			}
			int GetAllVisitors() { return GetChildren() + GetAdults() + GetOld(); }//��� ���������� �� ���� ����
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
			int GetAll()//��� ���������� 
			{
				return Live.Child + Live.Adult + Live.Old +
					Enrollment.Child + Enrollment.Adult + Enrollment.Old;
			};
		};
		QueueStruct Queue;//�� ��������
		ReceptionStruct Reception = ReceptionStruct();//���������� �� �����		
	};

	vector<Visitor> LivePriority = vector<Visitor>();
	vector<Visitor> EnrollmentPriority = vector<Visitor>();
	vector<Window> Windows = vector<Window>(5);

public:
	Clinic(int countWindows, int countVisitors);//�������� ������ (�������� ���-�� ���� � �����������)
	void Work(int timeWork, int breakStart, int breakEnd);//������ � ������� ��������� �������(� �������), break -�������� ��������
	ReportStruct Report = ReportStruct();//��������� ������
};


