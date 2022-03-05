#include "Gatherer.h"

Gatherer::Gatherer(const char* textureName)
{
	image = LoadImage(textureName);
	texture = LoadTextureFromImage(image);
	maxHealth = 50;
	currentHealth = maxHealth;
	damage = 1;
	armour = 1;
	resources = 0;
	speed = 90.0f;
	detectionRange = 50.0f;
}

Gatherer::~Gatherer()
{
}

void Gatherer::Update(float deltaTime)
{
	shipPosition += shipVelocity * deltaTime;
}

void Gatherer::Draw()
{
}

void Gatherer::PathFind()
{
	if (resources == 0)
	{
		//path find to nearest resource asteroid
	}
	if (resources == 1)
	{
		//path find to the nearest transport ship
	}
}

int Gatherer::GatherResources()
{
	return 0;
}
