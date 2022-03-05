#pragma once
#include "Asteroid.h"

class ResourceAsteroid : Asteroid
{
public:
	ResourceAsteroid(const char* textureName);
	~ResourceAsteroid();

	void Update();
	void Draw();

private:
	int mineral;

	//Image resAstImage;
	//Texture resAstTexture;

	float maxSpeed;
	Vector2 position;
	Vector2 velocity;
};
