
#include "pch.h"
#include "Potok.h"

//интерфейсный класс считывателя
char * Vvod::Read()
{
	return nullptr;
}


char* VvodInt::Read()
{
	cin.ignore();//пропуск первого переноса строки
	//cin.getline(str, 5, ';');
	char ch = 0;
	char* str = new char[5];
	for (short i = 0; i < 5; i++)
	{
		cin.get(ch);//получаем ввод посимвольно
		if (ch == ' ' || ch == '\t')//пропускаем пробелы и табуляцию
			continue;
		if (ch == ';' || ch == '\n')//заканчиваем ввод при нажатии ; или enter
			break;
		else str[i] = ch;
	}
	if (ch != '\n')
		cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	return str;
}

char* VvodDouble::Read()
{
	cin.ignore();//пропуск первого переноса строки
	char ch = 0;
	char* str = new char[15];
	short count = 0;
	for (short i = 0; i < 15; i++)
	{
		cin.get(ch);//получаем ввод посимвольно
		if (ch == '.') ch = ',';//допускаем возможность ввода и через точку и через запятую 
		if (ch == ',' || count > 0) count++;//счетчик знаков после запятой

		if (ch == ' ' || ch == '\t')//пропускаем пробелы и табуляцию
			continue;
		if (ch == ';' || ch == '\n')//заканчиваем ввод при нажатии ; или enter
			break;
		else str[i] = ch;

		if (count > 2) break;//после 2х знаков после запятой ввод прерывается
	}
	if (ch != '\n')
		cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	return str;
}

char* VvodString::Read()
{
	char ch = 0;
	char* str = new char[50];
	for (short i = 0; i < 50; i++)
	{
		cin.get(ch);//получаем ввод посимвольно
		if (ch == ';')//заканчиваем ввод при нажатии ; или enter
			break;
		else str[i] = ch;
	}
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	return str;
}


//интерфейсный класс валидатора
void Validator::Check(char * str)
{

}

void ValidatorInt::Check(char * str)
{
	int val = 0;

	int res = sscanf(str, "%d", &val);
	if (res == EOF)
		cout << "*входная строка пуста\n";
	else if (res == 0)
		cout << "*неверный формат\n";
	else
	{
		if (val > 100)
			cout << "*значение больше допустимого\n";
		else if (val < 1)
			cout << "*значение меньше допустимого\n";

		else cout << "*значение установлено: " << val << "\n";
	}
}

void ValidatorDouble::Check(char * str)
{
	double val = 0;

	int res = sscanf(str, "%lf", &val);
	if (res == EOF)
		cout << "*входная строка пуста\n";
	else if (res == 0)
		cout << "*неверный формат\n";
	else
	{
		if (val > 99.99)
			cout << "*значение больше допустимого\n";
		else if (val < -99.99)
			cout << "*значение меньше допустимого\n";

		else cout << "*значение установлено: " << val << "\n";
	}
}

void ValidatorString::Check(char * str)
{
	cout << "*значение установлено: ";
	for (size_t i = 0; str[i] != '\0' && str[i] != -51; i++)
	{
		cout << str[i];
	}
	cout << "\n";
}
