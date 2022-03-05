#pragma once
#include "Spaceship.h"

class Behaviour
{
public:
	//empty constructors and destructors for the base class
	Behaviour() {}
	virtual ~Behaviour() {}

	//pure virtual function for executing the behaviour
	virtual Vector2 Update(Spaceship* spaceShip, float deltaTime) = 0;
};
