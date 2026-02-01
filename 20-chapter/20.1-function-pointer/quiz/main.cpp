#include <functional>
#include <iostream>

using ArithmeticFunction = std::function<int(int,int)>;

int getNumber()
{
    std::cout << "Enter a double value: ";
    int x{};
    std::cin >> x;

    return x;
}

char getOperation()
{
    char op{};

    do
    {
        std::cout << "Enter an operation ('+', '-', '*', '/'): ";
        std::cin >> op;
    }
    while (op!='+' && op!='-' && op!='*' && op!='/');

    return op;
}

int add(int x, int y)
{
    return x + y;
}

int subtract(int x, int y)
{
    return x - y;
}

int multiply(int x, int y)
{
    return x * y;
}

int divide(int x, int y)
{
    return x / y;
}

ArithmeticFunction getArithmeticFunction(char operation)
{
    switch (operation)
    {
    case '+':
        return add;
    case '-':
        return subtract;
    case '*':
        return multiply;
    case '/':
        return divide;
    default:
        return nullptr;
    }
}

int main()
{
    int num1 { getNumber() };
    char operation { getOperation() };
    int num2 { getNumber() };

    ArithmeticFunction math { getArithmeticFunction(operation) };

    if(math)
    {
        std::cout << math(num1, num2) << std::endl;
    }

    return 0;
}