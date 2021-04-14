#ifndef PATHINGNODELOGIC_H
#define PATHINGNODELOGIC_H

#include <iostream>
#include <algorithm>
#include "pathingNodeStruct.h"

using namespace std;

vector<pathingNode> singleCallPathing(vector<vector<int>> level, pair<int, int> initialPosition, pair<int, int> objectivePosition, vector<pathingNode> pathingNodeList)
{
	cout << "entered single call pathing function" << endl;
	bool keepLooking = true;
	pathingNode nodeToModify;
	nodeToModify.position = initialPosition;
	nodeToModify.distanceFromObjective = abs(objectivePosition.first - initialPosition.first) + abs(objectivePosition.second - initialPosition.second);

	pathingNodeList.push_back(nodeToModify);

	// while (keepLooking)
	// {
	cout << "still looking" << endl;
	auto minValueNode = min_element(pathingNodeList.begin(), pathingNodeList.end(), [](pathingNode a, pathingNode b) { return a.distanceFromObjective < b.distanceFromObjective; });

	int positionToCheck;

	// checar arriba
	if (minValueNode->position.first - 1 < level.size())
	{
		positionToCheck = level[minValueNode->position.first - 1][minValueNode->position.second];
		if (positionToCheck != 255 && positionToCheck != 7 && positionToCheck != 1)
		{
			nodeToModify.position.first = minValueNode->position.first - 1;
			nodeToModify.position.second = minValueNode->position.second;
			nodeToModify.distanceFromObjective = sqrt(pow(objectivePosition.first - nodeToModify.position.first, 2) + pow(objectivePosition.second - nodeToModify.position.second, 2));
			pathingNodeList.push_back(nodeToModify);
			level[minValueNode->position.first + 1][minValueNode->position.second] = 7;
		}
		if (positionToCheck == 2)
		{
			cout << "found it" << endl;
			keepLooking = false;
			return pathingNodeList;
		}
	}

	// // checar derecha
	if (minValueNode->position.second + 1 < level[0].size())
	{
		positionToCheck = level[minValueNode->position.first][minValueNode->position.second + 1];
		if (positionToCheck != 255 && positionToCheck != 7 && positionToCheck != 1)
		{
			nodeToModify.position.first = minValueNode->position.first;
			nodeToModify.position.second = minValueNode->position.second + 1;
			nodeToModify.distanceFromObjective = sqrt(pow(objectivePosition.first - nodeToModify.position.first, 2) + pow(objectivePosition.second - nodeToModify.position.second, 2));
			pathingNodeList.push_back(nodeToModify);
			level[minValueNode->position.first + 1][minValueNode->position.second] = 7;
		}
		if (positionToCheck == 2)
		{
			cout << "found it" << endl;
			keepLooking = false;
			return pathingNodeList;
		}
	}

	// // checar izquierda
	if (minValueNode->position.second - 1 >= 0)
	{
		positionToCheck = level[minValueNode->position.first][minValueNode->position.second - 1];
		if (positionToCheck != 255 && positionToCheck != 7 && positionToCheck != 1)
		{
			nodeToModify.position.first = minValueNode->position.first;
			nodeToModify.position.second = minValueNode->position.second - 1;
			nodeToModify.distanceFromObjective = sqrt(pow(objectivePosition.first - nodeToModify.position.first, 2) + pow(objectivePosition.second - nodeToModify.position.second, 2));
			pathingNodeList.push_back(nodeToModify);
			level[minValueNode->position.first + 1][minValueNode->position.second] = 7;
		}
		if (positionToCheck == 2)
		{
			cout << "found it" << endl;
			keepLooking = false;
			return pathingNodeList;
		}
	}

	// checar abajo
	if (minValueNode->position.first + 1 < level.size())
	{
		positionToCheck = level[minValueNode->position.first + 1][minValueNode->position.second];
		if (positionToCheck != 255 && positionToCheck != 7 && positionToCheck != 1)
		{
			nodeToModify.position.first = minValueNode->position.first + 1;
			nodeToModify.position.second = minValueNode->position.second;
			nodeToModify.distanceFromObjective = sqrt(pow(objectivePosition.first - nodeToModify.position.first, 2) + pow(objectivePosition.second - nodeToModify.position.second, 2));
			pathingNodeList.push_back(nodeToModify);
			level[minValueNode->position.first + 1][minValueNode->position.second] = 7;
		}
		if (positionToCheck == 2)
		{
			cout << "found it" << endl;
			keepLooking = false;
			return pathingNodeList;
		}
	}

	// weird shit with std::find and structs
	// for (vector<pathingNode>::iterator i = pathingNodeList.begin(); i !=  pathingNodeList.end(); i++) {
	// 	if (*i == *minValueNode)
	// }

	// if (it != pathingNodeList.end())
	// {
	// cout << "found node correctle" << endl;
	pathingNodeList.erase(minValueNode);
	// }`

	if (pathingNodeList.size() == 1)
	{
		keepLooking = false;
		cout << "no path to objective" << endl;
		return pathingNodeList;
	}
	// }
	return pathingNodeList;
}

#endif