#pragma once

class Drawer {
public: 
	Drawer(int height, int width,int padding, int cellSize);
	void Update();
	void Draw();
	void Control();
private:
	void DrawBoard();
};