// GFNumber.cpp
#include "GFNumber.h"
#include "GField.h"

// --------------------------------------------------------------------------------------
// This file contains the implementation of the class GField.
// --------------------------------------------------------------------------------------

// ctor
GFNumber::GFNumber(long n, GField field) : _field(field)
{
    _n = ((((n % _field.getOrder()) + _field.getOrder())% _field.getOrder()));
}

// operator =
GFNumber &GFNumber::operator=(const GFNumber &other) {
    this->_n = other._n;
    this->_field = other._field;
    return *this;
}

