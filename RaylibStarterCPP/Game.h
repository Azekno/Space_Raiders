#pragma once
#include "raylib.h"
#include <vector>
#include "GameWorld.h"

#define WIN_WIDTH 1024
#define WIN_HEIGHT 1024

class Asteroid;
class ResourceAsteroid;
class Player;
class Fighter;
class KeyboardBehaviour;
class Graph;
class FighterAI;
class Spaceship;

class Game
{
private:
	GameWorld* gameWorld;
	Graph* theGraph;
	FighterAI* state;
	std::vector<Asteroid*> asteroids;
	ResourceAsteroid* resAsteroid;
	Player* playerShip;
	Fighter* fightship;
	KeyboardBehaviour* keyboardBehaviour;
	Fighter* enemyFightShip;
	Spaceship* spaceShip;

	Spaceship* enemySpaceShip;
	float deltaTime;
	float position = 50.0f;
	//Vector2 testPosition;
public:
	//Game() {}

	//void GameWorld(const char* textureName);

	void Init();

	void Shutdown();

	void Update();

	void Draw();

};