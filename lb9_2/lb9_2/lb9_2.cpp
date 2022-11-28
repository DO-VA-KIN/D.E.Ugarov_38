#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
#include "DelClass.h"

using namespace std;


unsigned int num = 0;
unsigned int countDel = 0;
bool CompareFunc(DelVector<unsigned int> v)
{
	if (find(v.begin(), v.end(), num) != v.end())
	{
		countDel++;
		return true;
	}
	else return false;
};
void MeanFunc(vector<DelVector<unsigned int>> v)
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		int mean = accumulate(v[i].begin(), v[i].end(), 0) / v[i].size();
		cout << v[i].X << ": ";
		cout << mean << endl;
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int move = -1;

	while (true)
	{
		unsigned int xs[20];
		unsigned int arrSize = sizeof(xs) / sizeof(unsigned int);
		for (unsigned int i = 0; i < arrSize; i++)
		{
			srand(time(NULL) + 5 * i);
			//int num = min + rand() % (max - min + 1);
			xs[i] = 1 + rand() % 65535;//шанс появления посетителя
		}


		vector<DelVector<unsigned int>> vDel;
		vDel.reserve(arrSize);


		for (unsigned int i = 0; i < arrSize; i++)
		{
			DelVector<unsigned int> del(xs[i]);
			vDel.push_back(del);
		}

		for (unsigned int i = 0; i < arrSize; i++)
		{
			cout << vDel[i].X << ": ";
			cout << vDel[i] << endl;
		}

	DoMove:
		cout << "\nВыберете действие: "
			<< "\n1)посчитать делители"
			<< "\n2)показать среднее арифметическое"
			<< "\n3)новая итерация"
			<< "\n9)выход\n" << endl;
		cin >> move;

		if (move == 1)
		{
			cout << "Введите искомый делитель: ";
			cin >> num;

			countDel = 0;
			count_if(vDel.begin(), vDel.end(), CompareFunc);
			cout << "колиство делителей: " << countDel << endl;
		}
		else if (move == 2)
		{
			MeanFunc(vDel);
		}
		else if (move == 3)
		{
			continue;
		}
		else if (move == 9) break;
		goto DoMove;

	}
}

