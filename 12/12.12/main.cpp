#include <iostream>
#include <string>

const std::string& getProgramName()
{
    static const std::string s_programName{ "Calculator" };

    return s_programName;
}

int main()
{
    std::string x { getProgramName() };

    x = "meow line";

    std::cout << "This program is named " << getProgramName();



    return 0;
}
