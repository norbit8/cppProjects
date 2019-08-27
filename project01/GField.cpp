// GField.cpp

#include "GField.h"
#include <cassert>
#define MINIMUM_
// --------------------------------------------------------------------------------------
// This file contains the implementation of the class GField.
// --------------------------------------------------------------------------------------

// ctor 1
GField::GField(long p) {
    assert(isPrime(p));
    this->_p = p;
}

// ctor 2
GField::GField(long p, long l) {
    assert((isPrime(p) && (l >= 0)));
    this->_p = p;
    this->_l = l;
}

bool GField::isPrime(long p) {
    return true;
}

GFNumber GField::gcd(GFNumber a, GFNumber b) {
    return GFNumber();
}

GFNumber GField::createNumber(long k) {
    return GFNumber();
}

GField &GField::operator=(const GField &other) {
    return *this;
}

std::ostream &operator<<(std::ostream &out, const GField &field) {
    return out;
}

std::istream &operator>>(std::istream &in, const GField &field) {
    return in;
}

const bool GField::operator!=(const GField &other) {
    return false;
}

const bool GField::operator==(const GField &other) {
    return false;
}
