#include <iostream>
#include <vector>

int main()
{
    std::vector arr1 { 1, 2, 3, 4, 5 };
    std::vector arr2 { arr1 };

    arr1[0] = 6;
    arr2[0] = 7;
        
    std::cout << arr1[0] << arr2[0] << '\n';

    return 0;
}
