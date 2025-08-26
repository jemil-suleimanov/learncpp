#include <iostream>

int sumTo(int value)
{
    int sum { 0 };
    for (int i{ 1 }; i <= value; i++) {
        sum += i;
    }

    return sum;
}

void fizzBuzz(int value)
{
    for (int i {1}; i <= value; i++)
    {
        bool match{ false };
        if (i % 3 == 0) {
            std::cout << "fizz";
            match = true;
        }
        if (i % 5 == 0) {
            std::cout << "buzz";
            match = true;
        }
        if (i % 7 == 0) {
            std::cout << "pop";
            match = true;
        }
        if (!match) {
            std::cout << i;
        }
        std::cout << '\n';
    }
}

int main()
{
    int limit { 20 };
    for (int i{ 0 }; i <= limit; i++) {
        std::cout << i << ' ';
    }

    std::cout << std::endl;

    int sum { sumTo(5) };

    std::cout << sum << '\n';

    std::cout << '\n';

    fizzBuzz(150);

    return 0;
}