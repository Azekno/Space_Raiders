#pragma once
#include "raylib.h"
#include "Graph.h"
#include <math.h>
#include <cmath>


static float Magnitude(Vector2 a)
{
	return sqrtf((a.x * a.x) + (a.y * a.y));
}

static Vector2 Normalise(Vector2 value)
{
	Vector2 result;

	float length = Magnitude(value);
	if (length != 0)
	{
		result.x = value.x / length;
		result.y = value.y / length;

		return result;
	}

	result.x = 0;
	result.y = 0;

	return result;
}

static Vector2 operator+(Vector2 a, Vector2 b)
{
	Vector2 vector2;

	vector2.x = a.x + b.x;
	vector2.y = a.y + b.y;
	return vector2;
}

static Vector2 operator-(Vector2 a, Vector2 b)
{
	Vector2 vector2;

	vector2.x = a.x - b.x;
	vector2.y = a.y - b.y;
	return vector2;
}

static Vector2 operator*(Vector2 a, float b)
{
	Vector2 vector2;

	vector2.x = a.x * b;
	vector2.y = a.y * b;
	return vector2;
}

static Vector2 operator/(Vector2 a, float b)
{
	Vector2 vector2;

	vector2.x = a.x / b;
	vector2.y = a.y / b;
	return vector2;
}

static Vector2 operator+=(Vector2& vec, Vector2 otherVec)
{
	vec.x += otherVec.x;
	vec.y += otherVec.y;
	return vec;
}

static Vector2 operator-=(Vector2& vec, Vector2 otherVec)
{
	vec.x -= otherVec.x;
	vec.y -= otherVec.y;
	return vec;
}

static float GetRandom(float min, float max)
{
	float range = max - min;

	float value = rand() / (float)RAND_MAX;
	value *= range;
	return value + min;
}

static Vector2 ConvertScreenToGrid(Vector2 playerScreenVec2)
{
	return{ playerScreenVec2.x / GRAPH_SIZE, playerScreenVec2.y / GRAPH_SIZE };
}

static Vector2 ConvertGridToScreen(Vector2 playerGridVec2)
{
	return playerGridVec2 * GRAPH_SIZE;
}