#include <cmath>
#include <iostream>

template <double D>
double getSqrt() {
    static_assert(D >= 0.0, "getSqrt(): D must be non-negative");

    if constexpr (D >= 0) {
        return std::sqrt(D);
    }

    return 0.0;
}


template <int N>
constexpr int factorial()
{
    int sum { 1 };
    std::cout << N << '\n';
    for (int i {1}; i <= N;i++) {
        std::cout << i << '\n';
        sum = i * sum;
    }

    std::cout << sum << '\n';

    return sum;
    
}

int main()
{
    std::cout << getSqrt<5.0>() << '\n';
    //std::cout << getSqrt<-5.0>() << '\n';

    int res { factorial<4>() };

    std::cout << res << '\n';

    return 0;
}
