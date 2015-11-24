#pragma once
#include<iostream>

template<typename T>
struct Elem
{
	T data;
	Elem<T>* prev;
};


template<typename T>
class Stack
{
public:
	Stack() :top(NULL) {}
	~Stack();
	Stack(const Stack<T>& o);
	bool isEmpty()const
	{
		return top == NULL;
	}
	void push(const T& newElem)
	{
		Elem<T>* pn = new Elem<T>;
		pn->data = newElem;
		pn->prev = top;
		top = pn;
	}
	void pop()
	{
		if (isEmpty())
		{
			throw "The Stack is Empty!";
		}
		Elem<T>* previous = top->prev;
		delete top;
		top = previous;
	}
	T peek()
	{
		if (isEmpty())
		{
			throw "The Stack is Empty!";
		}
		return top->data;
	}
private:
	Elem<T>* top;
	void copyStack(const Stack<T>& o);
	

};

template<typename T>
Stack<T>::~Stack()
{
	while (top)
	{
		Elem<T>* prev = top->prev;
		delete top;
		top = prev;
	}
}

template<typename T>
void Stack<T>::copyStack(const Stack<T>& o)
{
	Elem<T>*cur = o.top;
	if (!cur)
	{
		top = NULL;
	}
	else
	{
		top = new Elem < T >;
		top->data = cur->data;
		top->prev = NULL;
		Elem<T>*next = top;
		while (cur)
		{
			Elem<T>* newEl = new Elem < T >;
			newEl->data = cur->data;
			newEl->prev = NULL;
			next->prev = newEl;
			next = newEl;
			cur = cur->prev;

		}
	}
}

template<typename T>
Stack<T>::Stack(const Stack<T>& o)
{
	copyStack(o);
}
