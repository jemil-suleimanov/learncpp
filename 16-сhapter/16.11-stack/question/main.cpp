#include <vector>
#include <iostream>
#include <string>

void printStack(const std::vector<int>& stack)
{
    std::cout << "(Stack:";
    if (stack.size() == 0) {
        std::cout << " empty)\n";
        return;
    }

    for (auto element : stack)
    {
        std::cout << element << ' ';
    }
}

void updateStack(std::vector<int>& stack, std::string command, int value)
{
    if (command == "Push")
    {
        stack.push_back(value);
        std::cout << "Push " << value << " ";
    } else if (command == "Pop")
    {
        stack.pop_back();
        std::cout << "Pop ";
    }

    printStack(stack);
    std::cout << "\n";
}

int main()
{
    std::vector<int> stack{};
    printStack(stack);

    updateStack(stack, "Push", 1);
    updateStack(stack, "Push", 2);
    updateStack(stack, "Push", 3);
    updateStack(stack, "Pop", 0);
    updateStack(stack, "Push", 4);
    updateStack(stack, "Pop", 4);
    updateStack(stack, "Pop", 4);
    updateStack(stack, "Pop", 4);

    return 0;
}