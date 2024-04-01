#pragma once
#include "raylib.h"
class Drawer {
public: 
	Drawer(int height, int width,int padding, int cellSize);
	void Update();
	void Draw();
	void Control();
private:
	void DrawBoard();
	const int height;
	const int width;
	const int padding;
	const int cellSize;
};