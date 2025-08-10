// Write a function called doubleNumber() that takes one integer parameter. The function should return double the value of the parameter.

#include <iostream>

int doubleNumber(int number) {
    return number * 2;
}

int main()
{
    std::cout << "Enter integer: " << '\n';
    int num{};
    std::cin >> num;
    std::cout << doubleNumber(num) << '\n';
}
