#include <functional>
#include <iostream>

int foo()
{
    return 5;
}

int goo()
{
    return 6;
}

int main()
{
    std::function<int()> fcnPtr{ & foo };

    fcnPtr = &goo;

    std::function fcnPtr2{ & foo };

    return 0;
}