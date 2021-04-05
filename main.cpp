#include <include/tileMapper.hpp>
#include <iostream>
#include <include/randomNum.hpp>
#include <include/pathing.hpp>

int main()
{
    int width = 1200;
    int height = 650;

    int tileSize = 20;
    // std::cin >> tileSize;

    // create the window
    sf::RenderWindow window(sf::VideoMode(width, height), "Tilemap");

    std::vector<std::vector<int>> level;
    std::tuple<std::pair<int, int>, int, int, int> positionValueTuple;
    std::vector<std::tuple<std::pair<int, int>, int, int, int>> positionValueTuplesVector;

    for (int y = 0; y < height / tileSize; y++)
    {
        std::vector<int> yVector;
        for (int x = 0; x < width / tileSize; x++)
        {
            if (getRandomNum(1, 3) == 1)
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

    tuple<pair<int, int>, int, int, int> thisPositionValueTuple;
    // y position
    get<0>(thisPositionValueTuple).first = 0;
    // x position
    get<0>(thisPositionValueTuple).second = 0;
    // distance from start
    get<1>(thisPositionValueTuple) = 0;
    // distance from end
    get<2>(thisPositionValueTuple) = (level.size() * level.size()) + (level[0].size() * level[0].size());
    // sum of distances
    get<3>(thisPositionValueTuple) = get<2>(thisPositionValueTuple) + get<1>(thisPositionValueTuple);

    positionValueTuplesVector.push_back(thisPositionValueTuple);

    positionValueTuplesVector = pathing(level, positionValueTuplesVector);

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
    for (auto i : positionValueTuplesVector)
    {
        level[get<0>(i).first][get<0>(i).second] = 7;
    }

    if (!map.buildTilemap(level))
        return -1;

    bool shouldKeepLooking = true;

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
                // if (event.key.code == sf::Keyboard::Space)
                // {
                //     positionValueTuplesVector = pathing(level, positionValueTuplesVector);
                //     for (auto i : positionValueTuplesVector)
                //     {
                //         level[get<0>(i).first][get<0>(i).second] = 7;
                //     }
                //     if (!map.buildTilemap(level))
                //         return -1;
                // }
            }
        }
        if (shouldKeepLooking)
        {
            positionValueTuplesVector = pathing(level, positionValueTuplesVector);
            for (auto i : positionValueTuplesVector)
            {
                level[get<0>(i).first][get<0>(i).second] = 7;
            }
            if (!map.buildTilemap(level))
                return -1;
            if (positionValueTuplesVector.size() == 0)
            {
                cout << "fuck you, i cant look no more" << endl;
                shouldKeepLooking = false;
                // window.close();
            }
            else if (level.back().back() == 7)
            {
                cout << "fuck you, i found it" << endl;
                shouldKeepLooking = false;
                // window.close();
            }
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