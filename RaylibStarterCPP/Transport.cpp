#include "Transport.h"

Transport::Transport(const char* textureName)
{
	transportImage = LoadImage(textureName);
	transportTexture = LoadTextureFromImage(transportImage);
	maxHealth = 200;
	currentHealth = maxHealth;
	damage = 0;
	armour = 50;
	resources = 0;
}

Transport::~Transport()
{
	UnloadTexture(transportTexture);
	UnloadImage(transportImage);
}

void Transport::Update(float deltaTime)
{
	shipPosition += shipVelocity * deltaTime;
}

void Transport::Draw()
{
}

void Transport::EmptyTransport()
{
	if (resources == 0)
	{
		//Path find to the nearest asteroid and gatherer
	}
}

void Transport::ReturnTransport()
{
	if (resources == 10)
	{
		//Path find to the space station
	}
}
