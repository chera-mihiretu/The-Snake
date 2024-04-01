#include "Drawer.h"

Drawer::Drawer(int height, int width, int padding, int cellSize):
	height(height), width(width), padding(padding), cellSize(cellSize)
{
}

void Drawer::Update()
{
}

void Drawer::Draw()

{
	Rectangle boundary = Rectangle{ (float)padding /2, (float)padding/2, (float)width, (float)height };
	DrawRectangleLinesEx(boundary, padding/2 , GRAY);
}

void Drawer::Control()
{
}

void Drawer::DrawBoard()
{
}
