#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
#include <iterator>
#include <thread>
#include <chrono>
#include "User.h"

using namespace std;


static User Generator()//ф-ия генератор 
{
    //setlocale(LC_ALL, "Russian");
    struct AL
    {
        string names[5]{ "Dmitry","Sergey","Kate","Olga","Semen" };//Библиотека не способна работать с русским языком
        string surnames[5]{ "Ivanov","Sidorov","Knyzkova","Tihonova","Priluchniy" };
        string patronymic[5]{ "Evgenevich","Иванович","Victorovna","Sergeevna","Georgievich" };
    };
    AL al;

    string name = "";
    string surname = "";
    string Patronymic = "";

    //int num = min + rand() % (max - min + 1);
    int num = 0 + rand() % 5;
    name = al.names[num];
    surname = al.surnames[num];
    Patronymic = al.patronymic[num];

    int age = 5 + rand() % 96;
    bool activity;
    if (0 + rand() % 2 == 0)
        activity = false;
    else activity = true;

    User user(name, surname, Patronymic);
    user.Activity = activity;
    user.Age = age;
    return user;
}

    int Age1 = 0;//глобальные переменные для алгоритмов
    string Name1 = "";
    string Surname1 = "";
    unsigned int num = 0;
    bool Older(User user) { return user.Age > Age1; };//проверка возраста
    bool Active(User user) { return user.Activity == true; };//проверка активности
    bool Hewing(User user) { return user.Surname == Surname1; };//проверка на однофамильцев
    bool FullHewing(User user) { return user.Name == Name1 && user.Surname == Surname1;; };//проверка на полных тёсок(совпадение по имени и фамилии)

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");

    vector<User> vec;
    generate_n(back_inserter(vec), 10, Generator);//генерация
    for (User user : vec)
        cout << user;
 
    cout << "\nВведите возраст: ";
    cin >> Age1;
    for (vector<User>::iterator it = vec.begin(); it != vec.end(); it++)//вывод пользователей старше заданного возраста
    {
        it = find_if(it, vec.end(), Older);
        cout << *it;
        //this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    int count = count_if(vec.begin(), vec.end(), Active);//подсчет активных и неактивных пользователей
    cout << "активных пользователей: " << count << "\n";
    cout << "неактивных пользователей: " << vec.size() - count << "\n";

    cout << "\nКоличество однофамильцев: " << endl;//подсчет однофамильцев
    vector<string> vs;
    for (vector<User>::iterator it = vec.begin(); it != vec.end(); it++)
    {
        User us = *it;
        Surname1 = us.Surname;
        if (find(vs.begin(), vs.end(), us.Surname) != vs.end()) continue;//пропускаем уже посчитанных однофамильцев
        vs.push_back(us.Surname);
        cout << us.Surname <<": " << count_if(it, vec.end(), Hewing) << endl;
    }


    cout << "\nКоличество полных тесок: " << endl;//подсчет полных тесок
    vector<string> vs1;//имена
    vector<string> vs2;//фамилии
    for (vector<User>::iterator it = vec.begin(); it != vec.end(); it++)
    {
        User us = *it;
        Name1 = us.Name;
        Surname1 = us.Surname;
        if (find(vs2.begin(), vs2.end(), us.Surname) != vs2.end() &&
            find(vs1.begin(), vs1.end(), us.Name) != vs1.end()) continue;//пропускаем уже посчитанных тёсок
        vs1.push_back(us.Name);
        vs2.push_back(us.Surname);
        cout << us.Name << " " << us.Surname << ": " << count_if(it, vec.end(), FullHewing) << endl;
    }

    User user("Екатерина", "Князькова", "Андреевна");//для демонстрации транслита
    cout << user.Login;
}

