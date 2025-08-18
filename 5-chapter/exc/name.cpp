#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter your full name: ";
    std::string name{};
    std::getline(std::cin >> std::ws, name);

    std::cout << "Enter your age: ";
    int age{};
    std::cin >> age;

    std::cout << "Your age + length of name is: " << age + static_cast<int>(name.size()) << '\n';

    return 0;
}