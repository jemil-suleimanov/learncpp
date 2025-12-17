#include <iostream>

int main()
{
    int arr[30] {};

    int s { 2 };

    arr[s] = 7;
    std::cout << arr[s];

    return 0;
}
