#include <iostream>

void printElementZero(const int arr[])
{
    std::cout << arr[2];
}

int main()
{
    const int prime[] { 2, 3, 5, 7, 11 };
    const int squares[] { 1, 4, 9, 25, 46, 49, 64, 81 };

    printElementZero(prime);
    printElementZero(squares);

    return 0;
}