#include <iostream>

int main()
{
    std::cout << "Enter a number in range between 0 and 9 \n";
    int x{};
    std::cin >> x;

    if (x == 2)
        std::cout << "The digit is prime \n";
    else if (x == 3)
        std::cout << "The digit is prime \n";
    else if (x == 5)
        std::cout << "The digit is prime \n";
    else if (x == 7)
        std::cout << "The digit is prime \n";
    else
        std::cout << "The digit is not prime \n";

    return 0;
}