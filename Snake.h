#pragma once
class Snake {
public:
	Snake(int x, int y, int cellSize,int  padding);
	int getX() const;

	int getY() const;
	// updating things
	void setX(int x);
	void setY(int y);
	void setDir(int pos);
	int getDir()const;
	// for drawing
	int getDrawingX() const;
	int getDrawingY() const;
	// moving the snake
	int move(int dir);


private:
	// 0 -> represent left
	// 1 -> represent down
	// 2 -> represent right
	// 3 - > represent up
	int dir;
	int pos_x;
	int pos_y;
	int cellSize;
	int padding;
	

};