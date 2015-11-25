#pragma once 
#include<iostream>

template<typename T>
class List
{
public:
	List() :first(NULL), last(NULL),Size(0){}
	//List(const List<T>& other);
	//List<T>& operator=(const List<T>& other);
	~List()
	{
		while (Size>0)
		{
			pop_front();
		}
	}

	struct Elem
	{
		T data;
		Elem* next, *prev;
	};

	class ListIter
	{
	public:
		~ListIter()
		{}
		ListIter& operator++()
		{
			if (current != NULL)
			{
				current = current->next;
				
			}
			return *this;
		}
		ListIter operator++(int)
		{
			ListIter o(*this);
			++(*this);
			return o;
		}
		T& operator*()
		{
			if (!current)
			{
				throw "Null pointer";
			}
			return current->data;
		}
		bool operator==(ListIter right)
		{
			return owner == right.owner && current == right.current;
		}
		bool operator!=(ListIter right)
		{
			return !(*this == right);
		}
		operator bool() const
		{
			return current != NULL;
		}
		ListIter& operator--()
		{
			if (current != NULL)
			{
				current = current->prev;

			}
			return *this;
		}
		ListIter operator--(int)
		{
			ListIter o(*this);
			--(*this);
			return o;
		}
		ListIter(const ListIter& o):current(o.current),owner(o.owner) {}
		ListIter( Elem* pos, List<T>* l) :current(pos), owner(l){}
	private:
		friend class List <T>;
		Elem* current;
		List<T>* owner;

	protected:
		
		
		
	};

	T& operator[](Size_t i)
	{
		Elem* pCurr = first;
		if (first)
		{
			if (i+1<=Size)
			{
				for (Size_t k = 0; k < i; k++)
				{
					pCurr = pCurr->next;
				}
			}
			else
			{
				throw "Out of bound!"
			}
			
		}
		return pCurr;
	}
	int size()
	{
		return Size;
	}
	ListIter begin()
	{
		return ListIter(first, this);
	}
	ListIter end()
	{
		return ListIter(last, this);
	}
	void push_back(T data)
	{
		Elem* pn = new Elem;
		pn->data = data;
		pn->next = NULL;
		pn->prev = last;
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
	void pop_front()
	{
		if (Size == 0)
		{
			throw"Empty Queue!";
		}
		Elem* temp = first;
		if ((first->next))
		{
			first = first->next;
			first->prev = NULL;
		}
		delete temp;
		Size--;
	}
	void push_front(const T& data)
	{
		Elem* pn = new Elem;
		pn->data = data;
		pn->next = first;
		if (first)
		{
			first->prev = pn;
			first = pn;
			pn->prev = NULL;
		}
		else
		{
			first = pn;
			last = pn;
		}
		
		
		Size++;
	}
	void pop_back()
	{
		if (Size == 0)
		{
			throw"Empty Queue!";
		}
		Elem* Prev = last->prev;
		delete last;
		last = Prev;
		Size--;
	}

private:
	Elem *first, *last;
	//void deleteList();
	//void copyList(const List<T>& other);
	int Size;

};

