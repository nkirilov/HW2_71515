#pragma once
#include<iostream>
#include"Cell.h"
#include"List.h"
#include"Stack.h"
#include"Queue.h"


class Solver
{
public:
	
	Solver( int x, int y);
	~Solver();

	void pathFinder();

private:
	
	Cell** Map;
	Cell start;
	Cell* end;
	Queue<Cell*> CellQ;
	int xBorder, yBorder;
	List<Cell*> endPoints;
	
	

	Cell* pCurrent;

	void check(Cell* pCell,bool addEnd);
	

	bool isTarget();
	Cell* getCell(int x, int y);


};



