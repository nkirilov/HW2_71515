#include<iostream>
#include<fstream>
#include<math.h>
#include<iomanip>
#include"Cell.h"
#include"Solver.h"
#include"Stack.h"
#include"Queue.h"
#include"List.h"

int main()
{
	int x, y;
	std::cout << "Enter Dimensions: ";
	std::cin >> x >> y;
	std::cout << std::endl;
	Solver solve(x, y);
	solve.pathFinder();
	system("pause");
	return 0;
}