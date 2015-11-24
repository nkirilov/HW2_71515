#pragma once
#include <iostream>


class Cell
{
public:
	Cell();
	Cell(int oX,int oY,char oS);
	~Cell();
	Cell& operator=(Cell& o);



	void setX(int nx);
	void setY(int ny);
	void setVisited(bool nv);
	void setSymbol(char ns);
	//void setParent(Cell* o);
	//void setPrice(double np);



	int getX();
	int getY();
	bool getVisited();
	char getSymbol();
	//double getPrice();
	//Cell* getParent();



	void markVisited();



	//bool operator<(Cell& o);
	//bool operator>(Cell& o);
	//bool operator<=(Cell& o);
	//bool operator>=(Cell& o);
	//bool operator==(Cell& o);
	//bool operator!=(Cell& o);


private:
	char symbol;
	int x;
	int y;
	bool visited;
	//Cell* parent;
	//double price;

};

