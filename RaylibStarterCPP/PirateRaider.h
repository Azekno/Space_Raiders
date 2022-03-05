#pragma once
#include "Spaceship.h"

class PirateRaider : public Spaceship
{
public:
	PirateRaider(const char* textureName);
	~PirateRaider();

	void Update(float deltaTime);
	void Draw();
private:
	Image pirRaidImage;
	Texture pirRaidTexture;
	
	int resources;
};
