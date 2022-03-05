#include "Spacestation.h"

Spacestation::Spacestation(const char* textureName)
{
	spaStatImage = LoadImage(textureName);
	spaStatTexture = LoadTextureFromImage(spaStatImage);

	maxHealth = 1000;
	currentHealth = maxHealth;
	armour = 100;
	resources = 0;

	position.x = 50.0f;
	position.y = 100.0f;
}

Spacestation::~Spacestation()
{
	UnloadTexture(spaStatTexture);
	UnloadImage(spaStatImage);
}

int Spacestation::DamageTaken(int damageDealt)
{
	return currentHealth = armour - damageDealt;
}

void Spacestation::Update()
{
}

void Spacestation::Draw()
{
}
