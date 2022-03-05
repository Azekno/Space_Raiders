#include "Spaceships.h"

Spaceships::Spaceships()
{
	health = 0;
	damage = 0;
	armour = 0;
}

Spaceships::~Spaceships()
{
}

int Spaceships::DamageDealt()
{
	return 0;
}

int Spaceships::DamageTaken()
{
	return health -= damage;
}

bool Spaceships::isAlive()
{
	if (health > 0)
	{
		return health;
	}
	else
	{
		health = 0;
		return false;
	}
}
