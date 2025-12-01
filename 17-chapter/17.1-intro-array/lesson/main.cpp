#include <array>
#include <vector>
#include <iostream>

int main()
{
    constexpr std::array<int, 5> prime { 2, 3, 5, 7, 11 };

    for (int num : prime ) {
        std::cout << num;
    }
}
