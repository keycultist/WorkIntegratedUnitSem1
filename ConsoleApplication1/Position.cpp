#include "Position.h"
#include <iostream>

Position::Position()
{
	x = 0;
	y = 0;
	//std::cout << "Pos created\n";
}

Position::Position(int x, int y)
{
}

Position::~Position()
{
	//std::cout << "Pos destroyed\n";
}

void Position::SetX(int x)
{
	this->x = x;
}

void Position::SetY(int y)
{
	this->y = y;
}

int Position::GetX(void) const
{
	return x;
}

int Position::GetY(void) const
{
	return y;
}
