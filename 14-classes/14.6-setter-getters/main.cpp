#include <iostream>

class Date
{
private:
    int m_year { 2020 };
    int m_month { 10 };
    int m_day { 14 };

public:
    void print()
    {
        std::cout << m_year << '/' << m_month << '/' << m_day << '\n';
    }

    int getYear() const { return m_year; }
    void setYear(int year) { m_year = year; }

    int getMonth() const { return m_month; }
    void setMonth(int month) { m_month = month; }

    int getDay() const { return m_day; }
    void setDay(int day) { m_day = day; }
};

int main()
{
    Date d{};
    d.setYear(2021);

    std::cout << "The year is: " << d.getYear() << '\n';

    return 0;
}
