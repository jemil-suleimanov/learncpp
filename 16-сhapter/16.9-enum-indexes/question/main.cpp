#include <iostream>
#include <vector>

namespace Animals
{
    enum Names
    {
        chicken,
        dog,
        cat,
        elephant,
        duck,
        snake,
        MaxAnimals
    };
}

int main()
{
    std::vector<int> legs{ 2, 4, 4, 4, 2, 0 };

    std::cout << legs[Animals::elephant];

    return 0;
}