﻿// lb2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>

#include "Array2Class.h"


using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");//добавление возможности отображения русского языка
	cout << "\nWritten by Ghost: HI!\n\n";//автограф - приветствие
	
	cout << "Укажите размерность массива\n";
	int n = 0;
	cin >> n;

	Array2Class arrayClass;
	arrayClass.Initialize(n);
	arrayClass.Clear();
	while (true)
	{
		cout << "Выберите действие:\n"
			"0) заполнить нулями\n"
			"1) симетрия по главной диагонали\n"
			"2) симетрия по побочной диагонали\n"
			"3) треугольник Паскаля\n"
			"4) сапер\n";

		cin >> n;


		switch (n)
		{
		case 0:

			break;
		case 1:
			arrayClass.Diag1();
			break;
		case 2:
			arrayClass.Diag2();
			break;
		case 3:
			arrayClass.Rectangle();
			break;
		case 4:
			//
			break;

		default:
			cout << "Спасибо за выбор нашей программы\n";
			break;
		}

		int** arr = arrayClass.GetArray();
		n = arrayClass.GetArraySize();

		for (int i = 0; i < n; i++)
		{
			string str = "";

			for (int j = 0; j < n; j++)
			{
				str += to_string(arr[i][j]) + "\t";
			}

			cout << str << "\n";
		}
	}
	cin >> n;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
