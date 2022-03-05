#include "Asteroid.h"


//#define WANDERING_CIRCLE_RADIUS 30
//#define WANDER_RANDOM_MAG 5
//#define WANDER_FORWARD_OFFSET 20
//#define WANDER_INFLUENCE_MULT 3

Asteroid::Asteroid()
{
}

Asteroid::Asteroid(const char* textureName)
{
	asteroidImage = LoadImage(textureName);
	asteroidTexture = LoadTextureFromImage(asteroidImage);

	position.x = 200.0f;
	position.y = 200.0f;
	velocity.x = 10.0f;
	velocity.y = 10.0f;

	maxSpeed = 60.0f;

	//textureDrawPos.x = (int)asteroidTexture.width / 2;
	//textureDrawPos.y = (int)asteroidTexture.height / 2;
	//
	//agentRotation = atan2f(velocity.y, velocity.x);
	//
	//wanderCircleOffset = { GetRandom(-1, 1), GetRandom(-1, 1) };
	//wanderCircleOffset = Normalise(wanderCircleOffset) * WANDERING_CIRCLE_RADIUS;
}

Asteroid::~Asteroid()
{
	UnloadTexture(asteroidTexture);
	UnloadImage(asteroidImage);
}

void Asteroid::Update()
{
	float deltaTime = GetFrameTime();


	//Vector2 wandomRandomOffset = { GetRandom(-1, 1), GetRandom(-1, 1) };
	//wandomRandomOffset = Normalise(wandomRandomOffset) * WANDER_RANDOM_MAG;
	//
	//wanderCircleOffset += wandomRandomOffset;
	//wanderCircleOffset = Normalise(wanderCircleOffset) * WANDERING_CIRCLE_RADIUS;
	//
	//wanderTarget = position + Normalise(velocity) * WANDER_FORWARD_OFFSET + wanderCircleOffset;
	//
	//Vector2 toTarget = wanderTarget - position;
	//toTarget = Normalise(toTarget) * WANDER_INFLUENCE_MULT;

	//velocity += toTarget;
	//
	//if (Magnitude(velocity) > maxSpeed)
	//{
	//	velocity = Normalise(velocity) * maxSpeed;
	//}

	position += velocity * deltaTime;

	//Screen Wrap
	if (position.x < 0)
	{
		position.x += GetScreenWidth();
	}
	if (position.y < 0)
	{
		position.y += GetScreenHeight();
	}
	if (position.x > GetScreenWidth())
	{
		position.x -= GetScreenWidth();
	}
	if (position.y > GetScreenHeight())
	{
		position.y -= GetScreenHeight();
	}
}

//void DrawTextureWithPivot(const Texture& tex, Vector2 pos, Vector2 pivot, float rot)
//{
//	Vector2 offset = pivot * -1;
//
//	float cosTheta = cos(rot * DEG2RAD);
//	float sinTheta = sin(rot * DEG2RAD);
//
//	Vector2 rotatedOffset;
//
//	rotatedOffset.x = offset.x * cosTheta + offset.y * -sinTheta;
//	rotatedOffset.y = offset.x * sinTheta + offset.y * cosTheta;
//
//	DrawTextureEx(tex, pos + rotatedOffset, rot, 1.0f, WHITE);
//}

void Asteroid::Draw()
{
	DrawTexture(asteroidTexture, position.x, position.y, WHITE);
	//DrawTextureWithPivot(asteroidTexture, position, textureDrawPos, agentRotation);
	DrawCircleV(position, 5, RED);
	//DrawCircle(wanderTarget.x, wanderTarget.y, 5, PURPLE);
}

void Asteroid::WanderBehaviour()
{
}
