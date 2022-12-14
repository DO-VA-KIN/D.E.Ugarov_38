// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "Resheto.h"//шаблон класса реализующего алгоритм "Решето Эратосфена"
#include <iostream>
#include <string> //шаблон класса для работы со строками
#include <vector> //шаблон класса для контейнеров последовательностей

using namespace std; //использование пространств имен для сокращения наименований
using namespace MyNamespace;

///<summary>
///<remarks>основная функция</remarks>
///</summary>
int main()
{
	setlocale(LC_ALL, "Russian");//добавление возможности отображения русского языка

	//автограф - приветствие
	cout << "\nWritten by Ghost: HI!\n\n";

	char str[256];//массив "char" для считывания ввода с консоли
	bool isValidValue = true;//флаг проверки корректности введенного пользователем значения
	int n; //число, до которого будет произведен поиск простых чисел

	//циклическое считывание значения из консоли, пока не будет получено корректное значение
	do
	{
		cout << "Введите число, до которого\nбудет произведен поиск простых чисел\n";//вывод сообщения
		cin >> str;//ввод значения пользователем

		for (char ch : str)
		{
			if (!isdigit(ch))//является ли символ числом
			{
				isValidValue = true;
				break;
			}
		}
	} while (!isValidValue);

	n = atoi(str);//преобразование массива символов в число
	Resheto resheto;//экземпляр класса
	vector<int> vResheto = resheto.Search(n);//простые числа, полученные алгоритмом "Решето Эратосфена"

	int count = 1;//счетчик элементов (для форматирования вывода)
	for(int item : vResheto)//поочередное получение чисел из "Вектора"
	{
		cout <<item <<"\t";//вывод числа в консоль

		if (count++ == 10)//перенос строки через каждые 5 элементов
		{
			count = 1;
			cout << "\n";
		}
	}

	cin >> str;//ожидание подтверждения закрытия программы
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
