#include <array>
#include <iostream>

int main()
{
    std::array<double, 365> temperatures {};

    std::cout << temperatures[122];

    std::array<char, 5> greeting { 'h', 'e', 'l', 'l', 'o' };

    std::cout << greeting[1];
}