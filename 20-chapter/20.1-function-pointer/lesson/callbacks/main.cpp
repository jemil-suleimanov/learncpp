#include <utility>
#include <iostream>

void selectionSort(int* array, int size, bool (*comparisonFcn)(int, int))
{
    if (!array || !comparisonFcn)
    {
        return;
    }

    for (int startIndex{ 0 }; startIndex < (size - 1); ++startIndex)
    {
        int bestIndex{ startIndex };

        for (int currentIndex{ startIndex + 1}; currentIndex < size; ++currentIndex)
        {
            if(comparisonFcn(array[bestIndex], array[currentIndex]))
            {
                bestIndex = currentIndex;
            }
        }

        std::swap(array[startIndex], array[bestIndex]);
    }
}

bool ascending(int x, int y)
{
    return x > y;
}

bool descending(int x, int y)
{
    return x < y;
}

void printArray(int* array, int size)
{
    if(!array)
    {
        return;
    }

    for (int index{ 0 }; index < size; ++index)
    {
        std::cout << array[index];
    }

    std::cout << '\n';
}

int main()
{
    int array[9]{ 3, 7, 9, 5, 6, 1, 8, 2, 4 };

    selectionSort(array, 9, descending);
    printArray(array, 9);

    selectionSort(array, 9, ascending);
    printArray(array, 9);
}