#pragma once
#include <string>

using namespace std;


class Translit //������� ��������������
{
public:
	string RuEng(string str)
	{
        for (int i = 0; i < str.length(); i++)
        {
            switch (str[i])
            {
            case '�': str[i] = 'a'; break;
            case '�': str[i] = 'b'; break;
            case '�': str[i] = 'v'; break;
            case '�': str[i] = 'g'; break;
            case '�': str[i] = 'd'; break;
            case '�': str[i] = 'e'; break;
            case '�': str.replace(i, 1, "ye"); break;
            case '�': str.replace(i, 1, "zh"); break;
            case '�': str[i] = 'z'; break;
            case '�': str[i] = 'i'; break;
            case '�': str[i] = 'y'; break;
            case '�': str[i] = 'k'; break;
            case '�': str[i] = 'l'; break;
            case '�': str[i] = 'm'; break;
            case '�': str[i] = 'n'; break;
            case '�': str[i] = 'o'; break;
            case '�': str[i] = 'p'; break;
            case '�': str[i] = 'r'; break;
            case '�': str[i] = 's'; break;
            case '�': str[i] = 't'; break;
            case '�': str[i] = 'u'; break;
            case '�': str[i] = 'f'; break;
            case '�': str.replace(i, 1, "ch"); break;
            case '�': str[i] = 'z'; break;
            case '�': str.replace(i, 1,"ch"); break;
            case '�': str.replace(i, 1,"sh"); break;
            case '�': str.replace(i, 1,"ch"); break;
            case '�': str.erase(str[i], 1); break;
            case '�': str[i] = 'y'; break;
            case '�': str.erase(str[i], 1); break;
            case '�': str[i] = 'e'; break;
            case '�': str.replace(i, 1, "yu"); break;
            case '�': str.replace(i, 1, "ya"); break;
            case '�': str[i] = 'A'; break;
            case '�': str[i] = 'B'; break;
            case '�': str[i] = 'V'; break;
            case '�': str[i] = 'G'; break;
            case '�': str[i] = 'D'; break;
            case '�': str[i] = 'E'; break;
            case '�': str.replace(i, 1, "Ye"); break;
            case '�': str.replace(i, 1, "Zh"); break;
            case '�': str[i] = 'Z'; break;
            case '�': str[i] = 'I'; break;
            case '�': str[i] = 'Y'; break;
            case '�': str[i] = 'K'; break;
            case '�': str[i] = 'L'; break;
            case '�': str[i] = 'M'; break;
            case '�': str[i] = 'N'; break;
            case '�': str[i] = 'O'; break;
            case '�': str[i] = 'P'; break;
            case '�': str[i] = 'R'; break;
            case '�': str[i] = 'S'; break;
            case '�': str[i] = 'T'; break;
            case '�': str[i] = 'U'; break;
            case '�': str[i] = 'F'; break;
            case '�': str.replace(i, 1, "Ch"); break;
            case '�': str[i] = 'Z'; break;
            case '�': str.replace(i, 1, "Ch"); break;
            case '�': str.replace(i, 1, "Sh"); break;
            case '�': str.replace(i, 1, "Ch"); break;
            case '�': str.erase(str[i],1); break;
            case '�': str[i] = 'Y'; break;
            case '�': str.erase(str[i], 1); break;
            case '�': str[i] = 'E'; break;
            case '�': str.replace(i, 1, "Yu"); break;
            case '�': str.replace(i, 1, "Ya"); break;            
            }
        }
        return str;
	}
};



class User
{
public:
	string Name;//���
	string Surname;//�������
	string Patronymic;//��������

	unsigned short Age = 0;//�������

	string Login;//�����
	string Password = "";//������

	bool Activity = false;//����������

	User(string name, string surname, string patronymic)//����������� ������ (���, �������, ��������)
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

    friend std::ostream& operator<< (std::ostream& out, const User& user);//������������� �������(����� ����������������� �� �������� �����������)
};

std::ostream& operator<< (std::ostream& out, const User& user)
{
    // ��������� operator<< �������� ������ ������ User,
    // �� ����� �������� ���������� � ������ ������ User.
    // ����� ����������� ����������� �����
    out << "������������:\n���: " << user.Surname << ' ' << user.Name << ' ' << user.Patronymic << "\n�����: "
        << user.Login << "\n�������: " << user.Age << "\n����������: " << user.Activity << "\n\n";

    // ���������� std::ostream, ��� ����������� ���������� � ������� ������ operator<<
    return out;
}