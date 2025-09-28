#include "monster.h"
#include <iostream>
#include <string>
#include <string_view>

struct Monster
{
    enum MonsterType {
        ogre,
        dragon,
        giantSpider,
        slime,
    };

    MonsterType type {ogre};
    std::string name {};
    int health {};
};

constexpr std::string_view getMonsterType(Monster::MonsterType monster)
{
    switch(monster) {
        case Monster::ogre: return "ogre";
        case Monster::dragon: return "dragon";
        case Monster::giantSpider: return "giantSpider";
        case Monster::slime: return "slime";
        default: return "???";
    }
}

std::ostream& operator<<(std::ostream& out, Monster::MonsterType monster)
{
    out << getMonsterType(monster);
    return out;
}

void printMonster(const Monster& monster)
{
    std::cout << "This " << monster.type << " is named " << monster.name << " and has " << monster.health << " health.\n";
}

void doMonsters()
{
    Monster ogre {Monster::ogre, "Torg", 145 };
    Monster slime {Monster::slime, "Blurp", 23 };

    printMonster(ogre);
    printMonster(slime);
}