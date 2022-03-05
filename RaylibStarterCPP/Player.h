#pragma once
#include "Spaceship.h"
class Player : public Spaceship
{
public:
	Player(const char* textureName);
	~Player();

	void Update(float deltaTime);
	void Draw();
	bool isAttacked();
	void DrawCircleAttack(float deltaTime);
	void KinematicUpdate(float deltaTime);

	void DrawTextureWithPivot(const Texture& tex, Vector2 pos, Vector2 pivot, float rot);

private:
	Image playerImage;
	Texture playerTexture;

	Vector2 textureDrawPos;
	//Vector2 mousePos;
	Vector2 bulletPosition = { shipPosition.x, shipPosition.y };
	Vector2 bulletVelocity = { 10, 10 };
	Vector2 bulletAcceleration = { 10,10 };

	float deltaTime;
	float playerRot;
};