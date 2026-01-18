#include <iterator>
#include <iostream>
#include <utility>

bool bubbleSort(int array[], int length)
{
    bool didSwap { false };
    for (int index{ 0 }; index < length - 1; ++index)
    {
        if (array[index + 1] < array[index])
        {
            std::swap(array[index + 1], array[index]);
            didSwap = true;
        }
    }

    return didSwap;
}

int main()
{
    int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };
    int length{ static_cast<int>(std::size(array)) };
    int s {9};
    int o {0};

    for (int index{ 0 }; index < length; ++index)
    {
        bool didSwap { bubbleSort(array, s) };
        o++;
        if (!didSwap) {
            std::cout << "Early termination on: " << o << "\n";
            break;
        }
        s--;
    }

    for (int index{ 0 }; index < length; ++index)
		std::cout << array[index] << ' ';

	std::cout << '\n';

    return 0;
}