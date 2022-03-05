#pragma once
#include "Node.h"
#define GRAPH_SIZE 20
#define NODE_SPACING 50

class Graph
{

public:
	Node nodes[GRAPH_SIZE][GRAPH_SIZE];
	
	Graph();
	Graph(const Graph& other) = delete;
	const Graph& operator=(const Graph& other) = delete;
	//void Draw() const;
	void Draw();
	Node* GetNodeAtPosition(Vector2 position);

	std::vector<Node*> AStarSearch(Node* startNode, Node* endNode);
private:
	void ConnectNodes(int xCoord1, int yCoord1, int xCoord2, int yCoord2);
};