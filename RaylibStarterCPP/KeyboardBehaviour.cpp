#include "KeyboardBehaviour.h"

Vector2 KeyboardBehaviour::Update(Spaceship* spaceShip, float deltaTime)
{
    return MovementVector();
}

Vector2 KeyboardBehaviour::MovementVector()
{
    Vector2 force = { 0,0 };
    if (IsKeyDown(KEY_UP))
    {
        force.y = -speedIncrement;
    }
    if (IsKeyDown(KEY_DOWN))
    {
        force.y = speedIncrement;
    }
    if (IsKeyDown(KEY_LEFT))
    {
        force.x = -speedIncrement;
    }
    if (IsKeyDown(KEY_RIGHT))
    {
        force.x = speedIncrement;
    }
    return force;
}
