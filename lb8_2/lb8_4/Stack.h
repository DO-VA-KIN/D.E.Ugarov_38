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
		T data;//поле с данными
		Node * next;//указатель на следующий
	};
	Node * root;//указатель на следующий

public:
	Stack() : root(nullptr) {}//по умолчанию стек пуст(nullptr - указатель на пустоту)
	~Stack() { while (!IsEmpty()) Pop(); }

	//T* begin() { return &root->data; }
	//T* end()
	//{
	//	Node* node = root;
	//	while (node->next != nullptr)
	//		node = node->next;
	//	return &node->next->data;
	//}


	//проверка на пустоту
	bool IsEmpty() const//const - не меняет объект, метод запрос
	{ return root == nullptr; }

	//добавить элемент
	void Push(const T& x)//класс передается по константной ссылке
	{
		Node* newNode = new Node;
		newNode->data = x;
		newNode->next = root;
		root = newNode;
	}

	///по классике stack top возвращает либо ссылку на верхний элемент(тогда его можно изменить)
	///или возвращает константную ссылку (тогда элемент изменить нельзя, но скорость перадачи выше)
	//текущий элемент
	const T& Top() const
	{
		if (IsEmpty())
			throw length_error("Stack is empty"); //искл. (унаследованно от exception)
		else return root->data;
	}

	///в с++ stack pop метод является void методом, просто удаляющим элемент
	///(т.к. вызов 2-ух методов последовательно - получить элемент и удалить быстрее,
	///чем двухкратное копирование данных (как внизу - извлечение))
	//извлечь элемент
	T Pop()
	{
		if (IsEmpty())
			throw length_error("Stack is empty"); //искл. (унаследованно от exception)
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

