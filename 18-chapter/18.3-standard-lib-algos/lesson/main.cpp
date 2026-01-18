#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

void find()
{
    std::array arr{ 13, 90, 99, 5, 40, 80 };

    std::cout << "Enter a value to search for and replace with: ";
    int search{};
    int replace{};
    std::cin >> search >> replace;

    auto found{ std::find(arr.begin(), arr.end(), search )};

    if (found == arr.end())
    {
        std::cout << "Could not find " << search << '\n';
    }
    else
    {
        *found = replace;
    }

    for (int i : arr)
    {
        std::cout << i << ' ';
    }

    std::cout << '\n';
}

bool containsNut(std::string_view str)
{
    return str.find("nut") != std::string_view::npos;
}

void findIf()
{
    std::array<std::string_view, 4> arr{ "apple", "banana", "walnut", "lemon" };

    auto found{ std::find_if(arr.begin(), arr.end(), containsNut) };

    if(found == arr.end())
    {
        std::cout << "No nuts\n";
    }
    else
    {
        std::cout << "Found " << *found << '\n';
    }
}

void count()
{
    std::array<std::string_view, 5> arr{ "apple", "banana", "walnut", "lemon", "peanut" };

    auto nuts{ std::count_if(arr.begin(), arr.end(), containsNut )};

    std::cout << "Counted " << nuts << " nut(s)\n";
}

bool greater(int a, int b)
{
    return (a > b);
}

void sort()
{
    std::array arr { 13, 90, 99, 5, 40, 80 };

    std::sort(arr.begin(), arr.end(), greater);

    for (int i : arr)
    {
        std::cout << i << ' ';
    }

    std::cout << '\n';
}

void doubleNumber(int& i)
{
    i *= 2;
}

void forEach()
{
    std::array arr {1, 2, 3, 4 };

    std::for_each(arr.begin(), arr.end(), doubleNumber);

    for (int i : arr)
    {
        std::cout << i << ' ';
    }

    std::cout << '\n';
}

int main()
{
    // find();

    findIf();

    count();

    sort();

    forEach();

    return 0;
}
