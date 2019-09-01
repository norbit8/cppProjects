// GField.cpp

#include "GField.h"
#include "GFNumber.h"
#include <cassert>
#include <cmath>
#include <iostream>

// --------------------------------------------------------------------------------------
// This file contains the implementation of the class GField.
// --------------------------------------------------------------------------------------


/**
 * A constructor.
 * ctor with p and l is default 1.
 * @param p the char of the field.
 */
GField::GField(long p)
{
    p = abs(p);
    assert(p > 1 && isPrime(p));
    this->_p = p;
    this->_l = 1;
}

/**
 * A constructor.
 * ctor with p and l.
 * @param p the char of the field.
 * @param l the degree of the field.
 */
GField::GField(long p , long l)
{
    p = abs(p);
    assert((isPrime(p)) && (l > 0));
    this->_p = p;
    this->_l = l;
}

/**
 * This static method verifies that the number p is prime.
 * @param p is a long number.
 * @return True if p is a prime number, false otherwise.
 */
bool GField::isPrime(long p)
{
    p = abs(p);
    if (p <= 1)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(p); i++)
    {
        if ((p % i) == 0)
        {
            return false;
        }
    }
    return true;
}

/**
 * This method calculates the gcd of two given numbers.
 * @param a GFNumber instance.
 * @param b GFNumber instance.
 * @return GFNumber instance which is the gcd of a and b.
 */
GFNumber GField::gcd(GFNumber a , GFNumber b) const
{
    assert(a.getField() == b.getField() && a.getField() == *this && b.getField() == *this);
    while (a.getNumber() >= 0 && b.getNumber() >= 0)
    {
        if (a.getNumber() == 0)
        {
            return b;
        }
        if (b.getNumber() == 0)
        {
            return a;
        }
        if (a.getNumber() == b.getNumber())
        {
            return a;
        }
        if (a.getNumber() > b.getNumber())
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }
}

/**
 * This method creates a GFNumber from the GField.
 * @param k long number.
 * @return a GFNumber from GField.
 */
GFNumber GField::createNumber(long k) const
{
    GFNumber gfNumber(k , *this);
    return gfNumber;
}

/**
 * Operator overloading of "=".
 * @param other GField instance.
 * @return GField instace
 */
GField &GField::operator=(const GField &other)
{
    this->_p = other._p;
    this->_l = other._l;
    return *this;
}

/**
 * Operator overloading of "<<".
 * @param out ostream reference.
 * @param field reference to a GField instance.
 * @return ostream reference with the desire output.
 */
std::ostream &operator<<(std::ostream &out , const GField &field)
{
    return (out << "GF(" << field.getChar() << "**" << field.getDegree() << ")");
}

/**
 * Operator overloading of ">>".
 * @param in some istream input.
 * @param field GField refernce.
 * @return istream reference with the desire input.
 */
std::istream &operator>>(std::istream &in , GField &field)
{
    long ch , degree;
    in >> ch >> degree;
    assert(ch > 1 && GField::isPrime(ch) && degree > 0);
    field._p = ch;
    field._l = degree;
    return in;
}


/**
 * Operator overloading of "==".
 * @param other GField instance.
 * @return True if the objects are equal, false otherwise.
 * note that instances are equal if the have the same order.
 */
const bool GField::operator!=(const GField &other) const
{
    return (this->getOrder() != other.getOrder());
}

/**
 * Operator overloading of "==".
 * @param other GField instance.
 * @return True if the objects are equal, false otherwise.
 * note that instances are equal if the have the same order.
 */
const bool GField::operator==(const GField &other) const
{
    return (this->getOrder() == other.getOrder());
}

/**
 * Destructor
 */
GField::~GField()
{
    // empty destructor
}
