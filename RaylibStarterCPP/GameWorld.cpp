#include "GameWorld.h"

GameWorld::GameWorld(const char* textureName)
{
	backgroundImage = LoadImage(textureName);
	backgroundTexture = LoadTextureFromImage(backgroundImage);

	gameBackgroundPosition.x = 0;
	gameBackgroundPosition.y = 0;

	tiling.x = backgroundTexture.width;
	tiling.y = backgroundTexture.height;

	offset.x = 0;
	offset.y = 0;

	quad.x = gameBackgroundPosition.x;
	quad.y = gameBackgroundPosition.y;
	quad.width = GetScreenWidth() ;
	quad.height = GetScreenHeight();
}

GameWorld::~GameWorld()
{
	UnloadTexture(backgroundTexture);
	UnloadImage(backgroundImage);
}

void GameWorld::Update()
{
}

void GameWorld::Draw()
{
	DrawTextureQuad(backgroundTexture, tiling, offset, quad, WHITE);
	//DrawTexture(backgroundTexture, 0, 0, SKYBLUE);
}
