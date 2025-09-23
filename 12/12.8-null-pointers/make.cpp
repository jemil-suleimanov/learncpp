#include <iostream>

int main()
{
    int* ptr { };

    if (ptr == nullptr) {
        std::cout << "ptr is null\n";
    } else {
        std::cout << *ptr << '\n';
    }

    int x {5};
    ptr = &x;

    std::cout << *ptr << '\n';

    return 0;
}
