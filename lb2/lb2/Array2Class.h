#pragma once

#include <stdlib.h>//����������� ���������� � ���������� ��������� �����
#include <time.h>//����������� ���������� ��� ��������� ��������� �����, ������������ �� �������


class Array2Class
{
private:
	int N;
	int ** ArrayIM;

	int GetRandomInt(int t);

public:
	Array2Class();
	~Array2Class();

	///<summary>
	///<remarks>������� ������� ����������� ������� "int"</remarks>
	///</summary>
	int GetArraySize();

	///<summary>
	///<remarks>������� ����������� �������</remarks>
	///</summary>
	int** GetArray();


	///<summary>
	///<param name="n">��������� ������ �������</param>
	///<remarks>�������� ���������� �������</remarks>
	///</summary>
	void Initialize(int n);


	///<summary>
	///<remarks>"���������" ��������� �������</remarks>
	///</summary>
	void Clear();


	///<summary>
	///<remarks>�������� ��������� ������� �� ������� ���������</remarks>
	///</summary>
	void Diag1();


	///<summary>
	///<remarks>�������� ��������� ������� �� �������� ���������</remarks>
	///</summary>
	void Diag2();


	///<summary>
	///<remarks>�������� ������������ �������</remarks>
	///</summary>
	void Rectangle();
};

