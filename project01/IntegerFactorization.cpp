// IntegerFactorization.cpp

#include <iostream>
#include <random>
#include "GField.h"
#include "GFNumber.h"
#define FAILED 1

/**
 * Main function, gets some user input and creates a GField
 * and a GFNumber and do some math operations on this.
 * @return 0 for successful run and 1 otherwise.
 */
int main()
{
    int a1, b1, c1, a2, b2, c2;
    std::cin >> a1 >> b1 >> c1;
    std::cin >> a2 >> b2 >> c2;
    // Check if the user input is valid
    if(std::cin.fail())
    {
        return FAILED;
    }
    GField f1(b1, c1), f2(b2, c2);
    GFNumber num1(a1, f1), num2(a2, f2);
    std::cout << num1 + num2 << std::endl;
    std::cout << num1 - num2 << std::endl;
    std::cout << num2 - num1 << std::endl;
    std::cout << num1 * num2 << std::endl;
    num1.printFactors();
    num2.printFactors();
    std::cout << "_____________________" << std::endl;
    std:: cout << num2 * num1 << std::endl;
    num1 *= (num2 * num1);
    std::cout << num1.getNumber() << std::endl;
    num1.printFactors();
    num1 = num2;
    num1.printFactors();
    return 0;
}