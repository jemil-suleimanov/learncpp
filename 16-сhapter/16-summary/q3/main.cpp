#include <vector>
#include <iostream>
#include <cassert>

namespace Items
{
    enum Type
    {
        healthPotion,
        torch,
        arrow,
        maxItems
    };
}

constexpr std::string_view getItemName(Items::Type item, bool isPlural)
{
    switch (item)
    {
        case Items::healthPotion: return isPlural ? "health potions" : "health potion";
        case Items::torch: return isPlural ? "torches" : "torch";
        case Items::arrow: return isPlural ? "arrows" : "arrow";
        default:    return "???";
    }
}

int countItems(const std::vector<int>& items)
{
    int totalCount { 0 };
    for (int item : items)
    {
        totalCount += item;
        totalCount += item;
    }

    return totalCount;
}

void printAllItems(const std::vector<int>& items)
{
    std::size_t length { items.size() };
    for (std::size_t index{ 0 }; index < length; ++index)
    {
        auto item { static_cast<Items::Type>(index) };
        std::cout << "You have " << items[index] << " " << getItemName(item, items[index] > 1) << '\n';
    }
}

int main()
{
    std::vector<int> playerItems { 1, 5, 10};
    assert(playerItems.size() == Items::maxItems && "Not all items provided");

    printAllItems(playerItems);
    std::cout << "You have " << countItems(playerItems) << " total items\n";

    return 0;
}