#include <iostream>

class Fraction
{
private:
    int m_numerator{ 0 };
    int m_denominator{ 1 };

public:
    Fraction(int numerator=0, int denominator=1)
        : m_numerator {numerator}, m_denominator {denominator}
    {}

    void printFraction() {
        std::cout << m_numerator << '/' << m_denominator << '\n';
    }

    void getFraction()
    {
        int numerator {};
        std::cout << "Enter a value for numerator: ";
        std::cin >> numerator;

        int denominator {};
        std::cout << "Enter a value for denominator: ";
        std::cin >> denominator;
        std::cout << '\n';
        m_numerator = numerator;
        m_denominator = denominator;
    }

    Fraction multiply(const Fraction& fraction) const
    {
        return { m_numerator * fraction.m_numerator, m_denominator * fraction.m_denominator };
    }
};


int main()
{
    std::cout << "freactions called"; 

    Fraction f1{};
    Fraction f2{};

    f1.getFraction();
    f2.getFraction();

    std::cout << "Your fractions multiplied together: ";

    Fraction multiplied {f2.multiply(f1)};

    multiplied.printFraction();

    return 0;
}
