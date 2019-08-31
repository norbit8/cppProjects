// GFNumber.cpp
#include "GFNumber.h"
#include "GField.h"
#include <cassert>
#include <random>
#include <cmath>
#define POLYNOMIAL_FUNC(x) ((x) * (x) + 1)
#define FAILED_POLARD -1

// --------------------------------------------------------------------------------------
// This file contains the implementation of the class GField.
// --------------------------------------------------------------------------------------

// ------- private ----------

void GFNumber::_checkValidityField(const GFNumber &other) const
{
    assert(this->_field == other._field);
}

long GFNumber::_convertNumberToField(long n) const
{
    return ((((n % _field.getOrder()) + _field.getOrder())% _field.getOrder()));
}

// ------------- public --------------

// ------------- ctor ----------------
GFNumber::GFNumber(long n, GField field) : _field(field)
{
    _n = _convertNumberToField(n);
}

// ------------- destructor ----------------
GFNumber::~GFNumber()
{
    if(_allocatedMem)
    {
        delete[] _primeFactors;
    }
}

// ------------ operators ------------
GFNumber &GFNumber::operator=(const GFNumber &other)
{
    this->_n = other.getNumber();
    this->_field = other._field;
    cleanUp();
    return *this;
}

GFNumber GFNumber::operator+(const GFNumber &other) const
{
    _checkValidityField(other);
    return GFNumber(_convertNumberToField(other.getNumber() + this->_n), this->_field);
}

GFNumber GFNumber::operator+(long rparam) const
{
    GFNumber gfNum(_convertNumberToField(this->_n + rparam), this->_field);
    return gfNum;
}

GFNumber &GFNumber::operator+=(const GFNumber &other)
{
    _checkValidityField(other);
    this->_n = _convertNumberToField(_n + other.getNumber());
    cleanUp();
    return *this;
}

GFNumber &GFNumber::operator+=(long rparam)
{
    this->_n = _convertNumberToField(_n + rparam);
    cleanUp();
    return *this;
}

GFNumber &GFNumber::operator-=(long rparam)
{
    this->_n = _convertNumberToField(_n - rparam);
    cleanUp();
    return *this;
}

GFNumber &GFNumber::operator-=(const GFNumber &other)
{
    _checkValidityField(other);
    this->_n = _convertNumberToField(_n - other.getNumber());
    cleanUp();
    return *this;
}

GFNumber GFNumber::operator-(const GFNumber &other) const
{
    _checkValidityField(other);
    GFNumber gfNum(_convertNumberToField(this->_n - other.getNumber()), this->_field);
    return gfNum;
}

GFNumber GFNumber::operator-(long rparam) const
{
    GFNumber gfNum(_convertNumberToField(_n - rparam), this->_field);
    return gfNum;
}

GFNumber &GFNumber::operator*=(const GFNumber &other)
{
    _checkValidityField(other);
    std::cout << "HEY:::!" << _convertNumberToField(_n * other.getNumber()) << std::endl;
    this->_n =_convertNumberToField(_n * other.getNumber());
    cleanUp();
    return *this;
}

GFNumber &GFNumber::operator*=(long rparam)
{
    this->_n = _convertNumberToField(_n * rparam);
    cleanUp();
    return *this;
}

GFNumber GFNumber::operator*(const GFNumber &other) const
{
    _checkValidityField(other);
    GFNumber gfNum(_convertNumberToField(this->_n * other.getNumber()), this->_field);
    return gfNum;
}

GFNumber GFNumber::operator*(long rparam) const
{
    GFNumber gfNum(_convertNumberToField(this->_n * rparam), this->_field);
    return gfNum;
}

GFNumber &GFNumber::operator%=(const GFNumber &other)
{
    _checkValidityField(other);
    this->_n = _convertNumberToField(_n % other.getNumber());
    cleanUp();
    return *this;
}

GFNumber &GFNumber::operator%=(long rparam)
{
    this->_n = _convertNumberToField(_n % rparam);
    cleanUp();
    return *this;
}

GFNumber GFNumber::operator%(const GFNumber &other) const
{
    _checkValidityField(other);
    GFNumber gfNum(_convertNumberToField(this->_n % other.getNumber()), this->_field);
    return gfNum;
}

GFNumber GFNumber::operator%(long rparam) const
{
    assert(rparam != 0); // modulo 0 is undefined
    GFNumber gfNum(_convertNumberToField(this->_n % rparam), this->_field);
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
    _checkValidityField(other);
    return (this->_n >= other.getNumber());
}

bool GFNumber::operator>(const GFNumber &other) const
{
    _checkValidityField(other);
    return (this->_n > other.getNumber());
}


