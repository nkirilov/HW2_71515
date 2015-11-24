#pragma once
#include<iostream>

template<typename T>
struct Elem
{
	T data;
	Elem<T>* prev;
};

template<typename T>
class Queue
{
public:
	Queue() : front(NULL), rear(NULL), size(0)
	{
	}
	~Queue();
	bool empty();
	int size();
	T& front();
	T& back();
	void push(const T&);
	void pop();


private:
	Elem *first,*last;
	int size;

};


template<typename T>
Queue<T>::~Queue()
{
	while(size>0)
	{
		pop();
	}
}

template<typename T>
bool Queue<T>::empty()
{
	return size == 0;
}

template<typename T>
int Queue<T>::size()
{
	return size;
}

template<typename T>
T& Queue<T>::front()
{
	return first->data;
}

template<typename T>
T& Queue<T>::back()
{
	return last->data;
}

template<typename T>
void Queue<T>::push(const T&)
{
	Elem<T>* pn = new Elem;
	pn->data = data;
	pn->next = NULL;
	if (first != NULL)
	{
		last->next = pn;
		last = pn;
	}
	else
	{
		first = pn;
		last = pn;
	}
	size++;
}

template<typename T>
void Queue<T>::pop()
{
	if (size == 0)
	{
		throw"Empty Queue!";
	}
	Elem<T>* temp = first;
	if ((first->next))
	{
		first = first->next;
	}
	delete temp;
	size--;
}
