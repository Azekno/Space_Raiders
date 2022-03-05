#include "Fighter.h"

#define WANDERING_CIRLCE_RADIUS 30
#define WANDER_RANDOM_MAG 5
#define WANDER_FORWARD_OFFSET 20
#define WANDER_INFLUENCE_MULT 3

Fighter::Fighter(const char* textureName)
{
	fighterImage = LoadImage(textureName);
	fighterTexture = LoadTextureFromImage(fighterImage);
	maxHealth = 100;
	currentHealth = maxHealth;
	armour = 10;
	damage = 10;
	mousePos.x = 0;
	mousePos.y = 0;
	detectionRange = 150.0f;
	speed = 70.0f;

	textureDrawPos.x = fighterTexture.width / 2;
	textureDrawPos.y = fighterTexture.height / 2;

	fighterRot = atan2f(shipVelocity.y, shipVelocity.x);

	wanderCircleOffset = { GetRandom(-1, 1), GetRandom(-1, 1) };
	wanderCircleOffset = Normalise(wanderCircleOffset) * WANDERING_CIRLCE_RADIUS;
	wanderTarget.x = 0;
	wanderTarget.y = 0;

	//state.owner = this;
}

Fighter::~Fighter()
{
	UnloadTexture(fighterTexture);
	UnloadImage(fighterImage);
}

void Fighter::Update(float deltaTime)
{
	//Vector2 movementVector = Vector2((float)-Math.Sin(playerTank.tankPositionRotation), (float)Math.Cos(playerTank.tankPositionRotation) * tankMoveSpeed * deltaTime);
	mousePos = GetMousePosition();
	//if (IsKeyDown(KEY_T))
	//{
	//	std::cout << "SEEKING" << std::endl;
	//	SeekBehaviour();
	//}
	//if (IsKeyDown(KEY_Y))
	//{
	//	std::cout << "FLEEING" << std::endl;
	//	FleeBehaviour();
	//}
	//if (IsKeyPressed(KEY_J))
	//{
	//	std::cout << "WANDERING" << std::endl;
	//	WanderBehaviour();
	//}
	//state.Update();
	//Spaceship::Update(deltaTime);

	
	//if (collision occurs)
	//{
	//	DamageTaken();
	//}
	//WithinRange();
	if (shipPosition.x < 0)
	{
		shipPosition.x += GetScreenWidth();
	}
	if (shipPosition.y < 0)
	{
		shipPosition.y += GetScreenHeight();
	}
	if (shipPosition.x > GetScreenWidth())
	{
		shipPosition.x -= GetScreenWidth();
	}
	if (shipPosition.y > GetScreenHeight())
	{
		shipPosition.y -= GetScreenHeight();
	}
}
void Fighter::DrawTextureWithPivot(const Texture& tex, Vector2 pos, Vector2 pivot, float rot)
{
	Vector2 offset = pivot * -1;

	float cosTheta = cos(rot * DEG2RAD);
	float sinTheta = sin(rot * DEG2RAD);

	Vector2 rotatedOffset;

	rotatedOffset.x = offset.x * cosTheta + offset.y * -sinTheta;
	rotatedOffset.y = offset.x * sinTheta + offset.y * cosTheta;

	DrawTextureEx(tex, pos + rotatedOffset, rot, 1.0f, WHITE);
}
void Fighter::Draw()
{
	DrawSpaceshipDetectionRange();
	//DrawTexture(fighterTexture, shipPosition.x, shipPosition.y, WHITE);
	DrawTextureWithPivot(fighterTexture, shipPosition, textureDrawPos, fighterRot);
	
}

bool Fighter::isAttacked()
{
	return false;
}

void Fighter::SeekBehaviour()
{
	
	//mousePos.x -= 10;
	//mousePos.y -= 10;

	float deltaTime = GetFrameTime();
	//DesiredVelocity = normalise(P2-P1) x maxVelocity
	Vector2 direction = Normalise(mousePos - shipPosition) * speed;

	//SteeringForce = DesiredVelocity - CurrentVelocity
	Vector2 steeringForce = direction - shipPosition;
	//Velocity += SteeringForce * deltaTime
	shipVelocity.x += steeringForce.x * deltaTime;
	shipVelocity.y += steeringForce.y * deltaTime;
	//Position += Velocity * deltaTime
	shipPosition.x += shipVelocity.x * deltaTime;
	shipPosition.y += shipVelocity.y * deltaTime;
}

void Fighter::FleeBehaviour()
{
	mousePos = GetMousePosition();
	float deltaTime = GetFrameTime();
	Vector2 direction = Normalise(shipPosition - mousePos) * speed;

	Vector2 steeringForce = direction - shipVelocity;
	shipVelocity.x += steeringForce.x * deltaTime;
	shipVelocity.y += steeringForce.y * deltaTime;

	shipPosition.x += shipVelocity.x * deltaTime;
	shipPosition.y += shipVelocity.y * deltaTime;
}

void Fighter::WanderBehaviour()
{
	mousePos = GetMousePosition();
	float deltaTime = GetFrameTime();

	Vector2 wanderRandomOffset = { GetRandom(-1, 1), GetRandom(-1, 1) };
	wanderRandomOffset = Normalise(wanderRandomOffset) * WANDER_RANDOM_MAG;

	wanderCircleOffset += wanderRandomOffset;
	wanderCircleOffset = Normalise(wanderCircleOffset) * WANDERING_CIRLCE_RADIUS;

	wanderTarget = shipPosition + Normalise(shipVelocity) * WANDER_FORWARD_OFFSET + wanderCircleOffset;

	Vector2 toTarget = wanderTarget - shipPosition;
	toTarget = Normalise(toTarget) * WANDER_INFLUENCE_MULT;

	shipVelocity += toTarget;

	if (Magnitude(shipVelocity) > speed)
	{
		shipVelocity = Normalise(shipVelocity) * speed;
	}
}