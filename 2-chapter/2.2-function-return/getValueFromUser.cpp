#include <iostream>

int getValueFromUser()
{
    std::cout << "Enter an integer: ";
    int input{};
    std::cin >> input;

    return input;
}

int main()
{
    int num { getValueFromUser() };

    std::cout << num << " doubled is: " << num * 2 << '\n';

    return 0;
}

///

#include <iostream>

int main()
{
    int a(1);
    int b{2};
    int c{};

    std::cout << a << '\n';
    std::cout << b << '\n';
    std::cout << c << '\n';
}