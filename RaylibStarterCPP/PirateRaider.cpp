#include "PirateRaider.h"

PirateRaider::PirateRaider(const char* textureName)
{
	pirRaidImage = LoadImage(textureName);
	pirRaidTexture = LoadTextureFromImage(pirRaidImage);
	maxHealth = 50;
	currentHealth = maxHealth;
	damage = 8;
	armour = 6;
	resources = 0;

}

PirateRaider::~PirateRaider()
{
}

void PirateRaider::Update(float deltaTime)
{
}

void PirateRaider::Draw()
{
}
