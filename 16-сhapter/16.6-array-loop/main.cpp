#include <iostream>
#include <vector>
#include <limits> 
#include <string>

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool clearFailedExtraction()
{
    // Check for failed extraction
    if (!std::cin) // If the previous extraction failed
    {
        if (std::cin.eof()) // If the stream was closed
        {
            std::exit(0); // Shut down the program now
        }

        // Let's handle the failure
        std::cin.clear(); // Put us back in 'normal' operation mode
        ignoreLine();     // And remove the bad input

        return true;
    }

    return false;
}

template <typename T>
T getInt()
{
    while (true)
    {
        std::cout << "Enter a int number: ";
        T x{};
        std::cin >> x;

        if (clearFailedExtraction())
        {
            std::cout << "Oops, that input is invalid.  Please try again.\n";
            continue;
        }

        if (x < 1 || x > 9)
        {
            std::cout << "Number not in a range.\n";
            continue;
        }

        ignoreLine(); // Remove any extraneous input
        return x;     // Return the value we extracted
    }
}


void printer(const std::vector<int>& vector)
{
    std::size_t length { vector.size() };
    for (std::size_t index{ 0 }; index < length; ++index)
    {
        std::cout << vector[index] << " ";
    }
    std::cout << '\n';
}

void searchInVector(const std::vector<int>& vector, int num)
{
    std::size_t length { vector.size() };
    for (std::size_t index{ 0 }; index < length; ++index)
    {
        if (num == vector[static_cast<size_t>(index)]) {
            std::cout << "The number " << num << " has index " << index << '\n';
            return;
        }
    }
    std::cout << "The number " << num << " was not found\n";
}

template <typename T>
T findMax(const std::vector<T>& vector)
{
    T max { vector[0] };
    std::size_t length { vector.size() };
    for (std::size_t index{ 0 }; index < length; ++index)
    {
        if (vector[index] > max) {
            max = vector[index];
        }
    }
    return max;
}


void fizzBuzz(int value)
{
    std::vector<int> divisors { 3, 5, 7, 11, 13, 17, 19 };
    std::vector<std::string_view> words { "fizz", "buzz", "pop", "bang", "jazz", "pow", "boom" };

    for (int i {1}; i <= value; i++)
    {
        bool match{ false };
        std::size_t length { divisors.size() };
        for (std::size_t j{ 0 }; j < length; ++j)
        {
            if (i % divisors[j] == 0) {
                std::cout << words[j];
                match = true;
            }
        }
        if (!match) {
            std::cout << i;
        }
        std::cout << '\n';
    }
}


int main()
{
    std::vector testScore { 4, 6, 7, 3, 8, 2, 1, 9 };

    int searchIndex = getInt<int>();

    printer(testScore);

    searchInVector(testScore, searchIndex);

        std::vector data1 { 84, 92, 76, 81, 56 };
    std::cout << findMax(data1) << '\n';

    std::vector data2 { -13.0, -26.7, -105.5, -14.8 };
    std::cout << findMax(data2) << '\n';

    fizzBuzz(21);

    return 0;
}