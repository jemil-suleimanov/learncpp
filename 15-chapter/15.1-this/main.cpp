#include <iostream>

class Simple
{
private: 
    int m_id{};

public:
    Simple(int id)
        : m_id{ id }
    {}

    int getID() const { return m_id; }
    void setID(int id) { m_id = id; }

    void print() const { std::cout << this->m_id << '\n'; }
};

class Calc
{
private:
    int m_value{};

public:
    Calc& add(int value) { m_value += value; return *this; }
    Calc& sub(int value) { m_value -= value; return *this; }
    Calc& mult(int value) { m_value *= value; return *this; }

    int getValue() const { return m_value; }

    void reset() { *this = {}; }
};

int main()
{
    Simple simple{ 1 };
    simple.setID(2);

    simple.print();

    Calc calc{};

    calc.add(5).sub(3).mult(4);

    std::cout << calc.getValue() << '\n';

    calc.reset();

    std::cout << calc.getValue() << '\n';

    return 0;
}
