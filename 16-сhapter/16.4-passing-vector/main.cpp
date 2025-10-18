#include <iostream>
#include <vector>

template <typename T>
void passByRef(const std::vector<T>& arr)
{
    std::cout << arr[0] << '\n';
}

template <typename T>
void printElement(const std::vector<T>& arr, int index)
{
    if (index < 0 || static_cast<std::size_t>(index) >= arr.size())
        std::cout << "error\n";
    else
        std::cout << arr[static_cast<std::size_t>(index)] << '\n';
}   

int main()
{
    std::vector primes{ 2, 3, 5, 7, 11 };
    passByRef(primes);

    std::vector dbl{ 1.1, 2.2, 3.3 };
    passByRef(dbl);

    std::vector v1 { 0, 1, 2, 3, 4 };
    printElement(v1, 2);
    printElement(v1, 5);

    std::vector v2 { 1.1, 2.2, 3.3 };
    printElement(v2, 0);
    printElement(v2, -1);

    return 0;
}
