#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>

using namespace std;

typedef struct
{
	pair<int, int> position;
	int distanceFromObjective;
} pathingNode;

typedef struct
{
	pair<int, int> position;
} pathingNodesTree;

pair<vector<pathingNode>, vector<pathingNodesTree>> pathing(vector<vector<int>> level, pair<int, int> endPosition, pair<int, int> startPosition, vector<pathingNode> positionValuesTuplesVector, vector<pathingNodesTree> pathingNodeTreesVector)
{

	vector<pathingNode>::iterator minValueTuple = min_element(positionValuesTuplesVector.begin(), positionValuesTuplesVector.end(), [](pathingNode a, pathingNode b) { return a.distanceFromObjective < b.distanceFromObjective; });
	// cout << "Min found had value: " << minValueTuple->distanceFromObjective << endl;

	pathingNode nodeToPush;
	int positionToCheck;

	// checar abajo
	if (minValueTuple->position.first + 1 < level.size())
	{
		positionToCheck = level[minValueTuple->position.first + 1][minValueTuple->position.second];
		if (positionToCheck != 255 && positionToCheck != 7 && positionToCheck != 1)
		{
			nodeToPush.position.first = minValueTuple->position.first + 1;
			nodeToPush.position.second = minValueTuple->position.second;
			nodeToPush.distanceFromObjective = sqrt(pow((int)level.size() - nodeToPush.position.first, 2) + pow((int)level[0].size() - nodeToPush.position.second, 2));
			positionValuesTuplesVector.push_back(nodeToPush);
		}
	}

	// checar derecha
	if (minValueTuple->position.second + 1 < level[0].size())
	{
		positionToCheck = level[minValueTuple->position.first][minValueTuple->position.second + 1];
		if (positionToCheck != 255 && positionToCheck != 7 && positionToCheck != 1)
		{
			nodeToPush.position.first = minValueTuple->position.first;
			nodeToPush.position.second = minValueTuple->position.second + 1;
			nodeToPush.distanceFromObjective = sqrt(pow((int)level.size() - nodeToPush.position.first, 2) + pow((int)level[0].size() - nodeToPush.position.second, 2));
			positionValuesTuplesVector.push_back(nodeToPush);
		}
	}

	// checar izquierda
	if (minValueTuple->position.second - 1 >= 0)
	{
		positionToCheck = level[minValueTuple->position.first][minValueTuple->position.second - 1];
		if (positionToCheck != 255 && positionToCheck != 7 && positionToCheck != 1)
		{
			nodeToPush.position.first = minValueTuple->position.first;
			nodeToPush.position.second = minValueTuple->position.second - 1;
			nodeToPush.distanceFromObjective = sqrt(pow((int)level.size() - nodeToPush.position.first, 2) + pow((int)level[0].size() - nodeToPush.position.second, 2));
			positionValuesTuplesVector.push_back(nodeToPush);
		}
	}

	// checar arriba
	if (minValueTuple->position.first - 1 < level.size())
	{
		positionToCheck = level[minValueTuple->position.first - 1][minValueTuple->position.second];
		if (positionToCheck != 255 && positionToCheck != 7 && positionToCheck != 1)
		{
			nodeToPush.position.first = minValueTuple->position.first - 1;
			nodeToPush.position.second = minValueTuple->position.second;
			nodeToPush.distanceFromObjective = sqrt(pow((int)level.size() - nodeToPush.position.first, 2) + pow((int)level[0].size() - nodeToPush.position.second, 2));
			positionValuesTuplesVector.push_back(nodeToPush);
		}
	}

	pathingNodesTree nodeTreeToPush;
	nodeTreeToPush.position = minValueTuple->position;
	pathingNodeTreesVector.push_back(nodeTreeToPush);

	for (auto iter = positionValuesTuplesVector.begin(); iter != positionValuesTuplesVector.end(); ++iter)
	{
		if (iter->position == minValueTuple->position)
		{
			iter = positionValuesTuplesVector.erase(iter);
			break;
		}
	}

	return pair<vector<pathingNode>, vector<pathingNodesTree>>(positionValuesTuplesVector, pathingNodeTreesVector);
}