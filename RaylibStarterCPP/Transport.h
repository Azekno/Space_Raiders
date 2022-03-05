#pragma once
#include "Spaceship.h"

class Transport : public Spaceship
{
public:
	Transport(const char* textureName);
	~Transport();

	void Update(float deltaTime);
	void Draw();

	void EmptyTransport();
	void ReturnTransport();
private:
	int resources;

	Image transportImage;
	Texture transportTexture;
};