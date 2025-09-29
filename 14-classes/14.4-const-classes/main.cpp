#include <iostream>

struct Date
{
    int year {};
    int month {};
    int day {};

    void print() const
    {
        std::cout << year << '/' << month << '/' << day;
    }
};

void doSomething(const Date& date)
{
    date.print();
}


int main()
{
    const Date today { 2020, 10, 14 };
    today.print();

    doSomething(today);

    return 0;
}