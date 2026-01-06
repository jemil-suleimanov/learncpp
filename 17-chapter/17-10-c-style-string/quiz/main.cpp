#include <iostream>

int main()
{
    char str[]{"Hello, world!"};

    
    for (int i{0}; i <= 13; i++)
    {
        std::cout << *(str+ i);
    }
    
    std::cout << '\n';

    // const char* ch{ str };

    return 0;
}