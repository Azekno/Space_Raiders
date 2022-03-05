#pragma once
#include "Behaviour.h"

class KeyboardBehaviour : public Behaviour
{
public: 
	KeyboardBehaviour() {};
	virtual ~KeyboardBehaviour() {};

	virtual Vector2 Update(Spaceship* spaceShip, float deltaTime);

	Vector2 MovementVector();

private:
	float speedIncrement = 1.0f;
};