#pragma once
#include "raylib.h"
#include "Snake.h"
#include <vector>
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

	int food[2] = { GetRandomValue(0,20), GetRandomValue(0,12) };
};