#include "Drawer.h"
#include <iostream>
#include <assert.h>
#include <sstream>
Drawer::Drawer(int height, int width, int padding, int cellSize) :
	height(height), width(width), padding(padding), cellSize(cellSize)
{
	// the click
	click = new Click();
	// create the controll object and other setups
	control = new Control(&snake);
	// keep the track click intervals
	control->setClicked(true);
	timer = 0;
	
	// create all the free spaces as set for creating a food at a random place
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 20; j++) {
			all_spot.insert(std::make_pair(j, i));
		}
	}
	StartNew();

	generate_food_pos();
}

void Drawer::Update()
{
	// moving the snake

	
	/// this GetTime generate the time your app is running for but we use that as an advantage to 
	// to make a timer
	if (gameOver) return;
	if (onPlaing) {
		if (timer < GetTime()) {
			control->setClicked(true);
			timer = GetTime() + 0.2f;
			int pre_dir = snake[0]->getDir();
			int pre_pos[] = { 0,0 };
			for (int i = 0; i < snake.size(); i++) {
				int cur_dir = snake[i]->getDir();
				// we are taking the direction from the previous cell and assigning to te current 
				// in that way we can have the L shaped snake other wise it will be line moving
				pre_pos[0] = snake[i]->getX();
				pre_pos[1] = snake[i]->getY();
				snake[i]->move(snake[i]->getDir());
				snake[i]->setDir(pre_dir);
				pre_dir = cur_dir;
			}

			found_food(pre_pos, pre_dir);
			body_collision();
		}
	}
	
	
} 

void Drawer::Draw()

{


	//drawing the snake

	for (int i = 0; i < snake.size(); i++) {
		DrawSnake(snake[i]);
	}

	// Draw Food 
	DrawFood();

}

void Drawer::ControlCaller()
{
	// Handling the pressed key events arrange the change in the snake
	// we only change the first cell dir so that the other follow

	control->listenClick();
}

void Drawer::DrawFood()
{
	
	assert(food[0] >= 0 and food[0]* cellSize + padding <= width);
	assert(food[1] >= 0 and food[1]*cellSize+padding <= height);
	DrawRectangle(food[0] * cellSize + padding, food[1] * cellSize + padding, cellSize, cellSize, BLUE);

}

void Drawer::generate_food_pos()
{
	/*
	// Here we Draw food by generating some number this has to improved
	// we cannot do that because at the end we may infinite loop if we try to generate random
	// number because the generated number may have snake bosy overit
	// let say if every place is covered by body of the snake except one cell and we generate numbers until they are not 
	// where there is no snake body 
	// 
	// in that ca se the possiblity will 1/ 12 * 20 because we have that musch grid
	// 
	*/
	// so we use set to generate all spot the the snake position and then we can get the XOR of that
	std::set <std::pair<int, int>> snake_spot;
	for (int i = 0; i < snake.size(); i++) {
		snake_spot.insert(std::make_pair(snake[i]->getX(), snake[i]->getY()));
	}

	//this is to use the set to find free space
	
	std::set<std::pair<int, int>> result;

	for (const auto& element : all_spot) {
		if (snake_spot.find(element) == snake_spot.end()) {
			result.insert(element);
		}
	}

	
	
	//If There is free space availabe it will put the food over there randomly if not pauses
	if (result.size() == 0) {
		onPlaing = false;
		gameOver = true;
		play = "Done";
	}
	else {
		int index = GetRandomValue(0, result.size() - 1);
		auto pos = result.begin();
		std::advance(pos, index);
		std::pair<int, int> pairs = *pos;

		food[0] = pairs.first;
		food[1] = pairs.second;
	}


	

} 

void Drawer::found_food(int pre_pos[], int pre_dir)
{

	if (snake[0]->getX() == food[0] and snake[0]->getY() == food[1]) {
		snake.push_back(new Snake(pre_pos[0], pre_pos[1], cellSize, padding));
		snake[snake.size() - 1]->setDir(pre_dir);
		score += 1;
		generate_food_pos();

	}
}

void Drawer::body_collision()
{
	for (int i = 1; i < snake.size(); i++) {
		if (snake[0]->getX() == snake[i]->getX() && snake[0]->getY() == snake[i]->getY()) {
			gameOver = true;
			snake[0]->setColor(RED);
			snake[i]->setColor(RED);
			play = "Over";
		}
	}



}

bool Drawer::getOnPlaing() const
{
	return onPlaing;
}

bool Drawer::getGameOver() const
{
	return gameOver;
}

// here we will draw the setting 
void Drawer::DrawSetting(int offset, int height, int width)
{

	DrawText("Snake Game", width/ 2 + offset - MeasureText("Snake Game", 30)/2, height / 6, 30, RED);
	DrawRectangleLinesEx({ static_cast<float>(offset + width / 4), static_cast<float>(height / 3), static_cast<float>(width/2), 50}, 3, BLUE);
	DrawText(play.c_str(), width / 2 + offset - MeasureText(play.c_str(), 30) / 2, height / 3 + text_pad, 30, BLUE);


	
	std::stringstream convertor;

	std::string myString = "0";


	convertor << score;
	convertor >> myString;
	myString = "Score : " + myString;
	DrawText(myString.c_str(), width / 2 + offset - MeasureText(myString.c_str(), 30) / 2, height / 2 + text_pad, 30, BLUE);




	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		if (click->clicked(offset + width / 4, height / 3, offset + width / 4 + width / 2, height / 3 + 50))
		{
			
			if (!gameOver) {
				if (play == "Play") play = "Pause";
				else play = "Play";
				onPlaing = !onPlaing;
			}
			else {
				play = "Pause";
				score = 0;
				StartNew();
				gameOver = false;
				onPlaing = true;
			}
			
		}
	}
	
	
}






void Drawer::DrawBoard()
{
	Rectangle boundary = Rectangle{ static_cast<float>(padding / 2), static_cast<float>(padding / 2), static_cast<float>(width), static_cast<float>(height) };
	DrawRectangleLinesEx(boundary, static_cast<float>(padding / 2), GRAY);
}

void Drawer::DrawSnake(Snake* ss)
{
	
	// Draw the snake as rounded ball

	Rectangle cell = { static_cast<float>(ss->getDrawingX()), static_cast<float>(ss->getDrawingY()), static_cast<float>(cellSize), static_cast<float>(cellSize) };
	DrawRectangleRounded(cell,100, 100, ss->getColor());
}

void Drawer::StartNew()
{
	while (snake.size() > 0) snake.pop_back();
	// creating the first 3 cells of the snake
	for (int i = 0; i < 3; i++) {
		int value = 0;
		if (i != 0) {
			value = snake[0]->getX() + 1;
		}

		snake.insert(snake.begin(), new Snake(value, 12 / 2, cellSize, padding));
	}
	snake[0]->setColor(GREEN);

	
}
