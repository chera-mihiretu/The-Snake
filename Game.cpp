#include "Game.h"

Game::Game(int height, int width, int padding, int cellSize,std::string title, int menu):
	height(height), width(width),title(title), padding(padding),cellSize(cellSize), menu(menu)
{	
	
	InitWindow(width  +  padding * 2 + menu, height  + padding * 2, title.c_str());
	// we calculate the cell incase we might wanna change the size of the frame
	draw = new Drawer(height + padding, width + padding, padding, cellSize);
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
			
		draw->ControlCaller();
		draw->Draw();
		draw->Update();
			
		//std::cout << "hellow" << std::endl;
		draw->DrawSetting(width + padding, height, menu);

		// drawing the boarders
		draw->DrawBoard();
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
