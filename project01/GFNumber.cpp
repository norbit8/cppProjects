// GFNumber.cpp
#include "GFNumber.h"
#include "GField.h"
#include <cassert>

// --------------------------------------------------------------------------------------
// This file contains the implementation of the class GField.
// --------------------------------------------------------------------------------------

// ------- private ----------

void GFNumber::checkValidityField(const GFNumber &other) const
{
    assert(this->_field == other._field);
}

long GFNumber::convertNumberToField(long n) const
{
    return ((((n % _field.getOrder()) + _field.getOrder())% _field.getOrder()));
}

// ------------- public --------------

// ------------- ctor ----------------
GFNumber::GFNumber(long n, GField field) : _field(field)
{
    _n = convertNumberToField(n);
}

// ------------ operators ------------
GFNumber &GFNumber::operator=(const GFNumber &other)
{
    this->_n = other.getNumber();
    this->_field = other._field;
    return *this;
}

GFNumber GFNumber::operator+(const GFNumber &other) const
{
    checkValidityField(other);
    return GFNumber(convertNumberToField(other.getNumber() + this->_n), this->_field);
}

GFNumber GFNumber::operator+(long rparam) const
{
    GFNumber gfNum(convertNumberToField(this->_n + rparam), this->_field);
    return gfNum;
}

GFNumber &GFNumber::operator+=(const GFNumber &other)
{
    checkValidityField(other);
    this->_n = convertNumberToField(_n + other.getNumber());
    return *this;
}

GFNumber &GFNumber::operator+=(long rparam)
{
    this->_n = convertNumberToField(_n + rparam);
    return *this;
}

GFNumber &GFNumber::operator-=(long rparam)
{
    this->_n = convertNumberToField(_n - rparam);
    return *this;
}

GFNumber &GFNumber::operator-=(const GFNumber &other)
{
    checkValidityField(other);
    this->_n = convertNumberToField(_n - other.getNumber());
    return *this;
}

GFNumber GFNumber::operator-(const GFNumber &other) const
{
    checkValidityField(other);
    GFNumber gfNum(convertNumberToField(this->_n - other.getNumber()), this->_field);
    return gfNum;
}

GFNumber GFNumber::operator-(long rparam) const
{
    GFNumber gfNum(convertNumberToField(_n - rparam), this->_field);
    return gfNum;
}

GFNumber &GFNumber::operator*=(const GFNumber &other)
{
    checkValidityField(other);
    this->_n =convertNumberToField(_n * other.getNumber());
    return *this;
}

GFNumber &GFNumber::operator*=(long rparam)
{
    this->_n = convertNumberToField(_n * rparam);
    return *this;
}

GFNumber GFNumber::operator*(const GFNumber &other) const
{
    checkValidityField(other);
    GFNumber gfNum(convertNumberToField(this->_n * other.getNumber()), this->_field);
    return gfNum;
}

GFNumber GFNumber::operator*(long rparam) const
{
    GFNumber gfNum(convertNumberToField(this->_n * rparam), this->_field);
    return gfNum;
}

GFNumber &GFNumber::operator%=(const GFNumber &other)
{
    checkValidityField(other);
    this->_n = convertNumberToField(_n % other.getNumber());
    return *this;
}

GFNumber &GFNumber::operator%=(long rparam)
{
    this->_n = convertNumberToField(_n % rparam);
    return *this;
}

GFNumber GFNumber::operator%(const GFNumber &other) const
{
    checkValidityField(other);
    GFNumber gfNum(convertNumberToField(this->_n % other.getNumber()), this->_field);
    return gfNum;
}

GFNumber GFNumber::operator%(long rparam) const
{
    assert(rparam != 0); // modulo 0 is undefined
    GFNumber gfNum(convertNumberToField(this->_n % rparam), this->_field);
    return gfNum;
}

bool GFNumber::operator==(const GFNumber &other) const
{
    return (this->_n == other.getNumber() && this->_field == other.getField());
}

bool GFNumber::operator!=(const GFNumber &other) const
{
    return (!(*this == other));
}

bool GFNumber::operator>=(const GFNumber &other) const
{
    checkValidityField(other);
    return (this->_n >= other.getNumber());
}

bool GFNumber::operator>(const GFNumber &other) const
{
    checkValidityField(other);
    return (this->_n > other.getNumber());
}


bool GFNumber::operator<=(const GFNumber &other) const
{
    checkValidityField(other);
    return (this->_n <= other.getNumber());
}

bool GFNumber::operator<(const GFNumber &other) const
{
    checkValidityField(other);
    return (this->_n < other.getNumber());
}

std::ostream& operator<<(std::ostream &out, const GFNumber& number)
{
    return (out << number.getNumber() << " " << number.getField());
}

std::istream &operator>>(std::istream &in, GFNumber& number)
{
    long n, p, l;
    in >> n >> p >> l;
    GField field(p, l);
    GFNumber newgf(n, field);
    number = newgf;
    return in;
}

// ------------ methods ------------

long *GFNumber::getPrimeFactors() const
{
    // TODO: implement
    return nullptr;
}

void GFNumber::printFactors() const
{
    // TODO: implement
}

bool GFNumber::getIsPrime() const
{
    return GField::isPrime(this->_n);
}