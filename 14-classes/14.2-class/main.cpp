#include <iostream>

class Date
{
public:
    int m_day {};
    int m_month {};
    double m_year;
};

void printDate(const Date& date)
{
    std::cout << date.m_day << '/' << date.m_month << '/' << date.m_year << '\n';
}

int main()
{
    Date date{ 4, 10, 21};
    printDate(date);

    return 0;
}