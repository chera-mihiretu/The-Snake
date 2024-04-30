#include "raylib.h"
#include "Game.h"
#include "constants.cpp"
namespace cn = constant;
int main() {
	// This is where every thing begins
	Game* game = new Game(cn::height, cn::width, cn::padding, cn::cellSize, cn::title, cn::menu);

	
}