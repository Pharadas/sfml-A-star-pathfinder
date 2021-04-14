#include <iostream>
#include <algorithm>
#include <vector>

typedef struct
{
	std::pair<int, int> position;
	int distanceFromObjective;
} pathingNode;

using namespace std;

vector<pathingNode> pathFinding(vector<vector<int>> level, pair<int, int> startingPosition, pair<int, int> objectivePosition, vector<pathingNode> existingNodesVector)
{
	if (existingNodesVector.size() > 0)
	{
		auto minValueNode = min_element(existingNodesVector.begin(), existingNodesVector.end(), [](pathingNode a, pathingNode b) { return a.distanceFromObjective < b.distanceFromObjective; });

		cout << minValueNode->position.first << ' ' << minValueNode->position.second << ' ' << minValueNode->distanceFromObjective << endl;
		pathingNode nodeToModify;
		int positionToCheck;

		// checar debajo del nodo mas cercano al objetivo para asegurar que este dentro del nivel
		if (minValueNode->position.first + 1 < level.size())
		{
			positionToCheck = level[minValueNode->position.first + 1][minValueNode->position.second];
			if (positionToCheck != 255 && positionToCheck != 7 && positionToCheck != 1)
			{
				nodeToModify.position.first = minValueNode->position.first + 1;
				nodeToModify.position.second = minValueNode->position.second;
				nodeToModify.distanceFromObjective = pow(objectivePosition.first - nodeToModify.position.first, 2) + pow(objectivePosition.second - nodeToModify.position.second, 2);
				// nodeToModify.distanceFromObjective = minValueNode->distanceFromObjective - 1;
				existingNodesVector.push_back(nodeToModify);
			}
		}

		// checar a la derecha del nodo mas cercano al objetivo para asegurar que este dentro del nivel
		if (minValueNode->position.second + 1 < level[0].size())
		{
			positionToCheck = level[minValueNode->position.first][minValueNode->position.second + 1];
			if (positionToCheck != 255 && positionToCheck != 7 && positionToCheck != 1)
			{
				nodeToModify.position.first = minValueNode->position.first;
				nodeToModify.position.second = minValueNode->position.second + 1;
				nodeToModify.distanceFromObjective = pow(objectivePosition.first - nodeToModify.position.first, 2) + pow(objectivePosition.second - nodeToModify.position.second, 2);
				// nodeToModify.distanceFromObjective = minValueNode->distanceFromObjective - 1;
				existingNodesVector.push_back(nodeToModify);
			}
		}

		// checar a la izquiera del nodo mas cercano al objetivo para asegurar que este dentro del nivel
		if (minValueNode->position.second - 1 >= 0)
		{
			positionToCheck = level[minValueNode->position.first][minValueNode->position.second - 1];
			if (positionToCheck != 255 && positionToCheck != 7 && positionToCheck != 1)
			{
				nodeToModify.position.first = minValueNode->position.first;
				nodeToModify.position.second = minValueNode->position.second - 1;
				nodeToModify.distanceFromObjective = pow(objectivePosition.first - nodeToModify.position.first, 2) + pow(objectivePosition.second - nodeToModify.position.second, 2);
				// nodeToModify.distanceFromObjective = minValueNode->distanceFromObjective - 1;
				existingNodesVector.push_back(nodeToModify);
			}
		}

		// checar arriba del nodo mas cercano al objetivo para asegurar que este dentro del nivel
		if (minValueNode->position.first - 1 < level.size())
		{
			positionToCheck = level[minValueNode->position.first + 1][minValueNode->position.second];
			if (positionToCheck != 255 && positionToCheck != 7 && positionToCheck != 1)
			{
				nodeToModify.position.first = minValueNode->position.first - 1;
				nodeToModify.position.second = minValueNode->position.second;
				nodeToModify.distanceFromObjective = pow(objectivePosition.first - nodeToModify.position.first, 2) + pow(objectivePosition.second - nodeToModify.position.second, 2);
				// nodeToModify.distanceFromObjective = minValueNode->distanceFromObjective - 1;
				existingNodesVector.push_back(nodeToModify);
			}
		}

		for (vector<pathingNode>::iterator i = existingNodesVector.begin(); i != existingNodesVector.end(); i++)
		{
			if (i == minValueNode)
			{
				cout << "lo borre correctamente" << endl;
				existingNodesVector.erase(i);
			}
		}
	}
	return existingNodesVector;
}