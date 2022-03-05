#pragma once
#include "raylib.h"
#include <vector>
#include <iostream>

class Spaceship;
class Node;

class GameWorld
{
public:
	GameWorld(const char* textureName);
	~GameWorld();

	void Update();
	void Draw();
	//std::vector<std::vector<Spaceship*>> allSpaceShips;
	std::vector<Spaceship*> allShips;	//These are examples written by Finn
	int allShipSize = 5;
	//std::vector<Asteroid*> allAsteroids;
	//std::vector<Node*> patrolPath;

private:
	Image backgroundImage;
	Texture backgroundTexture;

	Vector2 gameBackgroundPosition;
	Vector2 tiling;
	Vector2 offset;
	Rectangle quad;
};