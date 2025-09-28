#include <iostream>

struct Employee
{
    int id {};
    int age {};
    double wage {};
};

struct Company
{
    int numberOfEmployees {};
    Employee CEO {};
};

struct Foo
{
    short a {};
    int b {};
    double c {};
};

int main()
{
    Company myCompany { 7, { 1, 32, 55000.0 } };
    std::cout << myCompany.CEO.wage << '\n';

    std::cout << "The size of short is " << sizeof(short) << " bytes\n";
    std::cout << "The size of int is " << sizeof(int) << " bytes\n";
    std::cout << "The size of double is " << sizeof(double) << " bytes\n";

    std::cout << "The size of Foo is " << sizeof(Foo) << " bytes\n";

    return 0;
}
