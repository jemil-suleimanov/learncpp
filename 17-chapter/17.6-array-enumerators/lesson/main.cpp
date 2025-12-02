#include <array>
#include <iostream>
#include <string>
#include <string_view>

namespace Color
{
    enum Type
    {
        black,
        red,
        blue,
        max_colors
    };

    using namespace std::string_view_literals;
    constexpr std::array colorName { "black"sv, "red"sv, "blue"sv };

    static_assert(std::size(colorName) == max_colors);
}

constexpr std::string_view getColorName(Color::Type color)
{
    return Color::colorName[static_cast<std::size_t>(color)];
}

std::ostream& operator<<(std::ostream& out, Color::Type color)
{
    return out << getColorName(color);
}

std::istream& operator>> (std::istream& in, Color::Type& color)
{
    std::string input {};
    std::getline(in >> std::ws, input);

    for (std::size_t index = 0; index < Color::colorName.size(); ++index)
    {
        if (input == Color::colorName[index]) {
            color = static_cast<Color::Type>(index);
            return in;
        }
    }

    in.setstate(std::ios_base::failbit);

    return in;
}

int main()
{
    auto shirt{ Color::blue };
    std::cout << "Your shirt is " << shirt << '\n';

    std::cout << "Enter a new color";
    std::cin >> shirt;

    if(!std::cin)
        std::cout << "Invalid\n";
    else
        std::cout << "Your shirt is now" << shirt << '\n';

    return 0;
}