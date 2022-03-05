#include <iostream>
#include <algorithm>
#include "myMath.h"


Graph::Graph()
{
	for (int x = 0; x < GRAPH_SIZE; x++)
	{
		for (int y = 0;y < GRAPH_SIZE; y++)
		{
			nodes[x][y].pos = { 
				(float)(x * NODE_SPACING + NODE_SPACING * 0.5f), 
				(float)(y * NODE_SPACING + NODE_SPACING * 0.5f) };

			for (int xOffset = -1; xOffset <= 1; xOffset++)
			{
				for (int yOffset = -1; yOffset <= 1; yOffset++)
				{
					ConnectNodes(x, y, x + xOffset, y + yOffset);
				}
			}

		}
	}
	for (int y = 0; y < GRAPH_SIZE - 5; y++)
	{
		nodes[7][y].blocked = true;
	}
}
//This should be a const function
//void Graph::Draw() const
void Graph::Draw()
{
	for (int x = 0; x < GRAPH_SIZE; x++)
	{
		for (int y = 0; y < GRAPH_SIZE; y++)
		{
			if (!nodes[x][y].blocked)
			{
				for (auto thisConnectedNode : nodes[x][y].connections)
				{
					Vector2 halfwayPoint = { (nodes[x][y].pos.x * 0.5f + thisConnectedNode->pos.x * 0.5f),
					(nodes[x][y].pos.y * 0.5f + thisConnectedNode->pos.y * 0.5f) };
					DrawLineEx(nodes[x][y].pos, halfwayPoint, 2, BLUE);
				}
			}
		}
	}

	for (int x = 0; x < GRAPH_SIZE; x++)
	{
		for (int y = 0;y < GRAPH_SIZE; y++)
		{
			if (!nodes[x][y].blocked)
			{
				DrawCircleV(nodes[x][y].pos, 5, RED);
			}
		}
	}

	//Find a path and draw it
	//Look at 1:30-5:00pm ~13-15 mins. Richard explains about what the AI will need to do
	//in order to find a path. 
	//This next code is a dodgey hack
	//std::vector<Node*> path = AStarSearch(&nodes[2][2], &nodes[15][10]);
	//for (int i = 0; i < path.size() - 1; ++i)
	//{
	//	DrawLineEx(path[i]->pos, path[i + 1]->pos, 10, DARKGREEN);
	//}
}

Node* Graph::GetNodeAtPosition(Vector2 position)
{
	Node* closestSoFar = &nodes[0][0];
	float closestToDistance = Magnitude(nodes[0][0].pos - position);
	for (int i = 0; i < GRAPH_SIZE; i++)
	{
		for (int j = 0; j < GRAPH_SIZE; j++)
		{
			Node* thisNode = &nodes[i][j];
			float distanceToThisNode = Magnitude(thisNode->pos - position);
			if (distanceToThisNode < closestToDistance)
			{
				closestToDistance = distanceToThisNode;
				closestSoFar = thisNode;
			}
		}
	}
	//ConvertScreenToGrid({GetScreenWidth, GetScreenHeight})
	//position
	return closestSoFar;
}

