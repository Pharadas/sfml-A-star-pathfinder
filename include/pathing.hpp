#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>

using namespace std;

vector<tuple<pair<int, int>, int, int, int>> pathing(vector<vector<int>> level, vector<tuple<pair<int, int>, int, int, int>> positionValuesTuplesVector)
{

	auto minValueTuple = min_element(positionValuesTuplesVector.begin(), positionValuesTuplesVector.end(), [](tuple<pair<int, int>, int, int, int> a, tuple<pair<int, int>, int, int, int> b) { return get<3>(a) < get<3>(b); });
	// cout << get<0>(*minValueTuple).first << ' ' << get<0>(*minValueTuple).second << endl;

	// if (get<0>(*minValueTuple).first == level.size() && get<0>(*minValueTuple).second == level[0].size())
	// {
	// 	cout << "fuck you im done" << endl;
	// }

	tuple<pair<int, int>, int, int, int> positionTupleToPush;

	// checar abajo
	if (get<0>(*minValueTuple).first + 1 < level.size())
	{
		if (level[get<0>(*minValueTuple).first + 1][get<0>(*minValueTuple).second] != 255 && level[get<0>(*minValueTuple).first + 1][get<0>(*minValueTuple).second] != 7 && level[get<0>(*minValueTuple).first + 1][get<0>(*minValueTuple).second] != 1)
		{
			get<0>(positionTupleToPush).first = get<0>(*minValueTuple).first + 1;
			get<0>(positionTupleToPush).second = get<0>(*minValueTuple).second;
			get<1>(positionTupleToPush) = sqrt(pow(get<0>(positionTupleToPush).first + 1, 2) + pow(get<0>(positionTupleToPush).second, 2));
			get<2>(positionTupleToPush) = sqrt(pow(level.size() - get<0>(positionTupleToPush).first + 1, 2) + pow(level[0].size() - get<0>(positionTupleToPush).second, 2));
			get<3>(positionTupleToPush) = get<2>(positionTupleToPush);
			positionValuesTuplesVector.push_back(positionTupleToPush);
		}
	}

	// checar derecha
	if (get<0>(*minValueTuple).second + 1 < level[0].size())
	{
		if (level[get<0>(*minValueTuple).first][get<0>(*minValueTuple).second + 1] != 255 && level[get<0>(*minValueTuple).first][get<0>(*minValueTuple).second + 1] != 7 && level[get<0>(*minValueTuple).first][get<0>(*minValueTuple).second + 1] != 1)
		{
			get<0>(positionTupleToPush).first = get<0>(*minValueTuple).first;
			get<0>(positionTupleToPush).second = get<0>(*minValueTuple).second + 1;
			get<1>(positionTupleToPush) = sqrt(pow(get<0>(positionTupleToPush).first, 2) + pow(get<0>(positionTupleToPush).second + 1, 2));
			get<2>(positionTupleToPush) = sqrt(pow(level.size() - get<0>(positionTupleToPush).first, 2) + pow(level[0].size() - get<0>(positionTupleToPush).second + 1, 2));
			get<3>(positionTupleToPush) = get<2>(positionTupleToPush);
			positionValuesTuplesVector.push_back(positionTupleToPush);
		}
	}

	// checar izquierda
	if (get<0>(*minValueTuple).second - 1 >= 0)
	{
		if (level[get<0>(*minValueTuple).first][get<0>(*minValueTuple).second - 1] != 255 && level[get<0>(*minValueTuple).first][get<0>(*minValueTuple).second - 1] != 7 && level[get<0>(*minValueTuple).first][get<0>(*minValueTuple).second - 1] != 1)
		{
			get<0>(positionTupleToPush).first = get<0>(*minValueTuple).first;
			get<0>(positionTupleToPush).second = get<0>(*minValueTuple).second - 1;
			get<1>(positionTupleToPush) = sqrt(pow(get<0>(positionTupleToPush).first, 2) + pow(get<0>(positionTupleToPush).second + 1, 2));
			get<2>(positionTupleToPush) = sqrt(pow(level.size() - get<0>(positionTupleToPush).first, 2) + pow(level[0].size() - get<0>(positionTupleToPush).second - 1, 2));
			get<3>(positionTupleToPush) = get<2>(positionTupleToPush);
			positionValuesTuplesVector.push_back(positionTupleToPush);
		}
	}

	// checar arriba
	if (get<0>(*minValueTuple).first - 1 < level.size())
	{
		if (level[get<0>(*minValueTuple).first - 1][get<0>(*minValueTuple).second] != 255 && level[get<0>(*minValueTuple).first - 1][get<0>(*minValueTuple).second] != 7 && level[get<0>(*minValueTuple).first - 1][get<0>(*minValueTuple).second] != 1)
		{
			// level[get<0>(*minValueTuple).first - 1][get<0>(*minValueTuple).second] != 255
			get<0>(positionTupleToPush).first = get<0>(*minValueTuple).first - 1;
			get<0>(positionTupleToPush).second = get<0>(*minValueTuple).second;
			get<1>(positionTupleToPush) = sqrt(pow(get<0>(positionTupleToPush).first - 1, 2) + pow(get<0>(positionTupleToPush).second, 2));
			get<2>(positionTupleToPush) = sqrt(pow(level.size() - get<0>(positionTupleToPush).first - 1, 2) + pow(level[0].size() - get<0>(positionTupleToPush).second, 2));
			get<3>(positionTupleToPush) = get<2>(positionTupleToPush);
			positionValuesTuplesVector.push_back(positionTupleToPush);
		}
	}

	auto it = find(positionValuesTuplesVector.begin(), positionValuesTuplesVector.end(), *minValueTuple);

	if (it != positionValuesTuplesVector.end())
	{
		positionValuesTuplesVector.erase(it);
	}

	return positionValuesTuplesVector;
}
// int main() {
// 	vector<vector<int>> level;

// }