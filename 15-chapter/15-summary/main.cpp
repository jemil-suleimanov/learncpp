#include "Random.h"
#include <iostream>
#include <string>
#include <string_view>

class Monster
{
public:
    enum Type
    {
        dragon,
        goblin,
        ogre,
        orc,
        skeleton,
        troll,
        vampire,
        zombie,
        maxMonsterTypes
    };

private:
    Type m_type{};
    std::string m_name{"???"};
    std::string m_roar{"???"};
    int m_hitPoints{};

public:
    Monster(Type type, std::string_view name, std::string_view roar, int hitPoints)
        : m_type{ type }, m_name{ name }, m_roar{ roar }, m_hitPoints{ hitPoints }
    {}
    
    void print() const
    {
        if (m_hitPoints > 0)
            std::cout << m_name << " the " << getTypeString(m_type) << " has " << m_hitPoints << " and says " << m_roar << '\n';
        else
            std::cout << m_name << " the " << getTypeString(m_type) << " is dead \n";
    }

private:
    constexpr std::string_view getTypeString(Type monsterType) const
    {
        switch (monsterType)
        {
        case dragon: return "dragon";
        case goblin: return "goblin";
        case ogre: return "ogre";
        case orc: return "orc";
        case skeleton: return "skeleton";
        case troll: return "troll";
        case vampire: return "vampire";
        case zombie: return "zombie";
        default: return "???";
        }
    }
};

namespace MonsterGenerator {
    std::string_view getName(int num)
    {
        switch (num)
        {
            case 0: return "Boromir";
            case 1: return "Gimli";
            case 2: return "Gandalf";
            case 3: return "Frodo";
            case 4: return "Aragorn";
            case 5: return "Legolas";
            default: return "Smog";
        }
    }

    std::string_view getRoar(int num)
    {
        switch (num)
        {
            case 0: return "*Rah*";
            case 1: return "*Roar*";
            case 2: return "*Rattle*";
            case 3: return "*Argh*";
            case 4: return "*Wuff*";
            case 5: return "*Meow*";
            default: return "*Boom*";
        }
    }

    Monster generate()
    {
        return Monster{ static_cast<Monster::Type>(Random::get(0, Monster::maxMonsterTypes-1)), getName(Random::get(0, 6)), getRoar(Random::get(0, 6)), Random::get(1,100)};
    }

}

int main()
{
	Monster skeleton{ MonsterGenerator::generate() };
    skeleton.print();

    Monster vampire{ Monster::vampire, "Nibblez", "*hiss*", 0 };
	vampire.print();

	return 0;
}
