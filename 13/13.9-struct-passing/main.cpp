#include "ad.h"
#include "fraction.h"
#include <iostream>

struct Employee
{
    int id {};
    int age {};
    double wage;
};

struct Point3d
{
    double x {0.0};
    double y {0.0};
    double z {0.0};
};

void printEmployee(const Employee& employee)
{
    std::cout << "ID: " << employee.id << '\n';
    std::cout << "Age: " << employee.age << '\n';
    std::cout << "Wage: " << employee.wage << '\n';
}

Point3d getZeroPoint()
{
    return Point3d { 0.0, 0.0, 0.0 };
}

int main()
{
    Employee joe { 14, 32, 24.15 };

    printEmployee(joe);

    std::cout << '\n';

    printEmployee(Employee { 15, 28, 18.27 });
    printEmployee({ 12, 39, 17.27 });

    Point3d zero { getZeroPoint() };

    if (zero.x == 0.0 && zero.y == 0.0 && zero.z == 0.0)
        std::cout << "The point is zero\n";
    else
        std::cout << "The point is not zero\n";

    getAds();

    setFractions();

    return 0;
}
