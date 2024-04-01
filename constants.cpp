#include <string>
namespace constant {
	// used to track the direction of the snake
	const enum DIR_VAL {
		LEFT,
		DOWN,
		RIGHT,
		UP
	};

	//used to rearrange the window size and stuffs including snake size
	constexpr int horizontal_cell = 20;
	constexpr int verticla_cell = 12;
	constexpr int cellSize = 40;

	// 
	constexpr int height = verticla_cell * cellSize;
	constexpr int width = horizontal_cell * cellSize;
	constexpr int padding = 20;



	const std::string title = "Snake";

}