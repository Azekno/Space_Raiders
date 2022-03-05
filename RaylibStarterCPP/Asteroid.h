#pragma once
#include "raylib.h"
#include "MyMath.h"

/*find the textures dimensions
Create a random generator function to random place the asteroid's around the screen
Use the world's dimensions to spawn the asteroids
Maybe allow for the Gatherer class of spaceship to have an ability to stop an asteroids movement
*/

class Asteroid
{
public:
	Asteroid();
	Asteroid(const char* textureName);
	~Asteroid();

	void Update();
	void Draw();

	void WanderBehaviour();

protected:
	Image asteroidImage;
	Texture asteroidTexture;
	//Vector2 textureDrawPos;

	float maxSpeed;
	Vector2 position;
	Vector2 velocity;
	//float agentRotation;

	//Vector2 wanderCircleOffset;
	//Vector2 wanderTarget;
};
//void DrawTexturedWithPivot(const Texture& tex, Vector2 pos, Vector2 pivot, float rot);