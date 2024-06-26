#include "Snake.h"

Snake::Snake(int x, int y, int cellSize, int padding):
	pos_x(x), pos_y(y), dir(0), cellSize(cellSize), padding(padding)
{
	result = { pos_x, pos_y };
}



int Snake::getX() const
{
	return pos_x;
}

int Snake::getY() const
{
	return pos_y;
}

void Snake::setX(int x)
{
	pos_x = x;
}

void Snake::setY(int y)
{
	pos_y = y;
}

int Snake::getDir() const
{
	return dir;
}

void Snake::setDir(int pos) {
	this->dir = pos;
}
int Snake::getDrawingX() const
{
	return pos_x * cellSize + padding;
}
int Snake::getDrawingY() const
{
	return pos_y * cellSize + padding;
}
int Snake::move(int dir)
{
	this->dir = dir;
	switch (this->dir) {
		// this when snake is moving left
		case 0:
			pos_x += 1;
			break;
		// when snake is moving down
		case 1:
			pos_y += 1;
			break;
		// when the snake is moving right
		case 2:
			pos_x -= 1;
			break;
		// when the snake is moving up
		case 3:
			pos_y -= 1;
			break;

	}
	return -1;
}



void Snake::setColor(Color c)
{
	this->color = c;
}

Color Snake::getColor() const
{
	return color;
}

std::array<int, 2> Snake::checkBefore(int dir)
{
	this->dir = dir;
	
	switch (this->dir) {
		// this when snake is moving left
	case 0:
		result[0] = this->pos_x + 1;
		break;
		// when snake is moving down
	case 1:
		result[1] = this->pos_y + 1;
		break;
		// when the snake is moving right
	case 2:
		result[0] =  this->pos_x - 1;
		break;
		// when the snake is moving up
	case 3:
		result[1] = this->pos_y - 1;
		break;

	}
	return result;
}


