
#include "pch.h"
#include "Potok.h"

//������������ ����� �����������
char * Vvod::Read()
{
	return nullptr;
}


char* VvodInt::Read()
{
	cin.ignore();//������� ������� �������� ������
	//cin.getline(str, 5, ';');
	char ch = 0;
	char* str = new char[5];
	for (short i = 0; i < 5; i++)
	{
		cin.get(ch);//�������� ���� �����������
		if (ch == ' ' || ch == '\t')//���������� ������� � ���������
			continue;
		if (ch == ';' || ch == '\n')//����������� ���� ��� ������� ; ��� enter
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
	cin.ignore();//������� ������� �������� ������
	char ch = 0;
	char* str = new char[15];
	short count = 0;
	for (short i = 0; i < 15; i++)
	{
		cin.get(ch);//�������� ���� �����������
		if (ch == '.') ch = ',';//��������� ����������� ����� � ����� ����� � ����� ������� 
		if (ch == ',' || count > 0) count++;//������� ������ ����� �������

		if (ch == ' ' || ch == '\t')//���������� ������� � ���������
			continue;
		if (ch == ';' || ch == '\n')//����������� ���� ��� ������� ; ��� enter
			break;
		else str[i] = ch;

		if (count > 2) break;//����� 2� ������ ����� ������� ���� �����������
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
		cin.get(ch);//�������� ���� �����������
		if (ch == ';')//����������� ���� ��� ������� ; ��� enter
			break;
		else str[i] = ch;
	}
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	return str;
}


//������������ ����� ����������
void Validator::Check(char * str)
{

}

void ValidatorInt::Check(char * str)
{
	int val = 0;

	int res = sscanf(str, "%d", &val);
	if (res == EOF)
		cout << "*������� ������ �����\n";
	else if (res == 0)
		cout << "*�������� ������\n";
	else
	{
		if (val > 100)
			cout << "*�������� ������ �����������\n";
		else if (val < 1)
			cout << "*�������� ������ �����������\n";

		else cout << "*�������� �����������: " << val << "\n";
	}
}

void ValidatorDouble::Check(char * str)
{
	double val = 0;

	int res = sscanf(str, "%lf", &val);
	if (res == EOF)
		cout << "*������� ������ �����\n";
	else if (res == 0)
		cout << "*�������� ������\n";
	else
	{
		if (val > 99.99)
			cout << "*�������� ������ �����������\n";
		else if (val < -99.99)
			cout << "*�������� ������ �����������\n";

		else cout << "*�������� �����������: " << val << "\n";
	}
}

void ValidatorString::Check(char * str)
{
	cout << "*�������� �����������: ";
	for (size_t i = 0; str[i] != '\0' && str[i] != -51; i++)
	{
		cout << str[i];
	}
	cout << "\n";
}
