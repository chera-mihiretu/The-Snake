#pragma once
#ifndef GAME_H
#define GAME_H


#include "raylib.h"
#include <string>
#include "Drawer.h"
class Game {

private:
	// have ifno about the condition of the game
	void GameRunner();
	bool GameOver() const;
	// this is drawer on the screen
	Drawer* draw;

	// infos about the game inviroment look
	// values are given from the main function
	const int height;
	const int width;
	const int padding;
	const int cellSize;
	const int menu;
	const std::string title;

public:
	// kill the game
	~Game() noexcept;
public:
	// this is what begins the game
	Game(int height, int width, int paddind, int cellSize, std::string title, int menu);
	void StartGame();


}; 
#endif // !GAME_H