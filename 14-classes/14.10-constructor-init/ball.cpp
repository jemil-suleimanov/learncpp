#include <iostream>
#include <string>

class Ball
{
private:
    std::string m_color {};
    int m_radius {};

public:
    Ball(std::string color, int radius)
    : m_color { color }, m_radius { radius }
    {}
};

void setBalls()
{
    Ball blue { "blue", 10.0 };
    print(blue);

    Ball red { "red", 12.0 };
    print(red)
}