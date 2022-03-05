#include "Player.h"

Player::Player(const char* textureName)
{
	playerImage = LoadImage(textureName);
	playerTexture = LoadTextureFromImage(playerImage);
	maxHealth = 50;
	currentHealth = maxHealth;
	armour = 10;
	damage = 10;
	//mousePos.x = 0;
	//mousePos.y = 0;
	detectionRange = 150.0f;
	speed = 70.0f;
	shipPosition = { 800, 650 };
	textureDrawPos.x = playerTexture.width / 2;
	textureDrawPos.y = playerTexture.height / 2;

	deltaTime = 0;
	playerRot = atan2f(shipVelocity.y, shipVelocity.x);

}

Player::~Player()
{
	UnloadTexture(playerTexture);
	UnloadImage(playerImage);
}

void Player::Update(float deltaTime)
{
	//deltaTime = GetFrameTime();
	Spaceship::Update(deltaTime);

	if (shipPosition.x < 0)
	{
		shipVelocity = { 0,0 };
		//shipPosition.x += GetScreenWidth();
	}
	if (shipPosition.y < 0)
	{
		shipVelocity = { 0,0 };
		//shipPosition.y += GetScreenHeight();
	}
	if (shipPosition.x > GetScreenWidth())
	{
		shipVelocity = { 0,0 };
		//shipPosition.x -= GetScreenWidth();
	}
	if (shipPosition.y > GetScreenHeight())
	{
		shipVelocity = { 0,0 };
		//shipPosition.y -= GetScreenHeight();
	}

	DrawCircleAttack(deltaTime);
}

void Player::Draw()
{
	deltaTime = GetFrameTime();
	DrawSpaceshipDetectionRange();
	//DrawTexture(fighterTexture, shipPosition.x, shipPosition.y, WHITE);
	DrawTextureWithPivot(playerTexture, shipPosition, textureDrawPos, playerRot);
	DrawCircleAttack(deltaTime);
}

bool Player::isAttacked()
{
	return false;
}

void Player::DrawCircleAttack(float deltaTime)
{
	if (IsKeyDown(KEY_SPACE))
	{
		DrawCircle(shipPosition.x, shipPosition.y, 5.0f, PURPLE);
		KinematicUpdate(deltaTime);
	}
}

void Player::KinematicUpdate(float deltaTime)
{
	bulletPosition += bulletVelocity * deltaTime; //one sixtieth
	bulletVelocity += bulletAcceleration * deltaTime;
}

void Player::DrawTextureWithPivot(const Texture& tex, Vector2 pos, Vector2 pivot, float rot)
{
	Vector2 offset = pivot * -1;
	
	float cosTheta = cos(rot * DEG2RAD);
	float sinTheta = sin(rot * DEG2RAD);

	Vector2 rotatedOffset;

	rotatedOffset.x = offset.x * cosTheta + offset.y * -sinTheta;
	rotatedOffset.y = offset.x * sinTheta + offset.y * cosTheta;

	DrawTextureEx(tex, pos + rotatedOffset, rot, 1.0f, WHITE);
}
