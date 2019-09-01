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
int main3()
{
    GFNumber num1, num2;
    std::cin >> num1 >> num2;
    // Check if the user input is valid
    if(std::cin.fail())
    {
        return FAILED;
    }
    std::cout << num1 + num2 << std::endl;
    std::cout << num1 - num2 << std::endl;
    std::cout << num2 - num1 << std::endl;
    std::cout << num1 * num2 << std::endl;
    num1.printFactors();
    num2.printFactors();
    return 0;
}