#include <iostream>

int main()
{
    int x {};
    const int* ptr { &x };

    std::cout << ptr << ' ' << (ptr + 1) << ' ' << (ptr + 2) << '\n';
}
