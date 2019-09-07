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
Fractal *Fractal::create(int type , int height)
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

/**
 * This method allocate a memory for 2d matrices representing the base of each
 * fractal.
 * @param type The type of the fractal. (1/2/3).
 * @return The base fractal matrix.
 */
char **getMatBase(int type)
{
    if (type == SIERPINSKICARPET)
    {
        char **mat = new char *[3];
        for (int i = 0; i < 3; i++)
        {
            mat[i] = new char[3];
            for (int j = 0; j < 3; j++)
            {
                if (i == 1 && j == 1)
                {
                    mat[i][j] = ' ';
                }
                else
                {
                    mat[i][j] = '#';
                }
            }
        }
        return mat;
    }
    if (type == SIERPINSKISIEVE)
    {
        char **mat = new char *[2];
        for (int i = 0; i < 2; i++)
        {
            mat[i] = new char[2];
            for (int j = 0; j < 2; j++)
            {
                if (i == 1 && j == 1)
                {
                    mat[i][j] = ' ';
                }
                else
                {
                    mat[i][j] = '#';
                }
            }
        }
        return mat;
    }
    if (type == CANTORDUST)
    {
        char **mat = new char *[3];
        for (int i = 0; i < 3; i++)
        {
            mat[i] = new char[3]();
            for (int j = 0; j < 3; j++)
            {
                mat[i][j] = ' ';
            }
        }
        mat[0][0] = '#';
        mat[0][2] = '#';
        mat[2][0] = '#';
        mat[2][2] = '#';
        return mat;
    }
    return nullptr;
}

/**
 * This function gets a type and a level (= height) of a fractal
 * and creates a matrix (on the heap) which represents the fractal.
 * @param type Type of a fractal (1/2/3).
 * @param level The height of the fractal (1-6).
 * @return An allocated 2d matrix with '#' and ' ' representing the specified fractal.
 */
char **matHelper(int type , int level)
{
    if (level == 1)
    {
        char **mat = getMatBase(type);
        return mat;
    }
    else
    {
        char **mat = matHelper(type , level - 1);
        int rowCol;
        if (type == 2)
        {
            rowCol = 2;
        }
        else
        {
            rowCol = 3;
        }
        int times = ceil(pow(rowCol , level));
        int fillOne = ceil(pow(rowCol , level - 1));
        char **newMat = new char *[times];
        for (int i = 0; i < times; i++)
        {
            newMat[i] = new char[times]();
            for (int j = 0; j < times; j++)
            {
                if (mat[i % fillOne][j % fillOne] == '#' &&
                    mat[(i / fillOne)][(j / fillOne)] == '#')
                {
                    newMat[i][j] = '#';
                }
                else
                {
                    newMat[i][j] += ' ';
                }
            }
        }
        times = ceil(pow(rowCol , level - 1));
        for (int i = 0; i < times; i++)
        {
            delete[] mat[i];
        }
        delete[] mat;
        return newMat;
    }
}

/**
 * The draw function of Sierpinski Sieve (virtual function).
 * this void function draws to cout the fractal.
 */
void SierpinskiSieve::draw()
{
    int times = ceil(pow(2 , _height));
    char **matrix = matHelper(SIERPINSKISIEVE , this->_height);
    for (int i = 0; i < times; i++)
    {
        for (int j = 0; j < times; j++)
        {
            std::cout << matrix[i][j];
        }
        std::cout << "\n";
    }
    // deleting the matrix, to prevent memory leak.
    for (int i = 0; i < times; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

/**
 * The draw function of Sierpinski Carpet (virtual function).
 * this void function draws to cout the fractal.
 */
void SierpinskiCarpet::draw()
{
    int times = ceil(pow(3 , _height));
    char **matrix = matHelper(SIERPINSKICARPET , this->_height);
    for (int i = 0; i < times; i++)
    {
        for (int j = 0; j < times; j++)
        {
            std::cout << matrix[i][j];
        }
        std::cout << "\n";
    }
    // deleting the matrix, to prevent memory leak.
    for (int i = 0; i < times; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

/**
 * The draw function of cantor dust (virtual function).
 * this void function draws to cout the fractal.
 */
void CantorDust::draw()
{
    int times = ceil(pow(3 , _height));
    char **matrix = matHelper(CANTORDUST , this->_height);
    for (int i = 0; i < times; i++)
    {
        for (int j = 0; j < times; j++)
        {
            std::cout << matrix[i][j];
        }
        std::cout << "\n";
    }
    // deleting the matrix, to prevent memory leak.
    for (int i = 0; i < times; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

/**
 * Move assignment.
 * @param other rvalue-reference to another sierpinski sieve.
 * @return this.
 */
SierpinskiSieve &SierpinskiSieve::operator=(SierpinskiSieve && other) noexcept
{
    if (this != &other)
    {
        _height = other._height;
    }
    return *this;
}

/**
 * Assignment operator.
 * @param other reference to another sierpinski sieve.
 * @return this.
 */
SierpinskiSieve &SierpinskiSieve::operator=(const SierpinskiSieve &other)
{
    if (this != &other)
    {
        _height = other._height;
    }
    return *this;
}

/**
 * Move assignment.
 * @param other rvalue-reference to another SierpinskiCarpet.
 * @return this.
 */
SierpinskiCarpet &SierpinskiCarpet::operator=(SierpinskiCarpet && other) noexcept
{
    if (this != &other)
    {
        _height = other._height;
    }
    return *this;
}

/**
 * Assignment operator.
 * @param other reference to another SierpinskiCarpet.
 * @return this.
 */
SierpinskiCarpet &SierpinskiCarpet::operator=(const SierpinskiCarpet &other)
{
    if (this != &other)
    {
        _height = other._height;
    }
    return *this;
}

/**
 * Move assignment.
 * @param other rvalue-reference to another CantorDust.
 * @return this.
 */
CantorDust &CantorDust::operator=(const CantorDust &other)
{
    if (this != &other)
    {
        _height = other._height;
    }
    return *this;
}

/**
 * Assignment operator.
 * @param other reference to another CantorDust.
 * @return this.
 */
CantorDust &CantorDust::operator=(CantorDust && other) noexcept
{
    if (this != &other)
    {
        _height = other._height;
    }
    return *this;
}