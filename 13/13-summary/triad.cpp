#include "triad.h"
#include <iostream>

template <typename T>
struct Triad
{
    T first {};
    T second {};
    T third {};
};

template <typename T>
void print(const Triad<T>& triad)
{
    std::cout << '[' << triad.first << ", " << triad.second << ", " << triad.third << "]";
}

void doTriad()
{
    Triad t1{ 1, 2, 3 };
    print(t1);

    Triad t2{ 1.2, 3.4, 5.6 };
    print(t2);
}