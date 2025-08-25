#include <iostream>

int main()
{
    int outer { 5 };

    while (outer > 0)
    {
        int inner { outer };
        while (inner > 0)
        {
            std::cout << inner << ' ';
            --inner;
        }
        std::cout << '\n';
        --outer;
    }

    std::cout << '\n';

    int linesCount { 0 };
    while (linesCount <= 5)
    {
        int inner {5};
        while (inner > 0)
        {
            if (inner <= linesCount) {
                std::cout << inner;
            } else {
                std::cout << ' ';
            }
            
            --inner;
        }
        std::cout << '\n';
        linesCount++;
    }
    

    return 0;
}
