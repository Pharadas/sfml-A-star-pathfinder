#include <include/tileMapper.hpp>
#include <iostream>
#include <include/randomNum.hpp>
#include <include/pathFinding.hpp>
// #include <thread>

int main()
{
	int width = 600;
	int height = 600;
	bool shouldKeepLooking = true;
	int tileSize = 30;
	// std::cin >> tileSize;

	std::vector<std::vector<int>> level;
	vector<pathingNode> pathingNodesVector;
	pathingNode initialPathingNode;
	initialPathingNode.position = pair<int, int>(0, 0);
	initialPathingNode.distanceFromObjective = 100000;
	pathingNodesVector.push_back(initialPathingNode);

	for (int y = 0; y < height / tileSize; y++)
	{
		std::vector<int> yVector;
		for (int x = 0; x < width / tileSize; x++)
		{
			if (getRandomNum(1, 4) == 1)
			{
				yVector.push_back(255);
			}
			else
			{
				yVector.push_back(0);
			}
		}
		level.push_back(yVector);
	}

	// create the tilemap from the level definition
	TileMap map;
	map.screenHeight = height;
	map.screenWidth = width;
	map.tileSize = tileSize;
	map.tileset = "DwarfFortressTileset.png";

	level[0][0] = 1;
	level[level.size() - 1][level[0].size() - 1] = 2;

	// draw posible tiles
	// auto thisThing = positionValueTuplesVector.begin();

	if (!map.buildTilemap(level))
		return -1;

	// create the window
	sf::RenderWindow window(sf::VideoMode(width, height), "Tilemap");

	// run the main loop
	while (window.isOpen())
	{
		// handle events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			else if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Space)
				{
					pathingNodesVector = pathFinding(level, pair<int, int>(0, 0), pair<int, int>(level.size() - 1, level[0].size() - 1), pathingNodesVector);
					if (pathingNodesVector.size() != 0 && level[level.size() - 1][level[0].size() - 1] != 7)
					{
						for (auto i : pathingNodesVector)
						{
							level[i.position.first][i.position.second] = 7;
						}
						if (!map.buildTilemap(level))
						{
							return -1;
						}
					}
					else
					{
						cout << "pretty fucking done" << endl;
					}
					// }
					// else
					// {
					// 	cout << "im done, fucker" << endl;
					// }
					// for (auto i : pathingNodesVector)
					// {
					// 	cout << i.position.first << ' ' << i.position.second << ' ' << i.distanceFromObjective << endl;
					// 	cout << "####################" << endl;
					// }
				}
				// }
			}
			// if (shouldKeepLooking)
			// {
			// 	pathingNodesVector = singleCallPathing(level, pair<int, int>(0, 0), pair<int, int>(level.size() - 1, level[0].size() - 1), pathingNodesVector);
			// 	for (auto i : pathingNodesVector)
			// 	{
			// 		level[i.position.first][i.position.second] = 7;
			// 	}
			// 	if (!map.buildTilemap(level))
			// 		return -1;
			// 	if (pathingNodesVector.size() == 0)
			// 	{
			// 		cout << "i cant look no more" << endl;
			// 		shouldKeepLooking = false;
			// 		// window.close();
			// 	}
			// 	else if (level.back().back() == 7)
			// 	{
			// 		cout << "i found it" << endl;
			// 		shouldKeepLooking = false;
			// 		// window.close();
			// 	}
		}
		window.clear();
		for (auto y : map.thisTileMap)
		{
			for (auto x : y)
			{
				window.draw(x);
			}
		}
		window.display();
	}

	return 0;
}
