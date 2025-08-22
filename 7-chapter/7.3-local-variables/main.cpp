#include <iostream>

int main()
{
    std::cout << "Enter an integer: ";
    int smaller {};
    std::cin >> smaller;

    std::cout << "Enter a larger integer: ";
    int larger {};
    std::cin >> larger;

    if (smaller > larger)
    {
        std::cout << "Swapping the values \n";
        int temp { larger };
        larger = smaller;
        smaller = temp;
    }

    std::cout << "The smaller is " << smaller << '\n';
    std::cout << "The larger is " << larger << '\n';

    return 0;
}