#include <string_view>
#include <iostream>

struct Item
{
    std::string_view name {};
    int gold;
};

int main()
{
    std::array<Item, 4> items {{
        { "sword", 5 },
        { "dagger", 3 },
        { "club", 2 },
        { "spear", 7 },
    }};

    for (auto item : items)
    {
        std::cout << "A " << item.name << " costs " << item.gold << " gold.\n";
    }

    return 0;
}