#include <iterator>
#include <iostream>
#include <utility>

int main()
{
    int array[]{30, 50, 20, 10, 40 };
    constexpr int length{ static_cast<int>(std::size(array)) };

    for (int i{ 0 }; i < length - 1; ++i)
    {
        int biggestIndex { i };

        for (int j{ i }; j < length; ++j)
        {
            if(array[j] > array[biggestIndex]) {
                biggestIndex = j;
            }
        }

        std::swap(array[i], array[biggestIndex]);
    }

    for (int index{ 0 }; index < length; ++index)
		std::cout << array[index] << ' ';

	std::cout << '\n';

    return 0;
}