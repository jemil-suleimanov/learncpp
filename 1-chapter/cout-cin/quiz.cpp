#include <iostream>

// Ask user to enter 3 numbers and prints them
int main()
{
    std::cout << "Enter three numbers: ";
    int a{};
    int b{};
    int c{};

    std::cin >> a >> b >> c;
    std::cout << "You entered " << a << ',' << b << ", and " << c << ".\n";
    return 0;
}
