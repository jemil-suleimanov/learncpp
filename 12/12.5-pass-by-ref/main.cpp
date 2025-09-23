#include <iostream>
#include <string>

void printValue(std::string& y)
{
    std::cout << y << '\n';
    y = "New";
}

int main()
{
    std::string x { "Hello, world!" };

    printValue(x);

    std::cout << x << '\n';


    return 0;
}