#include <iostream>
#include <random>
#include <vector>

int getRandomNum(const int lowerRange, const int upperRange)
{
    std::random_device rd;                                         // obtain a random number from hardware
    std::mt19937 gen(rd());                                        // seed the generator
    std::uniform_int_distribution<> distr(lowerRange, upperRange); // define the range

    return distr(gen);
}

std::vector<int> getRandomNumVector(const int lowerRange, const int upperRange, const int arrayLength)
{
    std::vector<int> returnArray;
    std::random_device rd;                         // obtain a random number from hardware
    std::mt19937 gen(rd());                        // seed the generator
    std::uniform_int_distribution<> distr(25, 63); // define the range

    for (int n = 0; n < 40; ++n)
        returnArray.push_back(distr(gen)); // generate numbers
    return returnArray;
}

// int main()
// {
//     std::cout << getRandomNum(1, 1000) << std::endl;
// }