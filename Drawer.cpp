#include "Drawer.h"

Drawer::Drawer(int height, int width, int padding, int cellSize):
	height(height), width(width), padding(padding), cellSize(cellSize)
{
	for (int i = 0; i < 3; i++) {
		int value = padding;
		if (i != 0) {
			value = snake[i - 1]->getX() + cellSize;
		}
		
		snake.push_back(new Snake(value, cellSize * 12 / 2));
	}
}

void Drawer::Update()
{
	
}

void Drawer::Draw()

{
	// drawing the boarders
	Rectangle boundary = Rectangle{ (float) padding /2, (float)padding/2, (float)width, (float)height };
	DrawRectangleLinesEx(boundary, padding/2 , GRAY);

	//drawing the snake

	for (int i = 0; i < snake.size(); i++) {
		DrawSnake(snake[i]);
	}

}

void Drawer::Control()
{
}

void Drawer::DrawBoard()
{
}

void Drawer::DrawSnake(Snake* ss)
{
	DrawRectangle(ss->getX(), ss->getY(), cellSize, cellSize, BROWN);
}
