#pragma once
#include "Spaceship.h"
class Fighter : public Spaceship
{
public:
	Fighter(const char* textureName);
	~Fighter();

	void Update(float deltaTime);
	void Draw();
	bool isAttacked();

	void SeekBehaviour();
	//int DamageDealt();
	void FleeBehaviour();
	void WanderBehaviour();
	void DrawTextureWithPivot(const Texture& tex, Vector2 pos, Vector2 pivot, float rot);

private:
	Image fighterImage;
	Texture fighterTexture;

	Vector2 textureDrawPos;
	Vector2 mousePos;

	float fighterRot;
	Vector2 wanderCircleOffset;
	Vector2 wanderTarget;
};
