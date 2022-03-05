#pragma once
#include "AIManager.h"
#define COUNTDOWN 3

enum class State
{
	Idle,
	Patrolling,
	Attack,
	Gather,
	Transport,
};

class Spaceship;
//Every agent should have one of these.
class FighterAI
{
public:
	GameWorld* gameWorldPointer;
	Spaceship* owner;
	FighterAI(Spaceship* spaceship, GameWorld* gWPointer);
	~FighterAI();

	void Update();

	void TransitionState(State newState);

private:
	State currentState;
	int countdownTimer;
	int deltaTime;
	int distanceToTarget;
	int counter = 0;
};