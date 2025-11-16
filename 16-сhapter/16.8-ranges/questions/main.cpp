#include <iostream>
#include <vector>
#include <string>

template <typename T>
bool isValueInArray(const std::vector<T>& array, const T& value)
{
    bool found { false };
    for (const auto& item : array)
    {
        if (item == value) {
            found = true;
            break;
        }
    }

    return found;
}

int main()
{
    std::vector<std::string_view> names { "Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly" };

    std::cout << "Enter a name: ";
    std::string userName {};
    std::cin >> userName;
    bool found { false };

    for (auto name : names)
    {
        if (name == userName)
        {
            std::cout << userName << " was found\n";
            found = true;
        }
    }

    if (!found) {
        std::cout << userName << " was not found\n";
    }

    std::cout << isValueInArray<std::string_view>(names, userName);

    return 0;
}