std::vector<Node*> Graph::AStarSearch(Node* startNode, Node* endNode)
{
	if (startNode == nullptr || endNode == nullptr)
	{
		std::cout << "The start or end node is invalid" << std::endl;
		return std::vector<Node*>();
	}
	if (startNode == endNode)
	{
		std::cout << "The start of the path equals the end part of the path" << std::endl;
		return std::vector<Node*>();
	}
	startNode->gScore = 0;
	startNode->previous = nullptr;

	std::vector<Node*>openList;
	std::vector<Node*>closedList;

	openList.push_back(startNode);

	while (openList.size() > 0)
	{
		std::sort(openList.begin(), openList.end(), [](const Node* first, const Node* second)
			{
				return first->GetF() < second->GetF();
			});
		Node* currentNode = openList[0];
		openList.erase(openList.begin());

		if (currentNode == endNode)
		{
			//std::cout << "Current node equals end node" << std::endl;
			//Path find code insert here??
			std::vector<Node*> finalPath;
			finalPath.push_back(currentNode);

			while (currentNode->previous)
			{
				currentNode = currentNode->previous;
				finalPath.push_back(currentNode);
			}
			return finalPath;
		}
		closedList.push_back(currentNode);


		for (auto outGoingNode : currentNode->connections)
		{
			//Check if blocked
			if (outGoingNode->blocked)
				continue;
			//First, check if it's closed.
			if (std::find(closedList.begin(), closedList.end(), outGoingNode) != closedList.end())
			{
				continue;
			}
			//bool isNodeClosed = false;
			//for (int i = 0; i < closedList.size(); i++)
			//{
			//	if (closedList[i] == outGoingNode)
			//	{
			//		isNodeClosed = true;
			//		break;
			//	}
			//}
			//if (isNodeClosed)
			//{
			//	continue;
			//}
			
			//Calculate scores
			float gScoreLocal = currentNode->gScore + NODE_SPACING;//cost

			//Now, check if it's already in the open list
			if (std::find(openList.begin(), openList.end(), outGoingNode) != openList.end())
			{
				if (gScoreLocal < outGoingNode->gScore)
				{
					outGoingNode->gScore = gScoreLocal;
					outGoingNode->previous = currentNode;
				}
			}
			else
			{
				outGoingNode->gScore = gScoreLocal;
				//Heuristic function(current target, end node)
				outGoingNode->hScore = abs(endNode->pos.x - outGoingNode->pos.x) + abs(endNode->pos.y - outGoingNode->pos.y);
				outGoingNode->previous = currentNode;
				openList.push_back(outGoingNode);
			}
			//bool isAlreadyOpen = false;
			//for (int i = 0; openList.size(); i++)
			//{
			//	if (openList[i] == outGoingNode)
			//	{
			//
			//	}
			//}
		}
	}
}

//std::vector<Node*> Graph::AStarSearch(Node* startNode, Node* endNode) // By Finn  & Richard
//{
//	if (startNode == nullptr || endNode == nullptr)
//	{
//		std::cout << "The start node or end node is invalid" << std::endl;
//		return;
//	}
//	if (startNode == endNode)
//	{
//		std::cout << "The start of the path equals the end part of the path" << std::endl;
//	}
//	if (startNode->blocked || endNode->blocked)
//	{
//		return std::vector<Node*>();
//	}
//
//	startNode->gScore = 0;
//	startNode->previous = nullptr;
//
//	std::vector<Node*>openList;
//	std::vector<Node*>closedList;
//
//	openList.push_back(startNode);
//	
//	
//
//	while (openList.size() > 0)
//	{
//		//Get the lowest f vlue from the open queue
//
//		std::sort(openList.begin(), openList.end(), [](const Node* first, const Node* second)
//			{
//				return first->GetF() < second->GetF();
//			});
//		Node* currentNode = openList[0];
//		openList.erase(openList.begin());
//
//		//Now, expand the node.
//		if (currentNode == endNode)
//		{
//			//We found a path! Do something here
//			//TODO
//		}
//		
//		for (auto outgoingNode : currentNode->connections)
//		{
//			//First, check if it's closted
//			for (int i = 0; i < closedList.size(); i++)
//			{
//
//			}
//		}
//	}
//	
//	std::vector<Node*> finalPath;
//	finalPath.push_back(currentNode);
//	
//	while (currentNode == nullptr)
//	{
//		finalPath.push_back(currentNode);
//		currentNode = currentNode->previous;
//	}
//	return finalPath;
//
//	//We haven't found a path.
//	return std::vector<Node*>();
//}

void Graph::ConnectNodes(int xCoord1, int yCoord1, int xCoord2, int yCoord2)
{
	if (xCoord1 == xCoord2 && yCoord1 == yCoord2)
	{
		return;
	}
	if (xCoord1 < 0 || xCoord2 < 0)
	{
		return;
	}
	if (xCoord1 >= GRAPH_SIZE || xCoord2 >= GRAPH_SIZE)
	{
		return;
	}
	if (yCoord1 < 0 || yCoord2 < 0)
	{
		return;
	}
	if (yCoord1 >= GRAPH_SIZE || yCoord2 >= GRAPH_SIZE)
	{
		return;
	}

	nodes[xCoord1][yCoord1].connections.push_back(&nodes[xCoord2][yCoord2]);
}
