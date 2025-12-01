#include <array>
#include <iostream>

template <typename T, std::size_t N>
void passByRef(const std::array<T, N>& arr)
{
    std::cout << arr[0] << '\n';
}

template <typename T, std::size_t N>
std::array<T, N> inputArray()
{
    std::array<T, N> arr{};
    std::size_t index { 0 };
    while (index < N)
    {
        std::cout << "Enter value #" << index << ": ";
        std::cin >> arr[index];

        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        ++index;
    }

    return arr;
}

int main()
{
    std::array arr{ 9, 7, 5, 3, 1 };
    passByRef(arr);

    std::array<int, 5> arr2 { inputArray<int, 5>()};

    std::cout << "The value of element 2 is " << arr2[2] << '\n';

    return 0;
}
