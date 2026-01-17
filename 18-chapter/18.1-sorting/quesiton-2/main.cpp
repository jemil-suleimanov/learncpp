#include <iterator>
#include <iostream>
#include <utility>

void bubbleSort(int array[], int length)
{
    for (int index{ 0 }; index < length - 1; ++index)
    {
        if (array[index + 1] < array[index])
        {
            std::swap(array[index + 1], array[index]);
        }
    }
}

int main()
{
    int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };
    constexpr int length{ static_cast<int>(std::size(array)) };

    for (int index{ 0 }; index < length; ++index)
    {
        bubbleSort(array, length);
    }

    for (int index{ 0 }; index < length; ++index)
		std::cout << array[index] << ' ';

	std::cout << '\n';

    return 0;
}