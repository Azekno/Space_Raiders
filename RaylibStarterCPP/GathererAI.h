#pragma once
#include "AIManager.h"

class Gatherer;

enum class GatherState
{
	Idle = 0,
	Gather = 1,
	Transport = 2
};

class GathererAI
{
public:
	GathererAI(Gatherer* selectedGatherer, GameWorld* gWPointer);
	~GathererAI();

	void Update();

	void TransitionState(GatherState newState);

private:
	GatherState currentState;
	int deltaTime;
	int distanceToTarget;
	int countdownTimer;
};