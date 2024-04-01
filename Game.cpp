#include "Game.h"

Game::Game(int height, int width, int padding, int cellSize,std::string title):
	height(height), width(width),title(title), padding(padding),cellSize(cellSize)
{	
	InitWindow(width + padding, height + padding, title.c_str());
	// we calculate the cell incase we might wanna change the size of the frame
	draw = new Drawer(height, width, padding, cellSize);
	StartGame();
}

void Game::StartGame()
{
	GameRunner();
}

void Game::GameRunner()
{
	while (!GameOver()) {
		BeginDrawing();
		ClearBackground(RAYWHITE);
		draw->Control();
		draw->Draw();
		draw->Update();
		EndDrawing();
	}
}

bool Game::GameOver() const
{
	return WindowShouldClose();
}

Game::~Game() noexcept
{
	// we close window when these class is destroyed
	CloseWindow();
}
