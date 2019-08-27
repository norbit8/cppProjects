#include <iostream>
#include "GField.h"

int main() {
    GField x(5,1.5);
    std::cout << x.getDegree() << std::endl;
    return 0;
}