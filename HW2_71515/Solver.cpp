#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <fstream>
#include <math.h>
#include <iomanip>
#include "Cell.h"
#include "Solver.h"


Solver::Solver(std::string file, Cell Start, Cell End)
{

	this->start = Start;
	this->end = End;
	pCurrent = NULL;
	std::ifstream filepath;
	filepath.open(file);
	std::vector< std::vector <char> > tempMap;
	std::string value;
	size_t rows = 0;
	while (filepath.good())
	{
		std::getline(filepath, value, '\n');
		tempMap.resize(rows + 1);
		for (size_t i = 0; i < value.length(); i++)
		{
			if (value[i] != ',' && value[i] != ';')
			{
				tempMap[rows].push_back(value[i]);
			}
		}
		rows++;
	}
	Map.resize(rows);
	for (size_t i = 0; i < tempMap.size(); i++)
	{
		for (size_t k = 0; k < tempMap[i].size(); k++)
		{
			Cell temp(i, k, tempMap[i][k]);
			temp.setX(i);
			temp.setY(k);
			Map[i].push_back(temp);
		}
	}
	filepath.close();
}

Solver::~Solver()
{

}

void Solver::check(Cell* pCell)
{
	if (pCell!=NULL &&
		pCell->getX()>= 0 && pCell->getX() < Map.size() &&
		pCell->getY() >= 0 && pCell->getY() < Map[0].size() &&
		pCell->getSymbol() != 'N' && !pCell->getVisited())
	{
		CellQ.push(pCell);
		pCell->markVisited();
		Relashions temp;
		temp.child = pCell;
		temp.parent = pCurrent;
		relatives.push_back(temp);
	}
}

//void Solver::checkDiagonal(Cell* pCell)
//{
//	if (pCell->getSymbol() != 'N' && !pCell->getVisited())
//	{
//		
//	}
//}

//double Solver::getDistance(Cell* pCell)
//{
//	double dx = abs(pCell->getX() - end.getX());
//	double dy = abs(pCell->getY() - end.getY());
//	return ((dx + dy) + (1.5 - 2)*(std::min(dx, dy)));
//}


bool Solver::isTarget()
{
	return ((pCurrent->getX() == end.getX() && pCurrent->getY() == end.getY()));
}

Cell* Solver::getCell(int x, int y)
{
	if (x >= 0 && x < Map.size() &&
		y >= 0 && y < Map[0].size())
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
	Cell* pstart = &start;
	CellQ.push(pstart);
	bool existNoPath = true;

	while (!CellQ.empty())
	{
		pCurrent = CellQ.front();
		pCurrent->markVisited();
		Map[pCurrent->getX()][pCurrent->getY()].markVisited();
		CellQ.pop();

		if (isTarget())
		{
			existNoPath = false;
			std::stack<Cell*> path;
			while (pCurrent != pstart)
			{
				Map[pCurrent->getX()][pCurrent->getY()].setSymbol('*');
				path.push(pCurrent);
				for (size_t i = 0; i < relatives.size(); i++)
				{
					if (relatives[i].child == pCurrent)
					{
						pCurrent = relatives[i].parent;
						break;
					}
				}
			}




			Map[start.getX()][start.getY()].setSymbol('M');
			Map[end.getX()][end.getY()].setSymbol('F');
			
			std::cout << "   |";
			for (size_t i = 0; i < Map[0].size(); i++)
			{
				std::cout << char(i + 'A')<<"|";
			}
			std::cout << std::endl;
			std::cout << "---+";
			for (size_t i = 0; i < Map[0].size(); i++)
			{
				std::cout << "-" << "+" ;
			}
			std::cout << std::endl;
			for (size_t i = 0; i < Map.size(); i++)
			{
				std::cout<<std::setw(3)<< i + 1 << "|";
				for (size_t j = 0; j < Map[0].size(); j++)
				{
					std::cout << Map[i][j].getSymbol() << "|";
				}
				std::cout << std::endl;
				std::cout << "---+";
				for (size_t j = 0; j < Map[0].size(); j++)
				{
					std::cout << "-+";
				}
				std::cout << std::endl;
			}

			std::cout << std::endl;

			std::cout << "Path: ";
			std::cout << " (" << char(start.getY() + 'A') << ", " << start.getX() + 1 << ") ";
			while (!path.empty())
			{
				std::cout << " (" << char(path.top()->getY() + 'A') << ", " << path.top()->getX() + 1 << ") ";
				path.pop();
			}
			std::cout << std::endl;
			
			break;

		}
		else
		{
			
			check(getCell(pCurrent->getX(), pCurrent->getY() - 1));
			check(getCell(pCurrent->getX(), pCurrent->getY() + 1));
			check(getCell(pCurrent->getX() - 1, pCurrent->getY()));
			check(getCell(pCurrent->getX() + 1, pCurrent->getY()));
			check(getCell(pCurrent->getX() - 1, pCurrent->getY() - 1));
			check(getCell(pCurrent->getX() + 1, pCurrent->getY() + 1));
			check(getCell(pCurrent->getX() - 1, pCurrent->getY() + 1));
			check(getCell(pCurrent->getX() + 1, pCurrent->getY() - 1));
			

			
		}
	}
	if (existNoPath)
	{
		std::cout << "There is no available path!"<<std::endl;
	}
}
