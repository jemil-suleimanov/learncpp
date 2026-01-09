#include <array>
#include <iostream>

template <typename T, std::size_t Row, std::size_t Col>
using Array2d = std::array<std::array <T, Col>, Row>;

template <typename T, std::size_t Row, std::size_t Col>
std::size_t rowLength(const Array2d<T, Row, Col> &)
{
    return Row;
}

template <typename T, std::size_t Row, std::size_t Col>
std::size_t colLength(const Array2d<T, Row, Col> &)
{
    return Col;
}

int main()
{
    Array2d<int, 3, 4> arr {{
        {1, 2, 3, 4, },
        {1, 2, 3, 4, },
        {1, 2, 3, 4, },
    }};

    std::cout << "row length: " << rowLength(arr) << '\n';
    std::cout << "col length: " << colLength(arr) << '\n';

    return 0;
}