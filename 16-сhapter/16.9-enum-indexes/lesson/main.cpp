#include <vector>

namespace Students
{
    enum Names
    {
        kenny,
        kyle,
        stan,
        butters,
        cartman,
        max_students
    };
}

int main()
{
    std::vector<int> testScores { 78, 94, 66, 77, 14 };

    testScores[Students::stan] = 76;

    return 0;
}
