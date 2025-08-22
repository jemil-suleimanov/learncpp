#include <iostream>

int value { 5 }; 

int main()
{
    int apples { 5 };

    {
        std:: cout << apples << '\n';

        int apples { 0 };

        apples = 10;

        std::cout << apples << '\n';
    }

    std::cout << apples << '\n';

    int value { 7 }; // hides the global variable value
    ++value; // increments local value, not global value

    --(::value); // decrements global value, not local value (parenthesis added for readability)

    std::cout << "local variable value: " << value << '\n';
    std::cout << "global variable value: " << ::value << '\n';

    return 0;
}