#include <iostream>

int foo(int x)
{
    return x;
}

int main()
{
    int (*fcnPtr)(int){ &foo };

    std::cout << fcnPtr(5) << "\n";
    std::cout << (*fcnPtr)(5) << "\n";

    return 0;
}
