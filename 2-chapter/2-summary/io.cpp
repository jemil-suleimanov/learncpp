#include "io.h"
#include <iostream>

int readNumber()
{
    std::cout << "Enter an integer to add: ";
    int num{};
    std::cin >> num;
    return num;
}

void writeAnswer(int result)
{
    std::cout << "The sum is: " << result << '\n';
}
