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
		///<param name="n">��������� �������� ����� ��� ������,</param>
		///<returns>���������� ����� "Vector", ����������� ����������� ���� "int",</returns>
		///<remarks>���������� ��������� "������ ����������"</remarks>
		///</summary>
		vector<int> Search(int n);

		Resheto();//����������� � ���������� ������ ��� ������ ������ �� �����
		~Resheto();
	};
};

