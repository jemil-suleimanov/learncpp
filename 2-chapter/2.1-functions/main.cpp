//  in C++, functions cannot be nested. The following program is not legal:

#include <iostream>

int main()
{
    void foo()
    {
        std::cout << "inside foo \n";
    }

    foo();

    return 0;
}
