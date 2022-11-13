#include "pch.h"
#include "Array2Class.h"


int Array2Class::GetRandomInt(int t)
{
	srand(time(NULL) + t);
	//int num = min + rand() % (max - min + 1);
	int randNum = rand() % (101);

	return randNum;
}


Array2Class::Array2Class()
{
}

Array2Class::~Array2Class()
{
}

int Array2Class::GetArraySize()
{
	return N;
}

int ** Array2Class::GetArray()
{
	return ArrayIM;
}



void Array2Class::Initialize(int n)
{
	N = n;

	ArrayIM = new int* [N];
	for (int i = 0; i < N; i++)
		ArrayIM[i] = new int[N];

	return;
}


void Array2Class::Clear()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			ArrayIM[i][j] = 0;
		}
	}	

	return;
}


void Array2Class::Diag1()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == j)
			{
				ArrayIM[i][j] = -1;
				break;
			}
			else
			{
				int value = GetRandomInt(i+j);
				ArrayIM[i][j] = value;
				ArrayIM[j][i] = value;
			}
		}
	}

	return;
}


void Array2Class::Diag2()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == N - j - 1)
			{
				ArrayIM[i][j] = -1;
				break;
			}
			else
			{
				int value = GetRandomInt(0);
				ArrayIM[i][N-j-1] = value;
				ArrayIM[j][N-i-1] = value;
			}
		}
	}

	return;
}


void Array2Class::Rectangle()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == 0)
			{
				ArrayIM[i][j] = 1;
				continue;
			}

			if (j < i)
			{
				ArrayIM[i][j] = 0;
				continue;
			}

			if (i == j)
			{
				ArrayIM[i][j] = 1;
			}
			else
			{
				ArrayIM[i][j] = ArrayIM[i-1][j-1];
				ArrayIM[j][i] = ArrayIM[i - 1][j];
			}
		}
	}

	return;
}
