#pragma once
#ifndef DRAWER_H

#define DRAWER_H

#include "raylib.h"
#include "Control.h"
#include "Snake.h"
#include <vector>
#include <set>
#include <algorithm>
#include "Click.h"
class Drawer {
public: 
	Drawer(int height, int width,int padding, int cellSize);
	// updates are gonna be in here
	void Update();

	// every thing will be drawn in here
	void Draw();

	// click and events are gonna be handeled here
	void ControlCaller();
	void DrawFood();
	// generate spots 
	
	void generate_food_pos();
	// game status
	void found_food(int pre_pos[], int pre_dir);
	void body_collision();
	// game status
	bool getOnPlaing() const;
	bool getGameOver() const;
	// Draw Settings
	void DrawSetting(int offset, int height, int width);
	// called by the draw function
	void DrawBoard();

private:
	void DrawSnake(Snake* snake);
	// start every thing as new


	void StartNew();
	// board infos
	const int height;
	const int width;
	const int padding;
	const int cellSize;
	// game padding and mergins
	int text_pad = 10;
	// Game status

	bool onPlaing = false;
	bool gameOver = false;
	



	// The snake

	std::vector<Snake*> snake;
	// time counter
	float timer;
	// float -> for food placememt

	int food[2];
	std::set <std::pair<int, int>> all_spot;
	// the control page
	Control* control;

	// click handler class
	Click* click;
	// play button text, and game info
	std::string play = "Play";
	int score = 0;
};

#endif // !DRAWER_H