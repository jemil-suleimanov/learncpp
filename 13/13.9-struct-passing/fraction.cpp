#include "fraction.h"
#include <iostream>

struct Fraction
{
    int numerator {};
    int denominator {};
};

void setNumerator(Fraction& fraction)
{
    int numerator{};
    std::cout << "Enter a value for the numerator: ";
    std::cin >> numerator;
    fraction.numerator = numerator;
}

void setDenominator(Fraction& fraction)
{
    int denominator{};
    std::cout << "Enter a value for the denominator: ";
    std::cin >> denominator;
    fraction.denominator = denominator;
}

Fraction getFraction()
{
    Fraction fraction {};

    setNumerator(fraction);
    setDenominator(fraction);

    return fraction;
}

Fraction multiplyFractions(Fraction& first, Fraction& second)
{
    return Fraction { first.numerator * second.numerator, first.denominator * second.denominator };
}

void printFraction(Fraction& fraction)
{
    std::cout << "Your fractions multiplied together: " << fraction.numerator << "/" << fraction.denominator << '\n';
}

void setFractions()
{
    Fraction first {};
    first = getFraction();

    Fraction second {};
    second = getFraction();

    Fraction result {};
    result = multiplyFractions(first, second);

    printFraction(result);
}
