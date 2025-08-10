// Write a program that asks the user to enter a number, and then enter a second number.
// The program should tell the user what the result of adding and subtracting the two numbers is.
#include <iostream>

int main()
{
    std::cout << "Enter an integer: ";
    int first{};
    std::cin >> first;

    std::cout << "Enter another integer: ";
    int second{};
    std::cin >> second;

    std::cout << first << " + " << second << " is " << first + second << ".\n";
    std::cout << first << " - " << second << " is " << first - second << ".\n";

    return 0;
}