#include <iostream>

struct Employee
{
    int id{};
    int age{};
    double wage{};
};

void printEmployee(const Employee& e)
{
    std::cout << "Id: " << e.id << '\n';
    std::cout << "Age: " << e.age << '\n';
    std::cout << "Wage: " << e.wage << '\n';
}

int main()
{
    Employee joe {1, 34, 65000.0};

    ++joe.age;
    joe.wage = 68000.0;

    printEmployee(joe);

    Employee* ptr{ &joe };
    std::cout << ptr->id << '\n';

    return 0;
}