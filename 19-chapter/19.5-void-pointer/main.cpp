#include <cassert>
#include <iostream>

enum class Type
{
    tInt,
    tFloat,
    tCString
};

void printValue(void* ptr, Type type)
{
    switch(type)
    {
        case Type::tInt:
            std::cout << *static_cast<int*>(ptr) << '\n';
            break;
        case Type::tFloat:
            std::cout << *static_cast<float*>(ptr) << '\n';
            break;
        case Type::tCString:
            std::cout << static_cast<char*>(ptr) <<  '\n';
            break;
        default:
            std::cerr << "printValue(): invalid type provided\n";
            assert(false && "type not found");
            break;
    }
}

int main()
{
    int nValue{ 5 };
    float fValue{ 7.5f };
    char szValue[]{ "Mollie" };

    printValue(&nValue, Type::tInt);
    printValue(&fValue, Type::tFloat);
    printValue(&szValue, Type::tCString);

    return 0;
}
