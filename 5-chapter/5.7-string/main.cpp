#include <iostream>
#include <string>

int main()
{
    std::string name {"Alex"};
    name = "Jason";

    std::cout << "My name is: " << name << '\n';

    std::cout << name << " has " << name.length() << " characters\n";

    return 0;
}