#include <iostream>
#include <vector>

int factorial(int n)
{
    if (n <= 1)
    {
        return 1;
    }

    return factorial(n - 1);
}

int sumDigits(int x)
{
	if (x < 10)
		return x;

	return sumDigits(x / 10) + x % 10;
}

void printBinary(int x)
{
    int y { x / 2 };

    if (x == 1)
    {
        std::cout << '1';
        return;
    }

    printBinary(y);

    std::cout << x % 2;
}

int main()
{
    for (int i {1}; i <= 7; i++)
    {
        int n {factorial(i)};
        std::cout << "factorial of " << i << ": " << n << '\n';
    }

    std::cout << sumDigits(93427);

    std::cout << '\n';

    printBinary(148);

    std::cout << '\n';

    return 0;
}
