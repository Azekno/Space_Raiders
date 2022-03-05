#pragma once
#include "Spaceship.h"

class Gatherer : public Spaceship
{
public:
	Gatherer(const char* textureName);
	~Gatherer();

	void Update(float deltaTime);
	void Draw();
	
	void PathFind();
	int GatherResources();
private:
	Image image;
	Texture texture;

	int resources;
};