bool GFNumber::operator<=(const GFNumber &other) const
{
    _checkValidityField(other);
    return (this->_n <= other.getNumber());
}

bool GFNumber::operator<(const GFNumber &other) const
{
    _checkValidityField(other);
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

void GFNumber::_addPrime(int num)
{
    _primeFactorsLength += 1;
    GFNumber* newPrimeArray = new GFNumber[_primeFactorsLength];
    for(int i = 0; i < _primeFactorsLength - 1; i++)
    {
        newPrimeArray[i] = _primeFactors[i];
    }
    newPrimeArray[_primeFactorsLength - 1] = GFNumber(num, _field);
    if (_allocatedMem)
    {
        delete[] _primeFactors;
    }
    _allocatedMem = true;
    _primeFactors = newPrimeArray;
}

void GFNumber::_directSearchFactorization(long n)
{
    long i = 2;
    while(i <= floor(sqrt(2)))
    {
        if ((n % i) == 0)
        {
            _addPrime(i);
            n = n / floor(i);
        }
        else
        {
            i = i + 1;
        }
    }
    if (n > 1)
    {
        _addPrime(n);
    }
}

GFNumber *GFNumber::getPrimeFactors(int* pointer)
{
    // ------------------------ TRIVIAL -----------------------------
    if (_factorsReadyFlag)
    {
        return _primeFactors;
    }
    if(getIsPrime() || _n == 0) // if the number is prime just create an array of size 0
    {
        _primeFactors = new GFNumber[0];
        *pointer = 0;
        _factorsReadyFlag = true;
        return _primeFactors;
    }
    // --------------------------------------------------------------
    // try to factor until the number is odd
    long currentNumber = _n;
    while(currentNumber % 2 == 0)
    {
        _addPrime(2); // adds 2 to the prime list
        currentNumber /= 2;
    }
    // try using "Pollard's Rho" algorithm until it gives -1
    long maybePrime = _pollardRho(currentNumber);
    while(GField::isPrime(maybePrime) || maybePrime != -1)
    {
        _addPrime(maybePrime);
        currentNumber /= maybePrime;
        maybePrime = _pollardRho(currentNumber);
    }
    if (currentNumber == 1)
    {
        _factorsReadyFlag = true;
        return _primeFactors;
    }
    else // we need to use the iterative method
    {
        _directSearchFactorization(currentNumber);
        _factorsReadyFlag = true;
        return _primeFactors;
    }
}

void GFNumber::printFactors()
{
    if(_factorsReadyFlag)
    {
        if(_primeFactorsLength == 0)
        {
            std::cout<< (this->getNumber()) << std::endl;
        }
        else
        {
            std::cout << this->getNumber() << "=";
            for(int i = 0; i < _primeFactorsLength - 1; i++)
            {
                std::cout << _primeFactors[i].getNumber() << "*";
            }
            std::cout << _primeFactors[_primeFactorsLength - 1].getNumber() <<std::endl;
        }
    }
    else
    {
        getPrimeFactors(&_primeFactorsLength);
        printFactors();
    }
}

bool GFNumber::getIsPrime() const
{
    return GField::isPrime(this->_n);
}


long GFNumber::_generateRand(long supremum) const
{
    /* The seed of the random number */
    std::random_device rd;
    /* The random number generator */
    std::default_random_engine generator(rd());
    /* The generator will generate number uniformly distributed */
    std::uniform_int_distribution<long> distribution(1,supremum - 1);
    return distribution(generator);
}

long GFNumber::_pollardRho(long currentNumber) const
{
    if (currentNumber == 1)
    {
        return FAILED_POLARD;
    }
    GFNumber x(_generateRand(currentNumber), _field);
    GFNumber y;
    long p = 1;
    while(p == 1)
    {
        x = POLYNOMIAL_FUNC(x);
        y = POLYNOMIAL_FUNC(POLYNOMIAL_FUNC(x));
        p = _field.gcd(GFNumber(std::abs(x.getNumber() - y.getNumber()), _field),
                GFNumber(currentNumber, _field)).getNumber();
    }
    if (p == currentNumber)
    {
        return FAILED_POLARD; // Faild to find p with the chosen polynomial
    }
    return p;
}

void GFNumber::cleanUp()
{
    if(_allocatedMem)
    {
        delete[] _primeFactors;
        _primeFactorsLength = 0;
        _factorsReadyFlag = false;
        _allocatedMem = false;
    }
    else
    {
        _factorsReadyFlag = false;
        _primeFactorsLength = 0;
    }
}