#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class TileMap
{
public:
	vector<vector<sf::RectangleShape>> thisTileMap;
	sf::Texture texture;
	int screenHeight;
	int screenWidth;
	int tileSize;
	const int sizeOfTiles = 15;
	const int amountOfTilesPerRow = 16;
	string tileset;

	bool buildTilemap(vector<vector<int>> level)
	{
		if (!texture.loadFromFile(tileset))
			return false;
		thisTileMap.clear();

		int heightPadding = screenHeight - (int(screenHeight / tileSize) * tileSize);
		int widthPadding = screenWidth - (int(screenWidth / tileSize) * tileSize);
		vector<vector<int>>::iterator yIndex = level.begin();

		for (int y = heightPadding / 2; y < screenHeight - (heightPadding); y += tileSize)
		{
			vector<sf::RectangleShape> yVector;
			vector<int>::iterator xIndex = yIndex->begin();
			for (int x = widthPadding / 2; x < screenWidth - (widthPadding); x += tileSize)
			{
				int tileHeight = int(*xIndex / amountOfTilesPerRow);
				int tileLength = *xIndex - (amountOfTilesPerRow * tileHeight);
				sf::RectangleShape thisRectangle(sf::Vector2f(tileSize, tileSize));
				thisRectangle.setPosition(x, y);
				thisRectangle.setTexture(&texture);
				thisRectangle.setTextureRect(sf::IntRect(tileLength * sizeOfTiles, tileHeight * sizeOfTiles, sizeOfTiles, sizeOfTiles));
				// thisRectangle.setOutlineThickness(1);
				// thisRectangle.setOutlineColor(sf::Color(255, 255, 255));
				yVector.push_back(thisRectangle);
				++xIndex;
			}
			thisTileMap.push_back(yVector);
			++yIndex;
		}
		return true;
	}
};