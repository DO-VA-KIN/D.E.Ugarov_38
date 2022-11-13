#pragma once

#include <stdlib.h>//подключение библиотеки с генерацией рандомных чисел
#include <time.h>//подключение библиотеки для генерации рандомных чисел, отталкиваясь от времени


class Array2Class
{
private:
	int N;
	int ** ArrayIM;

	int GetRandomInt(int t);

public:
	Array2Class();
	~Array2Class();

	///<summary>
	///<remarks>возврат размера дввумерного массива "int"</remarks>
	///</summary>
	int GetArraySize();

	///<summary>
	///<remarks>возврат дввумерного массива</remarks>
	///</summary>
	int** GetArray();


	///<summary>
	///<param name="n">Принимает размер массива</param>
	///<remarks>Создание двумерного массива</remarks>
	///</summary>
	void Initialize(int n);


	///<summary>
	///<remarks>"Зануление" элементов массива</remarks>
	///</summary>
	void Clear();


	///<summary>
	///<remarks>Симетрия элементов массива по главной диагонали</remarks>
	///</summary>
	void Diag1();


	///<summary>
	///<remarks>Симетрия элементов массива по побочной диагонали</remarks>
	///</summary>
	void Diag2();


	///<summary>
	///<remarks>Создание треугольника Паскаля</remarks>
	///</summary>
	void Rectangle();
};

