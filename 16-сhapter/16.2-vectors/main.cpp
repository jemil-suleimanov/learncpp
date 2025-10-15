#include <iostream>
#include <vector>

std::vector<int> getNumbers()
{
    std::vector<int> numbers (3);
    std::cout << "Enter 3 integers: ";
    std::cin >> numbers[0] >> numbers[1] >> numbers[2];
    return numbers;
}

void threeInts()
{
    std::vector numbers { getNumbers() };
    int sum = numbers[0] + numbers[1] + numbers[2];
    int product = numbers[0] * numbers[1] * numbers[2];
    std::cout << "The sum is: " << sum << '\n';
    std::cout << "The product is: " << product << '\n';
}

int main()
{
    std::vector<int> primes{ 2, 3, 5, 7 };
    std::vector vowels { 'a', 'e', 'i', 'o', 'u' };

    std::cout << "The first prime number is: " << primes[0] << '\n';

    std::cout << "An int is " << sizeof(int) << " bytes\n";
    std::cout << &(primes[0]) << '\n';
    std::cout << &(primes[1]) << '\n';
    std::cout << &(primes[2]) << '\n';

    threeInts();


    return 0;
}