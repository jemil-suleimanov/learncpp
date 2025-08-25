#include <iostream>
#include <cmath>

int main()
{
    double x{};
tryAgain:
    std::cout << "Enter a non-negative number: ";
    std::cin >> x;

    if (x < 0.0)
        goto tryAgain;

    std::cout << "the square roof of " << x << " is " << std::sqrt(x) << '\n';
    
    return 0;
}
