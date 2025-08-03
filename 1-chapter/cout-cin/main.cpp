#include <iostream>

int main()
{
    std::cout << "Enter two numbers: ";

    int x{};
    std::cin >> x;

    int y{};
    std::cin >> y;

    y = y + 3;

    std::cout << "You entered " << x << " and " << y << "\n";

    return 0;
}