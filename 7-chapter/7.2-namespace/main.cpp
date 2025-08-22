#include "foo.h"
#include "goo.h"

#include <iostream>

int main()
{
    std::cout << Foo::doSomething(4, 3) << '\n';
    std::cout << Goo::doSomething(4, 3) << '\n';

    return 0;
}
