#pragma once
#include "PirateRaiderAI.h"

enum class RaiderState
{
	Idle,
	Raid,
	Attack,
	Transport
};

class PirateRaiderAI
{
public:
	PirateRaiderAI();
	~PirateRaiderAI();

	void Update();

	void TransitionState(RaiderState newState);

private:
	RaiderState currentState;
	float deltaTime;
	int countdownTimer;
	int distanceToTarget;
};