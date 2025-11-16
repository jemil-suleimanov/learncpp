#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<int> fibonacci { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };

    for (auto num : fibonacci)
    {
        std::cout << num << ' ';
    }

    std::cout << '\n';

    std::vector<std::string> words { "peter", "likes", "frozen", "yogurt" };

    for (const auto& word : words)
    {
        std::cout << word << ' ';
    }

    std::cout << '\n';

    return 0;
}
