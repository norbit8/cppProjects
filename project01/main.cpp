#include <iostream>
#include "GField.h"
#include "GFNumber.h"

int main()
{
    GField x(7, 1);
    GFNumber num1(5, x);
    GFNumber num2(4, x);
    std::cout << x.gcd(num1 , num2).getNumber() <<  std::endl;
    std::cout << x << std::endl;
    return 0;
}