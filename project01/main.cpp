#include <iostream>
#include "GField.h"

int main()
{
    GField x(23, 2.5);
    std::cout << x.getDegree() << std::endl;
    return 0;
}