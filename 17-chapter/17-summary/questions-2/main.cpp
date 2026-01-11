#include <array>
#include <string>
#include <iostream>
#include "Random.h"
#include <limits>

namespace Potion
{
    enum Type {
        healing,
        mana,
        speed,
        invisibility,
        maxPotions
    };

    constexpr std::array types { healing, mana, speed, invisibility };
    constexpr std::array<std::string_view, Potion::maxPotions> name {
        "healing", "mana", "speed", "invisibility"
    };
    constexpr std::array<int, Potion::maxPotions> cost { 20, 30, 12, 50 };

    static_assert(std::size(types) == maxPotions);
    static_assert(std::size(cost) == maxPotions);
    static_assert(std::size(name) == maxPotions);
};

class Player
{
private:
    std::string_view m_name {};
    int m_gold {};
    std::array<int, Potion::maxPotions> m_inventory {};

    void addToInventory(Potion::Type p)
    {
        m_inventory[p] += 1;
    }

    void chargeGold(int gold)
    {
        m_gold -= gold;
    }

    bool canAfford(Potion::Type p)
    {
        return (m_gold - Potion::cost[p]) >= 0;
    }

public:
    Player(int gold, std::string_view name)
        : m_name{name}, m_gold{gold}
    {}

    void greet()
    {
        std::cout << "Hello, " << m_name << ", you have " << m_gold << " gold.\n\n";
    }

    int getGold() const { return m_gold; }
    std::string_view getName() const { return m_name; }
    int getInventory(Potion::Type p) const { return m_inventory[p]; }

    void purchasePotion(Potion::Type p)
    {
        if(canAfford(p)) {
            chargeGold(Potion::cost[p]);
            addToInventory(p);
            std::cout << "You purchased a potion of " << Potion::name[p] << ".  You have " << getGold() << " gold left\n";
        } else {
            std::cout << "You can not afford that.\n";
        }
        std::cout << '\n';
    }

    void printInventory()
    {
        std::cout << "Your inventory contains: \n";

        for (auto p: Potion::types)
        {
            int potionCount {getInventory(p)};
            if (potionCount > 0)
            {
                std::cout << potionCount << "x potion of " << Potion::name[p] << ".\n";
            }
            
        }

        std::cout << "You escaped with " << getGold() << " gold remaining.\n";
    }
};

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

Potion::Type getInput()
{
    char input{};
    std::cout << "Enter the number of the potion you'd like to buy, or 'q' to quit: ";
    std::cin >> input;
    ignoreLine();

    if (input == 'q')
    {
        return Potion::maxPotions;
    }

    int num { input - '0' };

    return static_cast<Potion::Type>(num);
}

void shop()
{
    std::cout << "Here is our selection for today\n";

    for (auto p: Potion::types)
        std::cout << p << ") " << Potion::name[p] << " costs " << Potion::cost[p] << '\n';
}

std::string getName()
{
    std::cout << "Enter your name: ";
    std::string name{};

    std::getline(std::cin, name);

    return name;
}

int getRandomNumber(int min, int max)
{
    std::uniform_int_distribution<> die6{min, max};
    return die6(Random::mt);
}

int main()
{
    std::cout << "Welcome to Roscoe's potion emporium!\n";

    std::string_view name{getName()};
    int gold {getRandomNumber(80, 120)};

    Player p1 {gold, name};
    p1.greet();

    bool continueShopping { true };

    while(continueShopping)
    {
        shop();
        Potion::Type potion {getInput()};

        if (potion == Potion::maxPotions)
        {
            continueShopping = false;
            break;
        }
        
        p1.purchasePotion(potion);
    }

    p1.printInventory();

    std::cout << "\nThanks for shopping at Roscoe's potion emporium\n";

    return 0;
}