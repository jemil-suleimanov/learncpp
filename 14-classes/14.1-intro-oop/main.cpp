#include <iostream>
#include <string-view>

struct Cat
{
    std::string_vie name {"cat"};
    int numLegs {4};
};

struct Dog
{
    std::string_vie name {"dog"};
    int numLegs {4};
};


struct Chicken
{
    std::string_vie name {"Chicken"};
    int numLegs {2};
};

struct Snake
{
    std::string_vie name {"snake"};
    int numLegs {0};
};

int mina()
{
    constexpr Snake animal;

    std::cout << "a " << animal.name << " has " << animal.numLegs << " legs\n";

    return 0;
}
