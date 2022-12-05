#pragma once
#include <string>

using namespace std;


class Translit //таблица транслитерации
{
public:
	string RuEng(string str)
	{
        for (int i = 0; i < str.length(); i++)
        {
            switch (str[i])
            {
            case 'а': str[i] = 'a'; break;
            case 'б': str[i] = 'b'; break;
            case 'в': str[i] = 'v'; break;
            case 'г': str[i] = 'g'; break;
            case 'д': str[i] = 'd'; break;
            case 'е': str[i] = 'e'; break;
            case 'ё': str.replace(i, 1, "ye"); break;
            case 'ж': str.replace(i, 1, "zh"); break;
            case 'з': str[i] = 'z'; break;
            case 'и': str[i] = 'i'; break;
            case 'й': str[i] = 'y'; break;
            case 'к': str[i] = 'k'; break;
            case 'л': str[i] = 'l'; break;
            case 'м': str[i] = 'm'; break;
            case 'н': str[i] = 'n'; break;
            case 'о': str[i] = 'o'; break;
            case 'п': str[i] = 'p'; break;
            case 'р': str[i] = 'r'; break;
            case 'с': str[i] = 's'; break;
            case 'т': str[i] = 't'; break;
            case 'у': str[i] = 'u'; break;
            case 'ф': str[i] = 'f'; break;
            case 'х': str.replace(i, 1, "ch"); break;
            case 'ц': str[i] = 'z'; break;
            case 'ч': str.replace(i, 1,"ch"); break;
            case 'ш': str.replace(i, 1,"sh"); break;
            case 'щ': str.replace(i, 1,"ch"); break;
            case 'ъ': str.erase(str[i], 1); break;
            case 'ы': str[i] = 'y'; break;
            case 'ь': str.erase(str[i], 1); break;
            case 'э': str[i] = 'e'; break;
            case 'ю': str.replace(i, 1, "yu"); break;
            case 'я': str.replace(i, 1, "ya"); break;
            case 'А': str[i] = 'A'; break;
            case 'Б': str[i] = 'B'; break;
            case 'В': str[i] = 'V'; break;
            case 'Г': str[i] = 'G'; break;
            case 'Д': str[i] = 'D'; break;
            case 'Е': str[i] = 'E'; break;
            case 'Ё': str.replace(i, 1, "Ye"); break;
            case 'Ж': str.replace(i, 1, "Zh"); break;
            case 'З': str[i] = 'Z'; break;
            case 'И': str[i] = 'I'; break;
            case 'Й': str[i] = 'Y'; break;
            case 'К': str[i] = 'K'; break;
            case 'Л': str[i] = 'L'; break;
            case 'М': str[i] = 'M'; break;
            case 'Н': str[i] = 'N'; break;
            case 'О': str[i] = 'O'; break;
            case 'П': str[i] = 'P'; break;
            case 'Р': str[i] = 'R'; break;
            case 'С': str[i] = 'S'; break;
            case 'Т': str[i] = 'T'; break;
            case 'У': str[i] = 'U'; break;
            case 'Ф': str[i] = 'F'; break;
            case 'Х': str.replace(i, 1, "Ch"); break;
            case 'Ц': str[i] = 'Z'; break;
            case 'Ч': str.replace(i, 1, "Ch"); break;
            case 'Ш': str.replace(i, 1, "Sh"); break;
            case 'Щ': str.replace(i, 1, "Ch"); break;
            case 'Ъ': str.erase(str[i],1); break;
            case 'Ы': str[i] = 'Y'; break;
            case 'Ь': str.erase(str[i], 1); break;
            case 'Э': str[i] = 'E'; break;
            case 'Ю': str.replace(i, 1, "Yu"); break;
            case 'Я': str.replace(i, 1, "Ya"); break;            
            }
        }
        return str;
	}
};



class User
{
public:
	string Name;//Имя
	string Surname;//Фамилия
	string Patronymic;//Отчество

	unsigned short Age = 0;//Возраст

	string Login;//Логин
	string Password = "";//Пароль

	bool Activity = false;//Активность

	User(string name, string surname, string patronymic)//конструктор класса (имя, фамилия, отчество)
	{
        Name = name;
        Surname = surname;
        Patronymic = patronymic;

        string s = "";
        s += name[0];
        s += '.';
        s += patronymic[0]; 
        s += '.';
        s += surname;
        Login = Translit().RuEng(s);

	}

    friend std::ostream& operator<< (std::ostream& out, const User& user);//дружественная функция(может взаимодействовать со скрытыми переменными)
};

std::ostream& operator<< (std::ostream& out, const User& user)
{
    // Поскольку operator<< является другом класса User,
    // мы можем напрямую обращаться к членам класса User.
    // здесь выполняется фактический вывод
    out << "Пользователь:\nФИО: " << user.Surname << ' ' << user.Name << ' ' << user.Patronymic << "\nЛогин: "
        << user.Login << "\nВозраст: " << user.Age << "\nАктивность: " << user.Activity << "\n\n";

    // возвращаем std::ostream, для возможности объединить в цепочку вызовы operator<<
    return out;
}