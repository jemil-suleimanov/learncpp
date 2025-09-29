#include <iostream>

struct Date
{
    int year{};
    int month{};
    int day{};

    void print()
    {
        std::cout << year << '/' << month << '/' << day << '\n';
    }
};

struct IntPair
{
    int x{};
    int y{};

    void print()
    {
        std::cout << "Pair(" << x << ", " << y << ")\n";
    }

    bool isEqual(IntPair& pair)
    {
        return x == pair.x && y == pair.y;
    }
};


int main()
{
    Date today { 2025, 9, 29 };

    today.day = 30;
    today.print();

    IntPair p1 {1, 2};
    IntPair p2 {3, 4};

    std::cout << "p1: ";
    p1.print();

    std::cout << "p2: ";
    p2.print();

    std::cout << "p1 and p1 " << (p1.isEqual(p1) ? "are equal\n" : "are not equal\n");
	std::cout << "p1 and p2 " << (p1.isEqual(p2) ? "are equal\n" : "are not equal\n");

    return 0;
}