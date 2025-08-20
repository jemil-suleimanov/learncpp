#include <iostream>
#include <string>
#include <string_view>

std::string getName()
{
    std::string s { "Alex" };
    return s;
}

void printSV(std::string_view str)
{
    std::cout << str << '\n';
}

int main()
{
    printSV("Hello, world!"); // call with C-style string literal

    std::string s2{ "Hello, world!" };
    printSV(s2); // call with std::string

    std::string_view s3{s2};
    s2 = "New";
    printSV(s3);

    std::string_view sv{};

    { // create a nested block
        std::string s{ "Hello, !" }; // create a std::string local to this nested block
        sv = s; // sv is now viewing s
    } // s is destroyed here, so sv is now viewing an invalid string

    std::cout << sv << '\n'; // undefined behavior

    std::string_view name { getName() }; // name initialized with return value of function
    std::cout << name << '\n'; // undefined behavior



    return 0;
}
