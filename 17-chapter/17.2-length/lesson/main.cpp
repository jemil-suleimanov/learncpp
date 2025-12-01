#include <array>
#include <iostream>

int main()
{
    constexpr std::array arr { 9.0, 7.2, 5.4, 3.6, 1.8 };
    constexpr int length{ std::size(arr) };

    std::cout << "length: " << arr.size() << '\n';
    std::cout << "length: " << length << '\n';

    return 0;
}