// Fractal.cpp

#define SIERPINSKISIEVE 1
#define SIERPINSKICARPET 2
#define CANTORDUST 3

#include "Fractal.h"
#include <iostream>

/**
 * Factory function
 * @param type Fractal type
 * @param height The height of the fractal.
 * @return a pointer to the newly created frcatal, from the correct type.
 */
Fractal *Fractal::Create(int type , int height)
{
    if (type == SIERPINSKISIEVE)
    {
        return (new SierpinskiSieve(height));
    }
    else if (type == SIERPINSKICARPET)
    {
        return (new SierpinskiCarpet(height));
    }
    else if (type == CANTORDUST)
    {
        return (new CantorDust(height));
    }
}


void SierpinskiSieve::draw()
{
    if (this->_height == 1)
    {
        std::cout << "###\n" << "# #\n" << "###\n";
    }
    else
    {
        SierpinskiSieve sieve(_height - 1);
        sieve.draw();
    }
}

void SierpinskiCarpet::draw()
{
    std::cout << "SierpinskiCarpet" << std::endl;
}

void CantorDust::draw()
{
    std::cout << "CantorDust" << std::endl;
}