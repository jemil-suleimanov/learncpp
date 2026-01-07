#include <iostream>

int main()
{
    const char name[] { "Alex" };

    const char* const color { "Orange" };

    std::cout << name << ' ' << color << '\n';

    char c{ 'Q' };
    std::cout << &c;

    return 0;
}