// Fractal.cpp

#define SIERPINSKICARPET 1
#define SIERPINSKISIEVE 2
#define CANTORDUST 3

#include "Fractal.h"
#include <iostream>
#include <cmath>

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
    return nullptr;
}

void SierpinskiSieve::draw()
{
    std::cout << "SierpinskiSieve" << std::endl;
}

void SierpinskiCarpet::draw()
{
    int times = ceil(pow(3, _height));
    int lower = ceil(sqrt(times));
    int upper = lower + 3 * (_height-1) - 1;
    std::string toPrint;
    for(int i = 0; i < times; i++)
    {
        for(int j = 0; j < times; j++)
        {
            if(i >= lower && i <= upper && j >= lower && j<= upper)
            {
                toPrint += " ";
            }
            else
            {
                toPrint += (this->_mat[i%3][j%3]);
            }
        }
        toPrint += '\n';
    }
    std::cout << toPrint << std::endl;
}

SierpinskiCarpet::SierpinskiCarpet(int height): _height(height),
  _mat  {{'#', '#', '#'},
         {'#',' ', '#'},
         {'#','#', '#'}}
{}

void CantorDust::draw()
{
    std::cout << "CantorDust" << std::endl;
}