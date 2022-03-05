#pragma once
#include "raylib.h"
#include <vector>
class Edge;

//namespace PathFinding
//{
//	class Node
//	{
//	public:
//		Vector2 pos;
//
//		float gScore;
//		float hScore;
//		float fScore;
//		Node* previous = nullptr;
//		std::vector<Edge> connections;
//
//		//std::vector<Node*> connections;
//		bool blocked = false;
//		//float GetF() const { return hScore + gScore; }
//
//	};
//}

class Node
{
public:
	Vector2 pos;

	float gScore = 0;
	float hScore = 0;
	//float fScore;
	Node* previous = nullptr;
	//std::vector<Edge> connections;

	std::vector<Node*> connections;
	bool blocked = false;
	float GetF() const { return hScore + gScore; }

};
