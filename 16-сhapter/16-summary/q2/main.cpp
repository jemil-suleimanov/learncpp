#include <utility>
#include <vector>
#include <iostream>

template<typename T>
std::pair<std::size_t, std::size_t> getMinMax(const std::vector<T>& arr)
{
    std::size_t minIndex { 0 };
    std::size_t maxIndex { 0 };

    std::size_t length { arr.size() };
    for (std::size_t i { 0 }; i < length; ++i)
    {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }

        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }

    return { minIndex, maxIndex };
}

template<typename T>
void printArray(const std::vector<T>& arr)
{
    std::cout << "With array ( ";

    std::size_t length { arr.size() };
    for (std::size_t i { 0 }; i < length; ++i)
    {
        if (i == 0) {
            std::cout << arr[i];
        } else {
            std::cout << ", " << arr[i];
        }
    }

    std::cout << " ):\n";
}

std::vector<int> getArray()
{
    bool shouldStop { false };
    std::vector<int> array {};

    std::cout << "Enter numbers to add ( use -1 to stop): ";
    while(!shouldStop)
    {
        int num {};
        std::cin >> num;
        if (num == -1) {
            shouldStop = true;
            break;
        }
        array.push_back(num);
    }

    return array;
}

int main()
{
    std::vector<int> v1 { 3, 8, 2, 5, 7, 8, 3 };
    auto p1 { getMinMax<int>(v1) };
    
    printArray(v1);
    std::cout << "The min element has index " << p1.first << " and value " << v1[p1.first] << '\n';
    std::cout << "The max element has index " << p1.second << " and value " << v1[p1.second] << '\n';

    std::vector<double> v2 { 5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6 };
    auto p2 { getMinMax<double>(v2) };

    printArray(v2);
    std::cout << "The min element has index " << p2.first << " and value " << v2[p2.first] << '\n';
    std::cout << "The max element has index " << p2.second << " and value " << v2[p2.second] << '\n';

    std::cout << "\n";

    std::vector<int> v3 { getArray() };

    auto p3 { getMinMax<int>(v3) };

    printArray(v3);

    std::cout << "The min element has index " << p3.first << " and value " << v3[p3.first] << '\n';
    std::cout << "The max element has index " << p3.second << " and value " << v3[p3.second] << '\n';

    return 0;
}