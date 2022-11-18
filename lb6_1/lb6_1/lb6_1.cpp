// lb6_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>

#include "Weapon.h"

using namespace std;


double RandDouble(double i)//получение рандомного double
{
    srand(time(NULL) + i);
    //random_number = firs_value + rand() % last_value;
    int randInt = 0 + rand() % 100;
    double randDouble = (double)randInt / 100;
    return randDouble;
}


int main()
{
    setlocale(LC_ALL, "Russian");

    Tir tir = Tir();//oснoвной класс
    Report report;//отчет
    int num = 0;//действие пользователя
    bool flag = true;//переключатель для стрельбы по всем мишеням

    while (true)
    {
        //очистка
        flag = true;
        srand(time(NULL));
        int randInt = 10 + rand() % 20;
        tir.TargetCircles = vector<TargetCircle>(randInt);
        tir.TargetSquares = vector<TargetSquare>(randInt);
        report = Report();
        report.AllTargets = randInt * 2;

        cout << "\nДобро пожаловать!\nСтрельба в течении минуты:\n"
            << "1) Стрелять одиночными\n"
            << "2) Стрелять очередями\n"
            << "3) Стрелять по усмотрению\n"
            << "5) Выход\n";
        cin >> num;

        if (num == 1)
        {
            int i = 0;//текущая мишень
            double timer = 0;//время(60 сек)
            while (timer < 60)
            {
                if (tir.Weapon.AK47.Magazine > 0)//остались ли патроны
                {
                    tir.Weapon.AK47.Magazine--;
                    timer++;

                    if (!tir.TargetCircles[i].Availability()) 
                    {
                        flag = !flag;
                        report.DestroyedTargets++;
                    }
                    if (!tir.TargetSquares[i].Availability()) 
                    { 
                        flag = !flag;
                        report.DestroyedTargets++;
                        i++; 
                    }

                    if (flag)//по круглым мишеням
                    {
                        if (RandDouble(timer) < tir.TargetCircles[i].HitChance())
                        {
                            tir.TargetCircles[i].HitAdd(1);
                            report.HitsCount++;
                        }
                    }
                    else//по квадратным
                    {
                        if (RandDouble(timer) < tir.TargetSquares[i].HitChance())
                        {
                            tir.TargetSquares[i].HitAdd(1);
                            report.HitsCount++;
                        }
                    }
                    report.Shoots++;
                    timer += 1 + RandDouble(timer);
                }
                else//перезарядка
                {
                    timer += tir.Weapon.AK47.ReloadTime + RandDouble(timer);
                    tir.Weapon.AK47.Magazine = tir.Weapon.AK47.Capacity;
                }
            }
        }
        else if (num == 2)
        {
            int i = 0;//текущая мишень
            double timer = 0;//время(60 сек)
            while (timer < 60)
            {
                if (tir.Weapon.AK47.Magazine > 0)//остались ли патроны
                {
                    tir.Weapon.AK47.Magazine -= 10;
                    timer++;

                    if (!tir.TargetCircles[i].Availability())
                    {
                        flag = !flag;
                        report.DestroyedTargets++;
                    }
                    if (!tir.TargetSquares[i].Availability())
                    {
                        flag = !flag;
                        report.DestroyedTargets++;
                        i++;
                    }

                    if (flag)//по круглым мишеням
                    {
                        if (RandDouble(timer) < tir.TargetCircles[i].HitChance()/2)
                        {
                            tir.TargetCircles[i].HitAdd(10);
                            report.HitsCount += 10;
                        }
                    }
                    else//по квадратным
                    {
                        if (RandDouble(timer) < tir.TargetSquares[i].HitChance())
                        {
                            tir.TargetSquares[i].HitAdd(10);
                            report.HitsCount += 10;
                        }
                    }
                    report.Shoots += 10;
                    timer += 1 + RandDouble(timer);
                }
                else//перезарядка
                {
                    timer += tir.Weapon.AK47.ReloadTime + RandDouble(timer);
                    tir.Weapon.AK47.Magazine = tir.Weapon.AK47.Capacity;
                }
            }
        }
        else if (num == 3)
        {
            int mode = 1;
            int acc = 1;

            int i = 0;//текущая мишень
            double timer = 0;//время(60 сек)
            while (timer < 60)
            {
                if (RandDouble(i) > 0.5)//переключение режима стрельбы
                { mode = 1; acc = 1; }
                else { mode = 10; acc = 2; }

                if (tir.Weapon.AK47.Magazine > 0)//остались ли патроны
                {
                    tir.Weapon.AK47.Magazine -= mode;
                    timer++;

                    if (!tir.TargetCircles[i].Availability())
                    {
                        flag = !flag;
                        report.DestroyedTargets++;
                    }
                    if (!tir.TargetSquares[i].Availability())
                    {
                        flag = !flag;
                        report.DestroyedTargets++;
                        i++;
                    }

                    if (flag)//по круглым мишеням
                    {
                        if (RandDouble(timer) < tir.TargetCircles[i].HitChance()/acc)
                        {
                            tir.TargetCircles[i].HitAdd(mode);
                            report.HitsCount += mode;
                        }
                    }
                    else//по квадратным
                    {
                        if (RandDouble(timer) < tir.TargetSquares[i].HitChance()/acc)
                        {
                            tir.TargetSquares[i].HitAdd(mode);
                            report.HitsCount += mode;
                        }
                    }
                    report.Shoots += mode;
                    timer += 1 + RandDouble(timer);
                }
                else//перезарядка
                {
                    timer += tir.Weapon.AK47.ReloadTime + RandDouble(timer);
                    tir.Weapon.AK47.Magazine = tir.Weapon.AK47.Capacity;
                }
            }
        }
        else if (num == 5)
        {
            break;
        }

        cout << "\nВсего выстрелов: " << report.Shoots
            << "\nПопаданий: " << report.HitsCount
            << "\nМеткость: " << report.Accuracy() << "%"
            //<< "\nВсего целей: " << report.AllTargets
            << "\nУничтожено целей: " << report.DestroyedTargets
            << "\nОсталось целей: " << report.RemainingTargets() << endl;
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
