#include <iostream>

namespace Squares
{
    int perfectSquares[] {0, 1, 4, 9};
}

bool isInRange(int x) {
    for (int square : Squares::perfectSquares) {
        if (square == x) {
            return true;
        }
    }

    return false;
}


int main()
{

    while (true)
    {
        std::cout << "Enter a single digit integer, or -1 to quit: ";
        int x{};
        std::cin >> x;

        if (x == -1) {
            break;
        }

        if (isInRange(x)) {
            std::cout << x << " is a perfect square\n";
        } else {
            std::cout << x << " is not a perfect square\n";
        }
    }

    std::cout << "Bye!\n";
    return 0;
}
