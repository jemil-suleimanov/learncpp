#include <iostream>

void print(char ptr[])
{
    std::cout << ptr << '\n';
}

int main()
{
    char str[]{ "string" };
    std::cout << str << '\n';

    print(str);

    str[1] = 'p';
    std::cout << str << '\n';

    return 0;
}
