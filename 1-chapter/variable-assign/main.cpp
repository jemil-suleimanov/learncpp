#include <iostream>

int main()
{
    // copy init
    int width = 3;
    std::cout << width;

    int length ( 5 );

    std::cout << length;

    [[maybe_unused]] double pi { 3.14159 };
    [[maybe_unused]] double gravity { 9.8 };
    [[maybe_unused]] double phi { 1.61803 };

    std::cout << pi << '\n';
    std::cout << phi << '\n';

    return 0;
}