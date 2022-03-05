#pragma once
#include "AIManager.h"

enum class TransportState
{

};

class TransportAI
{
public:
	TransportAI();
	~TransportAI();

	void Update();

	void TransitionState(TransportState newState);

private:
	TransportState currentState;
	float deltaTime;
	int countdownTimer;
	int distanceToTarget;
};