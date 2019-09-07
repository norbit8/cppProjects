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

char** getMatBase(int type)
{
    if (type == SIERPINSKICARPET)
    {
        char** mat = new char*[3];
        for (int i = 0; i < 3; i++)
        {
            mat[i] = new char[3];
            for(int j = 0; j < 3; j++)
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
        char** mat = new char*[2];
        for (int i = 0; i < 2; i++)
        {
            mat[i] = new char[2];
            for(int j = 0; j < 2; j++)
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
        char** mat = new char*[3];
        for (int i = 0; i < 3; i++)
        {
            mat[i] = new char[3]();
            for(int j = 0; j < 3; j++)
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

char** matHelper(int type, int level)
{
    if(level == 1)
    {
        char** mat = getMatBase(type);
        return mat;
    }
    else
    {
        char** mat = matHelper(type, level - 1);
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
        char **newMat = new char* [times];
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

void SierpinskiSieve::draw()
{
    int times = ceil(pow(2 , _height));
    char** matrix = matHelper(SIERPINSKISIEVE, this->_height);
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


void SierpinskiCarpet::draw()
{
    int times = ceil(pow(3 , _height));
    char** matrix = matHelper(SIERPINSKICARPET, this->_height);
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


void CantorDust::draw()
{
    int times = ceil(pow(3 , _height));
    char** matrix = matHelper(CANTORDUST, this->_height);
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