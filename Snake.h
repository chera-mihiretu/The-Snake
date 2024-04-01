#pragma once
#include "constants.cpp"
namespace cons = constant;
class Snake {
public:
	Snake();
private:
	// 0 -> represent left
	// 1 -> represent down
	// 2 -> represent right
	// 3 - > represent up
	cons::DIR_VAL direction = cons::DIR_VAL::LEFT;
	int pos_x;
	int pos_y;
	
};