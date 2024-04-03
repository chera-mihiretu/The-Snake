#pragma once
#include "Snake.h"
#include <iostream>
#include <vector>
#include <raylib.h>
class Control {
public:
	Control(std::vector<Snake*>* snake);
	void listenClick();
	void setClicked(bool val);
private:
	bool can_click;
	std::vector<Snake*>* snake;
	// used to track the direction of the snake
	const enum DIR_VAL {
		RIGHT,
		DOWN,
		LEFT,
		UP
	};
	// clicked interval controller
};