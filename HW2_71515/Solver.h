#pragma once
#include<iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <fstream>
#include"Cell.h"

struct Relashions
{
	Cell* parent;
	Cell* child;
};

class Solver
{
public:
	Solver(std::string file, Cell Start, Cell End);
	~Solver();

	void pathFinder();

private:
	std::vector< std::vector <Cell> > Map;
	Cell start;
	Cell end;
	std::queue<Cell*> CellQ;
	std::vector<Relashions> relatives;

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



