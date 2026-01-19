#include <iostream>
#include <string>
#include <algorithm>

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool greater(std::string a, std::string b)
{
    return (a < b);
}


int main()
{
    std::cout << "How many names would you like to enter? ";
    std::size_t namesCount{};
    std::cin >> namesCount;

    std::string* array { new std::string[namesCount]{} };

    for (std::size_t i{0}; i < namesCount; ++i)
    {
        std::cout << "Enter name #" << i + 1 << ": ";
        ignoreLine();
        std::string name{};
        std::cin >> name;
        array[i] = name;
    }

    std::sort(array, array + namesCount, greater);

    for (std::string* ptr = array; ptr != array + namesCount; ++ptr)
    {
        std::cout << *ptr << ' ';
    }

    std::cout << '\n';

    return 0;
}