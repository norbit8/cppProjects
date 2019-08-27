// GField.cpp

#include "GField.h"
#include <cassert>
#include <cmath>
// --------------------------------------------------------------------------------------
// This file contains the implementation of the class GField.
// --------------------------------------------------------------------------------------

// ctor 1
GField::GField(long p)
{
    assert(p >= 1 && isPrime(p));
    this->_p = p;
}

// ctor 2
GField::GField(long p, long l)
{
    assert((isPrime(p) && (l >= 0)));
    this->_p = p;
    this->_l = l;
}

bool GField::isPrime(long p)
{
    p = std::abs(p);
    if (p <= 1)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(p); i++)
    {
        if ((p % i) == 0) return false;
    }
    return true;
}

GFNumber GField::gcd(GFNumber a, GFNumber b)
{
    return GFNumber();
}

GFNumber GField::createNumber(long k)
{
    return GFNumber();
}

GField &GField::operator=(const GField &other)
{
    this->_p = other._p;
    this->_l = other._l;
    return *this;
}

std::ostream &operator<<(std::ostream &out, const GField &field)
{
    //out <<
    return out;
}

std::istream &operator>>(std::istream &in, const GField &field)
{
    return in;
}

const bool GField::operator!=(const GField &other)
{
    return (this->_p != other._p || this->_l != other._l);
}

const bool GField::operator==(const GField &other)
{
    return (this->_p == other._p && this->_l == other._l);
}