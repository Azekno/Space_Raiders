#pragma once
#include "raylib.h"

class Spacestation
{
public:
	Spacestation(const char* textureName);
	~Spacestation();

	int DamageTaken(int damageDealt);

	void Update();
	void Draw();

private:
	int resources;
	int maxHealth;
	int currentHealth;
	int armour;
	Image spaStatImage;
	Texture spaStatTexture;

	Vector2 position;

};