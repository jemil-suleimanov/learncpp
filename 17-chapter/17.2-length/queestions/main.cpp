#include <array>
#include <iostream>

int main()
{
    std::array greeting { 'h', 'e', 'l', 'l', 'o' };

    std::cout << "The length: " << greeting.size() << '\n';

    std::cout << greeting[1];
    std::cout << greeting.at(1);
    std::cout << std::get<1>(greeting);

    return 0;
}