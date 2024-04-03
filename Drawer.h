#pragma once
#include "raylib.h"
#include "Snake.h"
#include <vector>
#include <set>
#include <algorithm>
class Drawer {
public: 
	Drawer(int height, int width,int padding, int cellSize);
	// updates are gonna be in here
	void Update();

	// every thing will be drawn in here
	void Draw();

	// click and events are gonna be handeled here
	void Control();
	void DrawFood();
	// generate spots 
	
	void generate_food_pos();
	// game status
	void found_food(int pre_pos[], int pre_dir);
	void body_collision();
private:
	// called by the draw function
	void DrawBoard();
	void DrawSnake(Snake* snake);

	// board infos
	const int height;
	const int width;
	const int padding;
	const int cellSize;

	// The snake

	std::vector<Snake*> snake;
	// time counter
	float timer;
	// float -> for food placememt

	int food[2];
	std::set <std::pair<int, int>> all_spot;
	
};