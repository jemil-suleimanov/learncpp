#include <array>
#include <iostream>

int main()
{
    std::array arr{ 0, 1, 2, 3, 4, 5, 6 };

    auto begin{ &arr[0] };
    auto end{ begin + std::size(arr) };

    for (auto ptr{ begin }; ptr != end; ++ptr)
    {
        std::cout << *ptr << ' ';
    }
    std::cout << '\n';

    auto beginM{ arr.begin() };
    auto endM{ arr.end() };

    for (auto p{ beginM }; p != endM; ++p)
    {
        std::cout << *p << ' ';
    }

    std::cout << '\n';

    std::array range { 1, 2, 3, 4, };
    for (auto i : range)
    {
        std::cout << i << ' ';
    }

    std::cout << '\n';

    return 0;
}
