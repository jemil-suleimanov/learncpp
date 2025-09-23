#include <iostream>

int main()
{
    int x{ 5 };
    std::cout << x << '\n';
    std::cout << &x << '\n';

    std::cout << *(&x) << '\n';

    int* ptr { &x };
    
    std::cout << ptr << '\n';

    std::cout << *ptr << '\n';

    int y{ 6 };

    ptr = &y;
    
    std::cout << *ptr << '\n';

    *ptr = 10;

    std::cout << y << '\n';
    std::cout << *ptr << '\n';

    std::cout << sizeof(ptr) << '\n';

    return 0;
}