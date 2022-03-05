//#include "Spaceship.h"
#include "Behaviour.h"
#include "Graph.h"

Spaceship::Spaceship()
{
	maxHealth = 0;
	currentHealth = maxHealth;
	damage = 0;
	armour = 0;
	detectionRange = 0;
	speed = 0;
	shipPosition = { 50, 50 };
	shipVelocity = { 10, 10 };
	//graph = Graph::Graph();
	graph = new Graph();	
}

Spaceship::~Spaceship()
{
	delete graph;
	graph = nullptr;
}

int Spaceship::DamageDealt()
{
	int damageDealt = damage - armour;
	if (damageDealt < 0)
	{
		armour -= damageDealt;
		std::cout << "No damage has been taken" << std::endl;
		return armour;
	}
	else
	{
		std::cout << damageDealt << " has been dealt to the player" << std::endl;
		return damageDealt;
	}
}

int Spaceship::DamageTaken()
{
	return currentHealth -= DamageDealt();
}

bool Spaceship::isAlive()
{
	if (maxHealth > 0)
	{
		return maxHealth;
	}
	else
	{
		std::cout << "This unit has died" << std::endl;
		maxHealth = 0;
		return false;
	}
}

void Spaceship::Update(float deltaTime)
{
	for (int i = 0; i < behaviourList.size(); i++)
	{
		Vector2 force = behaviourList[i]->Update(this, deltaTime);
		shipVelocity += force * speed * deltaTime;
		shipPosition += shipVelocity * deltaTime;
	}
}

void Spaceship::Draw()
{
	DrawRectangle(shipPosition.x, shipPosition.y, 10, 10, RED);
	
}

void Spaceship::AddBehaviour(Behaviour* behaviour)
{
	behaviourList.push_back(behaviour);
}

void Spaceship::DrawSpaceshipDetectionRange()
{
	Vector2 spaceShipPos = shipPosition;
}

void Spaceship::AttackAIMovement()
{
	float deltaTime = GetFrameTime();
	//graph->AStarSearch(get)
	//Insert path find here
	std::vector<Node*> path = graph->AStarSearch(graph->GetNodeAtPosition(shipPosition), graph->GetNodeAtPosition(targetShip->shipPosition));
	for (int i = 0; i < path.size() - 1; ++i)
	{
		shipVelocity.x = speed;
		shipVelocity.y = speed;
		shipPosition.x += shipVelocity.x * deltaTime;
		shipPosition.y += shipVelocity.y * deltaTime;
	}
}
void Spaceship::InsertAIPatrolPath(Node* node)
{
	patrolPath.push_back(node);
}
void Spaceship::PatrolAIPath()
{
	float deltaTime = GetFrameTime();
	//std::vector<Node*> path = graph->AStarSearch(graph->GetNodeAtPosition(shipPosition), graph->GetNodeAtPosition(shipPosition * 10));
	//patrolPath
	for (int i = 0; i < patrolPath.size(); i++)
	{
		path[i] = graph->AStarSearch(patrolPath[i], patrolPath[(i + 1) % SIZE]);
		patrolPathCounter++;
	}
}
void Spaceship::AITraversing()
{
	Node* shipCurrentNode = graph->GetNodeAtPosition(shipPosition);
	//for (int i = 0; i < patrolPathCounter; i++)
	//{
	//
	//}

	//for (int j = 0; j < path.size(); j++)
	//{
	//	shipVelocity.x = speed;
	//	shipVelocity.y = speed;
	//	shipPosition.x += shipVelocity.x * deltaTime;
	//	shipPosition.y += shipVelocity.y * deltaTime;
	//}
}
///////////////////////////////////////////
//int Spaceship::WithinRange()
//{
//	detectionCircle;
//	Vector2 targetShipVector = targetShip->GetPosition();
//	Vector2 spaceShipVector = shipPosition;
//	float xDiff = targetShipVector.x - spaceShipVector.x;
//	float yDiff = targetShipVector.y - spaceShipVector.y;
//	float distance = sqrtf(xDiff * xDiff + yDiff * yDiff);
//	return distance <= detectionRange;
//}

bool Spaceship::WithinRange(Spaceship* targetShip)
{
	//Vector2 targetShipVector = targetShip->GetPosition();
	//Vector2 spaceShipVector = shipPosition;
	//float xDiff = targetShipVector.x - spaceShipVector.x;
	//float yDiff = targetShipVector.y - spaceShipVector.y;
	//float distance = sqrtf(xDiff * xDiff + yDiff * yDiff);
	//return distance <= detectionRange;
	return Magnitude(targetShip->GetPosition() - shipPosition) <= detectionRange;
	
}