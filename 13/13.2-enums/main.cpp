#include <iostream>

enum Color
{
    red,
    green,
    blue,
};

namespace Monster {
    enum MonsterType {
        orc,
        goblin,
        troll,
        ogre,
        skeleton
    };
}

int main()
{
    Color apple { red };
    Color shirt { green };
    Color cup {blue};

    std::cout << apple << ' ' << shirt << ' ' << cup << '\n';

    Monster::MonsterType troll { Monster::troll };

    std::cout << troll << '\n';

    return 0;
}