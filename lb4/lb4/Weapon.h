#pragma once
#include <string>
#include <time.h>
#include <stdlib.h>
#include <cstdlib>
#include <cmath>

using namespace std;


struct BaseAbilities
{
private:

public:
	string Name[8] = { "˸� � �����","����� � ������","���� � ������","������������","��������","������",
		"�����","��������" };
	string Description[8] = {
		"�����������(����������) ���������� �� 20% ��� ������, ��������� �� 1 ���. ��� �����",
		"������ ���������� ��� ������ � �����",
		"���������� ����� ���������� �� 30% ��� �����, 25% ����� ������� ���������� ��� ������",
		"10% ���� �� �������� ����",
		"10% ���� ������� 5� ����",
		"10% ���� ���������� �������� ����� �� ��������� 10 ������",
		"����� 5 ���������������� ���� ��������� ����� ���������� 2�",
		"5% ���� ��������� ����� ������ ���������� ����� �����"
	};
};

struct BaseWeapons
{
private:

public:
	const string Names[3] = {"���", "���", "���"};
	const int DamageDefence[9] = { 4,5,6, 8,9,10, 12,14,15 };
	const double AttackSpeed[6] = { 1.4, 1.3,  1.1, 1.0,  0.8, 0.65 };
	const string Rarity[3] = { "�������", "������", "���������" };
	BaseAbilities Abilities;
	const int Cost[3] = {100, 150, 120 };
};



class Weapon
{
private:

public:
	Weapon();
	~Weapon();

	string Name;
	int Damage;
	int Defence;
	double AttackSpeed;
	string Rarity;
	string AbilityName;
	string AbilityDescription;
	int Cost;

	void GetRandomWeapon(int i);

};

