#include <iostream>

template <typename T>
struct Pair
{
    T first{};
    T second{};
};

template <typename T>
constexpr T max(Pair<T> p)
{
    return (p.first < p.second ? p.second : p.first);
}

int main()
{
    Pair<int> p1{5, 6};
    std::cout << max<int>(p1) << " is larger\n";

    Pair<double> p2{1.2, 3.4};
    std::cout << max<double>(p2) << " is larger\n";

    Pair<double> p3{7.8, 9.0};
    std::cout << p3.first << ' ' << p3.second << '\n';

    return 0;
}