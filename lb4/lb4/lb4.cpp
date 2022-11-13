// lb4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "GuildShop.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");//добавление возможности отображения русского языка
	GuildShop shop;//основной класс функций

	cout << "\nWritten by Ghost: HI!\n\n";//автограф - приветствие

	int num;
	cout << "Введите размер магазина\n";
	cin >> num;

	shop.RefreshShop(num);
	while (true)
	{
		cout << "Выберите действие:\n"
			"0) показать луки\n"
			"1) показать мечи\n"
			"2) показать щиты\n"
			"3) оружие в пределах стоимости\n\n";
		cin >> num;


		switch (num)
		{
		case 0:
			for (Weapon weapon : shop.Weapons)
			{
				if (weapon.Name == "Лук")
				{
					cout << "\nКласс: " << weapon.Name << "\n";
					cout << "Редкость: " << weapon.Rarity << "\n";
					cout << "Урон: " << weapon.Damage << "\n";
					cout << "Скорость атаки: " << weapon.AttackSpeed << "\n";
					cout << "Защита: " << weapon.Defence << "\n";
					cout << "Способность: " << weapon.AbilityName << "\n";
					cout << weapon.AbilityDescription << "\n";
					cout << "Стоимость: " << weapon.Cost << "\n\n";
				}
			}
			break;
		case 1:
			for (Weapon weapon : shop.Weapons)
			{
				if (weapon.Name == "Меч")
				{
					cout << "\nКласс: " << weapon.Name << "\n";
					cout << "Редкость: " << weapon.Rarity << "\n";
					cout << "Урон: " << weapon.Damage << "\n";
					cout << "Скорость атаки: " << weapon.AttackSpeed << "\n";
					cout << "Защита: " << weapon.Defence << "\n";
					cout << "Способность: " << weapon.AbilityName << "\n";
					cout << weapon.AbilityDescription << "\n";
					cout << "Стоимость: " << weapon.Cost << "\n\n";
				}
			}
			break;
		case 2:
			for (Weapon weapon : shop.Weapons)
			{
				if (weapon.Name == "Щит")
				{
					cout << "\nКласс: " << weapon.Name << "\n";
					cout << "Редкость: " << weapon.Rarity << "\n";
					cout << "Урон: " << weapon.Damage << "\n";
					cout << "Скорость атаки: " << weapon.AttackSpeed << "\n";
					cout << "Защита: " << weapon.Defence << "\n";
					cout << "Способность: " << weapon.AbilityName << "\n";
					cout << weapon.AbilityDescription << "\n";
					cout << "Стоимость: " << weapon.Cost << "\n\n";
				}
			}
			break;
		case 3:
			cout << "Введите бюджет ";
			cin >> num;
			for (Weapon weapon : shop.Weapons)
			{
				if (weapon.Cost < num)
				{
					cout << "\nКласс: " << weapon.Name << "\n";
					cout << "Редкость: " << weapon.Rarity << "\n";
					cout << "Урон: " << weapon.Damage << "\n";
					cout << "Скорость атаки: " << weapon.AttackSpeed << "\n";
					cout << "Защита: " << weapon.Defence << "\n";
					cout << "Способность: " << weapon.AbilityName << "\n";
					cout << weapon.AbilityDescription << "\n";
					cout << "Стоимость: " << weapon.Cost << "\n\n";
				}
			}
			break;


		default:
			cout << "Спасибо за выбор нашей программы\n";
			return 0;
		}
	}


	cin >> num;
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
