#include <iostream>

double getNumber()
{
    std::cout << "Enter a double value: ";
    double x{};
    std::cin >> x;

    return x;
}

char getSymbol()
{
    std::cout << "Enter +, -, *, or /: ";
    char symbol{};
    std::cin >> symbol;

    return symbol;
}

void printResult(double x, double y, char symbol)
{
    double result{};

    if (symbol == '+')
        result = x + y;
    else if (symbol == '-')
        result = x - y;
    else if (symbol == '*')
        result = x * y;
    else if (symbol == '/')
        result = x / y;
    else
        return;

    std::cout << x << ' ' << symbol << ' ' << y << " is " << result << '\n';
}

int main()
{
    double x{ getNumber() };
    double y{ getNumber() };
    char symbol { getSymbol() };

    printResult(x, y, symbol);

    return 0;
}