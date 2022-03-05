#include "raylib.h"
#include "Game.h"


int main()
{

	InitWindow(WIN_WIDTH, WIN_HEIGHT, "Raiders");
	Game game;

	game.Init();

	while (!WindowShouldClose())
	{
		game.Update();
		game.Draw();
	}

	game.Shutdown();
	CloseWindow();
} 