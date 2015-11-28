//Николай Здравков Кирилов 
//ФН 71515
//Visual Studio 2015 Enterprise
//Windows 8.1 Pro 64bit
#include<iostream>
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