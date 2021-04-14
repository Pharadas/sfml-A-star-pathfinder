#ifndef PATHINGNODESTRUCT_H
#define PATHINGNODESTRUCT_H

#include <vector>

typedef struct
{
	std::pair<int, int> position;
	int distanceFromObjective;
} pathingNode;

typedef struct
{
	pair<int, int> positon;
	pathingNodesTree *parent;
} pathingNodesTree;

#endif