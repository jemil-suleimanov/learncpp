#include <format>
#include <iostream>
#include <print>

int main()
{
    std::cout << std::format("{:b\n}", 0b1010);
    std::cout << std::format("{:#b\n}", 0b1010);    

    std::println("{:b} {:b#}", 0b10101, 0b1010);

    return 0;
}