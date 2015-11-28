#include"Cell.h"

Cell::Cell()
{
	this->symbol = '.';
	this->x = 0;
	this->y = 0;
	this->visited = false;
	this->parent = NULL;
}

Cell::~Cell()
{

}

Cell::Cell(int oX, int oY, char oS)
{
	this->symbol = oS;
	this->x = oX;
	this->y = oY;
	this->visited = false;
	this->parent = NULL;
	
}

Cell& Cell::operator=(Cell& o)
{
	if (this!= &o)
	{
		this->symbol = o.symbol;
		this->x = o.x;
		this->y = o.y;
		this->visited = o.visited;
		this->parent = o.parent;
	}
	return *this;
}

///
///-------Seters--------
///
void Cell::setX(int nx)
{
	this->x = nx;
}

void Cell::setY(int ny)
{
	this->y = ny;
}

void Cell::setVisited(bool nv)
{
	this->visited = nv;
}

void Cell::setSymbol(char ns)
{
	this->symbol = ns;
}

void Cell::setParent(Cell* o)
{
	this->parent = o;
}





///
///-------Geters-------
///

int Cell::getX()
{
	return x;
}

int Cell::getY()
{
	return y;
}

bool Cell::getVisited()
{
	return visited;
}

char Cell::getSymbol()
{
	return symbol;
}

Cell* Cell::getParent()
{
	return parent;
}


///
///-------MarkVisited-------
///

void Cell::markVisited()
{
	setVisited(true);
}

///
///-------Print-------
///

void Cell::print() const
{
	std::cout << " (" << x << "," << y << ") ";
}

