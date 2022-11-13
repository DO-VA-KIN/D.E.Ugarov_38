#pragma once
#include <ctime>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

///<remarks>����� "����������"</remarks>
class Spell
{
public:
	struct EffectStruct
	{
		string baseNegativeNames[5] = {
		"����������",
		"������",
		"����������",
		"���������",
		"���������"
		};

		string basePositiveNames[5] = {
		"���������",
		"������ ���������� ��������",
		"�������������� ���"
		};

		string Name; // ����������� ������
		int Duration;// ����� ������������ � ������� (1-10)
		int AOE;	 // ������ �� ����� ������������ (1-10)
	};
///<summary>
///<param name="name">��������� ������ - �������� ����������,</param>
///<param name="distance">��������� int - ��������� ����������,</param>
///<param name="effectName">��������� ������ - �������� ������,</param>
///</summary>
	void Initialize(string name, int distance, string effectName, int i);

	string Name; // ��������
	int ManaCost;// ��������� �� 1 �� 100
	int Level;   // ��������� �� 1 �� 10
	tm TimeCast; // ����� ����� �� 1 ���. �� 1 ����
	int Distance;// ��������� �� 1 �� 100
	EffectStruct Effect; // ������������� �����

};

class RangeSpell:public Spell
{
private:

public:
	RangeSpell(int i);
};


class MeleeSpell :public Spell
{
private:

public:
	MeleeSpell(int i);
};


class SupportSpell :public Spell
{
private:

public:
	SupportSpell(int i);
};


class CurseSpell :public Spell
{
private:

public:
	CurseSpell(int i);
};


