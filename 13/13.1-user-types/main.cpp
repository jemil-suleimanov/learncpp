#include <iostream>

struct Fraction
{
	int numerator {};
	int denominator {};
};

int main()
{
    Fraction x { 5, 3 };
    std::cout << x << '\n';

    return 0;
}