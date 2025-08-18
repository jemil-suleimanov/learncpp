#include <iostream>

int main()
{
    // OCTAL - starts with -
    int x{ 012 };
    std::cout << x << '\n'; // print 10 as its octal (8) base number

    // HEXIDECIMAL - starts with 0x
    int y { 0xF };
    std::cout << y << '\n'; // print 15 as its hex (15) base number

    long value { 2'132'673'462 }; // much easier to read than 2132673462

    return 0;
}
