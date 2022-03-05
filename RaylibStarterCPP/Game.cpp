#include "Game.h"
#include <sstream>	//String stream, used for the FPS counter
#include "Graph.h"
//#include "GameWorld.h"
#include "ResourceAsteroid.h"
#include "Player.h"
#include "Fighter.h"
#include "Gatherer.h"
#include "KeyboardBehaviour.h"
#include "FighterAI.h"

#define ASTEROID_COUNT 1

//void Game::GameWorld(const char* textureName)
//{
//	backgroundImage = LoadImage(textureName);
//	backgroundTexture = LoadTextureFromImage(backgroundImage);
//}

void Game::Init()
{
	gameWorld = new GameWorld("space_background.png");

	for (int i = 0; i < ASTEROID_COUNT; i++)
	{
		asteroids.push_back(new Asteroid("paintResourceAsteroid.png"));
	}
	resAsteroid = new ResourceAsteroid("paintResourceAsteroid.png");

	//keyboardBehaviour = new KeyboardBehaviour();
	//enemyFightShip = new Fighter("enemyAgent.png");
	//playerShip = new Player("agent.png");
	//playerShip->AddBehaviour(keyboardBehaviour);
	//theGraph = new Graph();
	//enemySpaceShip = new Spaceship();
	//state = new FighterAI(enemyFightShip, gameWorld);

	//spaceShip = new Spaceship();
	//gameWorld->allShips.push_back(playerShip);

	//enemyFightShip->InsertAIPatrolPath(&theGraph->nodes[2][2]);
	//enemyFightShip->InsertAIPatrolPath(&theGraph->nodes[2][5]);
	//enemyFightShip->InsertAIPatrolPath(&theGraph->nodes[5][5]);
	//enemyFightShip->InsertAIPatrolPath(&theGraph->nodes[5][2]);
	SetTargetFPS(60);
}

void Game::Shutdown()
{
	//UnloadTexture(backgroundTexture);
	//UnloadImage(backgroundImage);
	
	for (int i = 0; i < ASTEROID_COUNT; i++)
	{
		delete asteroids[i];
		asteroids[i] = nullptr;
	
	}
	//delete resAsteroid;
	//resAsteroid = nullptr;
	//delete playerShip;
	//playerShip = nullptr;
	//delete fightship;
	//fightship = nullptr;
	//delete keyboardBehaviour;
	//keyboardBehaviour = nullptr;
	//delete theGraph;
	//theGraph = nullptr;
	//delete enemySpaceShip;
	//enemySpaceShip = nullptr;
	//delete state;
	//state = nullptr;
}

void Game::Update()
{
	deltaTime = GetFrameTime();
	//position += 10 * deltaTime;

	//for (int i = 0; i < ASTEROID_COUNT; i++)
	//{
	//	asteroids[i]->Update();
	//}
	//resAsteroid->Update();
	//playerShip->Update(deltaTime);
	//enemyFightShip->Update(deltaTime);
	//state->Update();
	
	//Put game logic and input management here.w

}

void Game::Draw()
{

	std::stringstream fpsCounter;

	fpsCounter << "FPS: " << GetFPS();

	BeginDrawing();	//Rendering code comes after this call...
	ClearBackground(SKYBLUE);

	gameWorld->Draw();
	//theGraph->Draw();
	//asteroids->Draw();
	//resAsteroid->Draw();
	//playerShip->Draw();
	//enemyFightShip->Draw();
	DrawText(fpsCounter.str().c_str(), 10, 10, 20, RED);


	EndDrawing();	//...and before this one.

}
