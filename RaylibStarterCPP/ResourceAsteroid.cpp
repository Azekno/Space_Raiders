#include "ResourceAsteroid.h"

ResourceAsteroid::ResourceAsteroid(const char* textureName)
{
	position.x = 300.0f;
	position.y = 300.0f;
	velocity.x = 10.0f;
	velocity.y = 10.0f;

	maxSpeed = 60.0f;

	mineral = 100;
}

ResourceAsteroid::~ResourceAsteroid()
{
}

void ResourceAsteroid::Update()
{
	int deltaTime = GetFrameTime();

	position += velocity * deltaTime;
}

void ResourceAsteroid::Draw()
{
	DrawTexture(asteroidTexture, position.x, position.y, WHITE);
}
