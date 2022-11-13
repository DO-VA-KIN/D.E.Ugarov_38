#pragma once
#include<vector>

using std::vector;
namespace MyNamespace
{
	class Resheto
	{
	private:

	public:
		///<summary>
		///<param name="n">Принимает конечное число для поиска,</param>
		///<returns>Возвращает класс "Vector", наполненный переменными типа "int",</returns>
		///<remarks>Реализация алгоритма "Решето Эратосфена"</remarks>
		///</summary>
		vector<int> Search(int n);

		Resheto();//конструктор и деструктор класса для данной задачи не нужны
		~Resheto();
	};
};

