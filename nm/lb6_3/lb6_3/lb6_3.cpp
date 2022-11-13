﻿// lb6_3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>

#include "Potok.h"

using namespace std;

int main()
{
	int num = 0;
	setlocale(LC_ALL, "Russian");

	while (true)
	{
		cout << "\nвыберите действие:\n"
			<< "1) int" << endl
			<< "2) double" << endl
			<< "3) string" << endl;
		cin >> num;

		if (num == 1)
		{
			cout << "\nвведите число от 1 до 100" << endl;
			char* str = VvodInt().Read();
			ValidatorInt().Check(str);
		}
		else if (num == 2)
		{
			cout << "\nвведите число от -99.99 до 99.99 (2 знака после запятой)" << endl;
			char* str = VvodDouble().Read();
			ValidatorDouble().Check(str);
		}
		else if (num == 3)
		{
			cout << "\nвведите строку (символ конца ; количество символов = 50)" << endl;
			char* str = VvodString().Read();
			ValidatorString().Check(str);
		}
	}

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