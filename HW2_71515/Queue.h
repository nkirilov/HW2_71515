#pragma once
#include<iostream>

template<typename T>
struct qElem
{
	T data;
	qElem<T>* next;
};

template<typename T>
class Queue
{
public:
	Queue() : first(NULL), last(NULL), Size(0)
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
	qElem<T> *first,*last;
	int Size;

};


template<typename T>
Queue<T>::~Queue()
{
	while(Size>0)
	{
		pop();
	}
}

template<typename T>
bool Queue<T>::empty()
{
	return Size == 0;
}

template<typename T>
int Queue<T>::size()
{
	return Size;
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
void Queue<T>::push(const T& data)
{
	qElem<T>* pn = new qElem<T>;
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
	Size++;
}

template<typename T>
void Queue<T>::pop()
{
	if (Size == 0)
	{
		throw"Empty Queue!";
	}
	qElem<T>* temp = first;
	if (temp==last)
	{
		last = NULL;
		first = NULL;
	}
	else
	{
		first = temp->next;
	}
	Size--;
	delete temp;
	
}
