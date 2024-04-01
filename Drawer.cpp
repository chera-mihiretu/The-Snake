#include "Drawer.h"
#include <iostream>
Drawer::Drawer(int height, int width, int padding, int cellSize):
	height(height), width(width), padding(padding), cellSize(cellSize)
{
	for (int i = 0; i < 3; i++) {
		int value = padding;
		if (i != 0) {
			value = snake[i - 1]->getX() + cellSize;
		}
		
		snake.push_back(new Snake(value, cellSize * 12 / 2, cellSize));
	}
	timer = 0;
}

void Drawer::Update()
{
	// moving the snake

	

	if (timer < GetTime()) {
		timer = timer + 0.5f;
		int pre_dir = snake[0]->getDir();
		
		for (int i = 0; i < snake.size(); i++) {
			int cur_dir = snake[i]->getDir();
			// we are taking the direction from the previous cell and assigning to te current 
			// in that way we can have the L shaped snake other wise it will be line moving
			
			snake[i]->move(pre_dir);
			pre_dir = cur_dir;
		}	 
		std::cout << "hellow" << std::endl;


	}
	
}

void Drawer::Draw()

{
	// drawing the boarders
	Rectangle boundary = Rectangle{ static_cast<float>(padding /2), static_cast<float>(padding/2), static_cast<float>(width), static_cast<float>(height) };
	DrawRectangleLinesEx(boundary, static_cast<float>(padding/2) , GRAY);

	//drawing the snake

	for (int i = 0; i < snake.size(); i++) {
		DrawSnake(snake[i]);
	}

}

void Drawer::Control()
{
	if (IsKeyPressed(KEY_DOWN)) {
		snake[0]->setDir(1);
	}
}

void Drawer::DrawBoard()
{
}

void Drawer::DrawSnake(Snake* ss)
{
	// Draw the snake as rounded ball
	Rectangle cell = { static_cast<float>(ss->getX()), static_cast<float>(ss->getY()), static_cast<float>(cellSize), static_cast<float>(cellSize) };
	DrawRectangleRounded(cell,100, 100, BROWN);
}
