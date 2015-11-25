#pragma once
#include<iostream>
#include <string>
#include <fstream>
#include"Cell.h"
#include"List.h"
#include"Stack.h"
#include"Queue.h"

struct Relashions
{
	Cell* parent;
	Cell* child;
};

class Solver
{
public:
	//TODO: change string
	Solver(std::string file, Cell Start, Cell End);
	~Solver();

	void pathFinder();

private:
	//TODO: change map
	std::vector< std::vector <Cell> > Map;
	Cell start;
	Cell end;
	Queue<Cell*> CellQ;
	List<Relashions> relatives;

	//std::priority_queue<Cell*> open;
	//std::vector<Cell*> closed;
	//std::vector<Cell*> children;
	Cell* pCurrent;

	void check(Cell* pCell);
	//void checkDiagonal(Cell* pCell);
	//double getDistance(Cell* pCell);

	bool isTarget();
	Cell* getCell(int x, int y);


};



