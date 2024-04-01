#pragma once
class Snake {
public:
	Snake(int x, int y);
	int getX() const;

	int getY() const;
private:
	// 0 -> represent left
	// 1 -> represent down
	// 2 -> represent right
	// 3 - > represent up
	int dir;
	int pos_x;
	int pos_y;
	
};