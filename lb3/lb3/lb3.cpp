// lb3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "Bancnote.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");//добавление возможности отображения русского языка
	Bancnote bancnoteClass;//основной класс функций

	cout << "\nWritten by Ghost: HI!\n\n";//автограф - приветствие

	int count = 0;
	vector <BancnoteStruct> bancnotes;
	
	cout << "Введите количество купюр\n";
	cin >> count;

	for (int i = 0; i < count; i++)
		bancnotes.push_back(bancnoteClass.RandomBancnote(i));


	while (true)
	{
		cout << "Выберите действие:\n"
			"0) посчитать деньги\n"
			"1) банкноты свыше заданного номинала\n"
			"2) состав кошелька\n"
			"3) перевод в рубли\n";
		cin >> count;


		switch (count)
		{
		case 0:
			cout << "Денег в кошельке: " << bancnoteClass.CountMoney(bancnotes) << " RU\n";
			break;
		case 1:
			cout << "Введите номинал свыше которого хотите искать купюры\n";
			cin >> count;
			for (BancnoteStruct bancnote : bancnotes)
			{
				if (bancnote.Nominal > count)
				{
					cout << "\n" << bancnote.Name;
					cout << "\n" << bancnote.Nominal;
					cout << "\n" << bancnote.kurs << "\n";
				}
			}
			break;
		case 2:
			count = 1;
			bancnotes = bancnoteClass.SortBancnotes(bancnotes);
			for (int i = 1; i < bancnotes.size() - 1; i++)
			{
				if ((bancnotes[i].Name == bancnotes[i + 1].Name) &(bancnotes[i].Nominal == bancnotes[i + 1].Nominal))
				{
					count++;
				}
				else
				{
					cout << "\n" << count << " купюр(ы)";
					cout << "\n" << bancnotes[i].Name;
					cout << "\n" << bancnotes[i].Nominal;
					cout << "\n" << bancnotes[i].kurs << "\n";
					count = 1;
				}
			}

			cout << "\n" << count << " купюр(ы)";
			cout << "\n" << bancnotes[bancnotes.size() - 1].Name;
			cout << "\n" << bancnotes[bancnotes.size() - 1].Nominal;
			cout << "\n" << bancnotes[bancnotes.size() - 1].kurs << "\n\n";

			break;
		case 3:
			count = bancnoteClass.CountMoney(bancnotes);
			cout << "\n" << count / 100 << " банкнот(а) по 100";
			count %= 100;
			cout << "\n" << count / 50 << " банкнот(а) по 50";
			count %= 50;
			cout << "\n" << count / 25 << " банкнот(а) по 25";
			count %= 25;
			cout << "\n" << count / 10 << " банкнот(а) по 10";
			count %= 10;
			cout << "\n" << count / 5 << " банкнот(а) по 5";
			break;


		default:
			cout << "Спасибо за выбор нашей программы\n";
			return 0;
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
