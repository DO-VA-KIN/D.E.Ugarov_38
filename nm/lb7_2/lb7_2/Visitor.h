#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>


using namespace std;

//(string type, int visitChance, int timeReceipt, int enrollmentChance) 
class Visitor
{
public:
	Visitor(string type, int visitChance, int timeReceipt, int enrollmentChance) 
	{
		Type = type;
		VisitChance = visitChance;
		TimeReceipt = timeReceipt;
		EnrollmentChance = enrollmentChance;
	};

	string Type;//��� ����������(�������, ��������, �������)
	int VisitChance;//���� ��������� ��������(� %)
	int TimeReceipt;//����� �� �����(� ���)
	int EnrollmentChance;//���� ������(� %)
};


static class ChildVisitor
{
public:
	static const string Type() { return "�������"; };
	static const int VisitChance = 5;
	static int TimeReceipt(int i)
	{
		srand(time(NULL) + i);
		//int num = min + rand() % (max - min + 1);
		int timeRec = MinTime + rand() % (MaxTime - MinTime + 1);
		return timeRec;
	};
	static const int EnrollmentChance = 20;
private:
	static const int MinTime = 5;
	static const int MaxTime = 10;
};


static class AdultVisitor
{
public:
	static const string Type() { return "��������"; };
	static const int VisitChance = 40;
	static int TimeReceipt(int i)
	{
		srand(time(NULL) + i);
		//int num = min + rand() % (max - min + 1);
		int timeRec = MinTime + rand() % (MaxTime - MinTime + 1);
		return timeRec;
	};
	static const int EnrollmentChance = 70;
private:
	static const int MinTime = 2;
	static const int MaxTime = 5;
};


static class OldVisitor
{
public:
	static string Type() { return "�������"; };
	static const int VisitChance = 30;
	static int TimeReceipt(int i)
	{
		srand(time(NULL) + i);
		//int num = min + rand() % (max - min + 1);
		int timeRec = MinTime + rand() % (MaxTime - MinTime + 1);
		return timeRec;
	};
	static const int EnrollmentChance = 5;
private:
	static const int MinTime = 7;
	static const int MaxTime = 9;
};