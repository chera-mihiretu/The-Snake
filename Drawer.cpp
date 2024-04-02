#include "Drawer.h"
#include <iostream>
#include <assert.h>

Drawer::Drawer(int height, int width, int padding, int cellSize) :
	height(height), width(width), padding(padding), cellSize(cellSize)
{
	for (int i = 0; i < 3; i++) {
		int value = padding;
		if (i != 0) {
			value = snake[0]->getX() + cellSize;
		}
		
		snake.insert(snake.begin(), new Snake(value, cellSize * 12 / 2, cellSize, padding));
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
			
			snake[i]->move(snake[i]->getDir());
			snake[i]->setDir(pre_dir);
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

	// Draw Food 
	DrawFood();

}

void Drawer::Control()
{
	// Handling the pressed key events arrange the change in the snake
	// we only change the first cell dir so that the other follow
	if (IsKeyPressed(KEY_DOWN)) {
		snake[0]->setDir(1);
	}
	if (IsKeyPressed(KEY_UP)) {
		snake[0]->setDir(3);
	}
	if (IsKeyPressed(KEY_LEFT)) {
		snake[0]->setDir(2);
	}
	if (IsKeyPressed(KEY_RIGHT)) {
		snake[0]->setDir(0);
	}
}

void Drawer::DrawFood()
{
	// Here we Draw food by generating some number 
	DrawRectangle(food[0] * cellSize + padding, food[1] * cellSize + padding, cellSize, cellSize, BLUE);
}

void Drawer::DrawBoard()
{
}

void Drawer::DrawSnake(Snake* ss)
{
	//assertion to make sure no drawing out side the window
	assert(ss->getX() >= 0 and ss->getX() <= width); // drawing outside window
	assert(ss->getY() >= 0 and ss->getY() <= height); // drawing outside window


	// Draw the snake as rounded ball

	Rectangle cell = { static_cast<float>(ss->getX()), static_cast<float>(ss->getY()), static_cast<float>(cellSize), static_cast<float>(cellSize) };
	DrawRectangleRounded(cell,100, 100, BROWN);
}
