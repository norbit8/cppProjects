#include <iostream>
#include "GField.h"
#include "GFNumber.h"


int main()
{
    GField x(3, 1);
    GField y(2,2);
    GField z(2,30);
    GFNumber noobnoob1(70000000, z);
    GFNumber noobnoob2(3030, z);
    std::cout << z.getOrder() << std::endl;
    std::cout << z.gcd(noobnoob1, noobnoob2).getNumber() << std::endl;
    GFNumber num3(3,y);
    GFNumber num1(5, x);
    GFNumber num2(4, x);
    // --- gcd test (1) ---
    std::cout << "gcd test (1): " << (x.gcd(num1 , num2).getNumber() == 1 ? "Pass" : "Fail") <<
    std::endl;
    // --- GField print test ---
    std::cout << "GField print test: " << x << " needs to be equal to GF(3**1)" << std::endl;
    // --- GFNumber plus operator test ---
    std::cout << "GFNumber plus operator test (1): " << ((num1 + num2).getNumber() == 0 ? "Pass" :
    "Fail") << std::endl;
    num1= GFNumber(1, x);
    num2= GFNumber(-2, x);
    std::cout << "GFNumber plus operator test (2): " << ((num1 + num2).getNumber() == 2 ? "Pass" :
                                                        "Fail") << std::endl;

    std::cout << "GFNumber plus operator test (3): " << ((num1 + 2).getNumber() == 0 ? "Pass" :
                                                         "Fail") << std::endl;



    return 0;
}