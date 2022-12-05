#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class Stack
{
private:
	//T nd = 3;
	struct Node
	{
		T data;//���� � �������
		Node * next;//��������� �� ���������
	};
	Node * root;//��������� �� ���������

public:
	Stack() : root(nullptr) {}//�� ��������� ���� ����(nullptr - ��������� �� �������)
	~Stack() { while (!IsEmpty()) Pop(); }

	//T* begin() { return &root->data; }
	//T* end()
	//{
	//	Node* node = root;
	//	while (node->next != nullptr)
	//		node = node->next;
	//	return &node->next->data;
	//}


	//�������� �� �������
	bool IsEmpty() const//const - �� ������ ������, ����� ������
	{ return root == nullptr; }

	//�������� �������
	void Push(const T& x)//����� ���������� �� ����������� ������
	{
		Node* newNode = new Node;
		newNode->data = x;
		newNode->next = root;
		root = newNode;
	}

	///�� �������� stack top ���������� ���� ������ �� ������� �������(����� ��� ����� ��������)
	///��� ���������� ����������� ������ (����� ������� �������� ������, �� �������� �������� ����)
	//������� �������
	const T& Top() const
	{
		if (IsEmpty())
			throw length_error("Stack is empty"); //����. (������������� �� exception)
		else return root->data;
	}

	///� �++ stack pop ����� �������� void �������, ������ ��������� �������
	///(�.�. ����� 2-�� ������� ��������������� - �������� ������� � ������� �������,
	///��� ����������� ����������� ������ (��� ����� - ����������))
	//������� �������
	T Pop()
	{
		if (IsEmpty())
			throw length_error("Stack is empty"); //����. (������������� �� exception)
		else 
		{
			Node* delNode = root;
			T x = delNode->data;
			root = delNode->next;
			delete delNode;
			return x;
		}
	}

	int Size()
	{
		if (IsEmpty())
			return 0;
		else
		{
			int count = 1;
			for (Node* node = root; node->next != nullptr; count++)
			{
				node = node->next;
			}
			return count;
		}
	}
};

