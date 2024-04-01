#include "Snake.h"

Snake::Snake(int x, int y):
	pos_x(x), pos_y(y), dir(0)
{
}



int Snake::getX() const
{
	return pos_x;
}

int Snake::getY() const
{
	return pos_y;
}
