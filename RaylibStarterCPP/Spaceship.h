#pragma once
#include "raylib.h"
#include "raymath.h"
#include "MyMath.h"
#include "GameWorld.h"
#define SIZE 4

class Behaviour;
class Graph;
class FighterAI;

class Spaceship
{
public:
	Spaceship();
	virtual ~Spaceship();
	GameWorld* gameWorld = nullptr;

	int DamageDealt();
	int DamageTaken();
	bool isAlive();

	virtual void Update(float deltaTime);

	virtual void Draw();

	void AddBehaviour(Behaviour* behaviour);

	//Movement Functions
	void SetPosition(Vector2 position) { shipPosition = position; }
	Vector2 GetPosition() { return shipPosition; }
	void SetVelocity(Vector2 position) { shipVelocity = position; }
	Vector2 GetVelocity() { return shipVelocity; }
	
	//std::vector<Spaceship*> spaceship;

	void DrawSpaceshipDetectionRange();
	void AttackAIMovement();
	void InsertAIPatrolPath(Node* node);
	void PatrolAIPath();
	void AITraversing();
	bool WithinRange(Spaceship* targetShip);

	//A pure virtual function
	//Used when the child's function are handled differently from each other and the virtual function must be overridden
	//virtual int DamageTaken() = 0;
	//Spaceship* targetShip;
	Spaceship* targetShip = nullptr;
	Vector2 shipVelocity;
	Vector2 shipPosition;

	std::vector<Node*> patrolPath;
	std::vector<Node*> path[SIZE];
	int patrolPathCounter = 0;

protected:
	float detectionRange;

	Graph* graph;
	std::vector<Behaviour*> behaviourList;


	//Don't need a detection circle as it is doing the same thing as the ships Position and detectionRange. 
	//Essentially doing the same thing twice without detectionCircle being updated at the same time as the two variables
	//Circle detectionCircle = { shipPosition, detectionRange };
	int maxHealth;
	int currentHealth;
	int damage;
	int armour;
	float speed;
};


