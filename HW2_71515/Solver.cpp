#include<iostream>
#include"Cell.h"
#include"Solver.h"
#include"Stack.h"
#include"Queue.h"
#include"List.h"


Solver::Solver( int x, int y)
{

	xBorder = x;
	yBorder = y;
	pCurrent = NULL;
	
	char** tempMap = new char*[x];
	for (size_t i = 0; i < x; i++)
	{
		tempMap[i] = new char[y+1];
	}

	std::cout << "Enter map: " << std::endl;
	char* buffer = new char[y+1];
	for (size_t i = 0; i < x; i++)
	{
		std::cin >> buffer;
		strcpy(tempMap[i], buffer);
	}

	int xS, yS;
	std::cout << "Enter starting point: ";
	std::cin >> xS >> yS;
	start.setX(xS);
	start.setY(yS);

	Map = new Cell*[x];
	for (size_t i = 0; i < x; i++)
	{
		Map[i] = new Cell[y];
	}
	for (size_t i = 0; i < x; i++)
	{
		for (size_t j = 0; j < y; j++)
		{
			Map[i][j].setX(i);
			Map[i][j].setY(j);
			Map[i][j].setSymbol(tempMap[i][j]);
		}
	}

	delete[]buffer;
	for (size_t i = 0; i < x; i++)
	{
		delete tempMap[i];
	}
	delete tempMap;
}

Solver::~Solver()
{
	for (size_t i = 0; i < xBorder; i++)
	{
		delete[]Map[i];
	}
	delete[]Map;
}

void Solver::check(Cell* pCell,bool addEnd)
{
	if (pCell!=NULL &&
		pCell->getX()>= 0 && pCell->getX() <xBorder &&
		pCell->getY() >= 0 && pCell->getY() < yBorder &&
		pCell->getSymbol() != '#' && !pCell->getVisited())
	{
		CellQ.push(pCell);
		if (addEnd)
		{
			endPoints.push_back(pCell);
		}
		
		pCell->markVisited();
		pCell->setParent(pCurrent);
		
	}
}




bool Solver::isTarget()
{
	return ((pCurrent->getX() == end->getX() && pCurrent->getY() == end->getY()));
}

Cell* Solver::getCell(int x, int y)
{
	if (x >= 0 && x < xBorder &&
		y >= 0 && y < yBorder)
	{
		return &Map[x][y];
	}
	else
	{
		return NULL;
	}
}


void Solver::pathFinder()
{
	///
	///---Find all available points---
	///
	Cell* pstart = &start;
	CellQ.push(pstart);
	bool existNoPath = true;
	
	while (!CellQ.empty())
	{
		pCurrent = CellQ.front();
		Map[pCurrent->getX()][pCurrent->getY()].markVisited();
		CellQ.pop();


		check(getCell(pCurrent->getX(), pCurrent->getY() - 1),true);
		check(getCell(pCurrent->getX(), pCurrent->getY() + 1), true);
		check(getCell(pCurrent->getX() - 1, pCurrent->getY()), true);
		check(getCell(pCurrent->getX() + 1, pCurrent->getY()), true);

	}
	///
	///---Print all available points---
	///
	std::cout << "All available points: ";
	for (size_t i = 0; i < endPoints.size(); i++)
	{
		endPoints[i]->print();
	}

	///
	///---Find paths to all available points---
	///
	for (size_t p = 0; p < endPoints.size(); p++)
	{
		for (size_t i = 0; i < xBorder; i++)
		{
			for (size_t j = 0; j < yBorder; j++)
			{
				Map[i][j].setVisited(false);
			}
		}
		std::cout << std::endl;
		std::cout << "Point: ";
		end = endPoints[p];
		end->print();
		std::cout << std::endl;
		pstart = &start;
		CellQ.push(pstart);
		bool existNoPath = true;

		while (!CellQ.empty())
		{
			pCurrent = CellQ.front();
			Map[pCurrent->getX()][pCurrent->getY()].markVisited();
			CellQ.pop();

			if (isTarget())
			{
				existNoPath = false;
				Stack<Cell*> path;
				while (pCurrent != pstart)
				{
					
					path.push(pCurrent);
					
					pCurrent = pCurrent->getParent();
				}


				std::cout << "---->";
				start.print();
				while (!path.isEmpty())
				{
					path.peek()->print();
					path.pop();
				}
				std::cout << std::endl;
				Map[end->getX()][end->getY()].setVisited(false);



			}
			else
			{

				check(getCell(pCurrent->getX(), pCurrent->getY() - 1),false);
				check(getCell(pCurrent->getX(), pCurrent->getY() + 1), false);
				check(getCell(pCurrent->getX() - 1, pCurrent->getY()), false);
				check(getCell(pCurrent->getX() + 1, pCurrent->getY()), false);




			}
		}
	}
}
