// GFNumber.cpp
#include "GFNumber.h"
#include "GField.h"
#include <cassert>
#include <random>
#include <cmath>

#define FAILED_POLARD -1

// --------------------------------------------------------------------------------------
// This file contains the implementation of the class GField.
// --------------------------------------------------------------------------------------

// ------- private ----------

/**
 * Private method for checking the validity of a given GFNumber by verifying that
 * it has the same field as the current instance.
 * @param other some GFNumber instance
 */
void GFNumber::_checkValidityField(const GFNumber &other) const
{
    assert(this->_field == other._field);
}

/**
 * This private method converts any number to a number from the field.
 * @param n long number.
 * @return
 */
long GFNumber::_convertNumberToField(long n) const
{
    return ((((n % _field.getOrder()) + _field.getOrder()) % _field.getOrder()));
}

// ------------- public --------------

// ------------- ctor ----------------
/**
 * A constructor.
 * @param n A number.
 * @param field The field.
 */
GFNumber::GFNumber(long n , GField field) : _field(field)
{
    _n = _convertNumberToField(n);
}

// ------------- destructor ----------------
/**
 * Destructor.
 */
GFNumber::~GFNumber()
{

}

// ------------ operators ------------
/**
 * Assignment operator.
 * @param other another GFNumber.
 * @return The result GFNumber
 */
GFNumber &GFNumber::operator=(const GFNumber &other)
{
    this->_n = other.getNumber();
    this->_field = other._field;
    return *this;
}

/**
 * Operator +
 * @param other another GFNumber.
 * @return The result GFNumber
 */
GFNumber GFNumber::operator+(const GFNumber &other) const
{
    _checkValidityField(other);
    return GFNumber(_convertNumberToField(other.getNumber() + this->_n) , this->_field);
}

/**
 * Operator + on long number and gfNumber (GFNumber + long).
 * @param rparam long number.
 * @return The result GFNumber
 */
GFNumber GFNumber::operator+(long rparam) const
{
    GFNumber gfNum(_convertNumberToField(this->_n + rparam) , this->_field);
    return gfNum;
}

/**
 * plus-assignment operator, for two GFNumbers.
 * @param other another GFNumber.
 * @return GFNumber instance.
 */
GFNumber &GFNumber::operator+=(const GFNumber &other)
{
    _checkValidityField(other);
    this->_n = _convertNumberToField(_n + other.getNumber());
    return *this;
}

/**
 * plus-assignment operator, for GFNumber and long number.
 * @param rparam long number.
 * @return GFNumber instance.
 */
GFNumber &GFNumber::operator+=(long rparam)
{
    this->_n = _convertNumberToField(_n + rparam);
    return *this;
}

/**
 * minus-assignment operator, for GFNumber and long number.
 * @param rparam long number.
 * @return GFNumber instance.
 */
GFNumber &GFNumber::operator-=(long rparam)
{
    this->_n = _convertNumberToField(_n - rparam);
    return *this;
}

/**
 * minus-assignment operator, for two GFNumbers.
 * @param other another GFNumber.
 * @return GFNumber instance.
 */
GFNumber &GFNumber::operator-=(const GFNumber &other)
{
    _checkValidityField(other);
    this->_n = _convertNumberToField(_n - other.getNumber());
    return *this;
}

/**
 * Operator - on long number and gfNumber (GFNumber - GFNumber).
 * @param other GFNumber.
 * @return The result GFNumber
 */
GFNumber GFNumber::operator-(const GFNumber &other) const
{
    _checkValidityField(other);
    GFNumber gfNum(_convertNumberToField(this->_n - other.getNumber()) , this->_field);
    return gfNum;
}

/**
 * Operator - on long number and gfNumber (GFNumber - long).
 * @param rparam long number.
 * @return The result GFNumber
 */
GFNumber GFNumber::operator-(long rparam) const
{
    GFNumber gfNum(_convertNumberToField(_n - rparam) , this->_field);
    return gfNum;
}

/**
 * multiply-assignment operator, for two GFNumbers.
 * @param other GFNumber instance.
 * @return GFNumber instance.
 */
GFNumber &GFNumber::operator*=(const GFNumber &other)
{
    _checkValidityField(other);
    this->_n = _convertNumberToField(_n * other.getNumber());
    return *this;
}

/**
 * multiply-assignment operator, for GFNumber and long number.
 * @param rparam long number.
 * @return GFNumber instance.
 */
GFNumber &GFNumber::operator*=(long rparam)
{
    this->_n = _convertNumberToField(_n * rparam);
    return *this;
}

/**
 * Operator * on two gfNumber (GFNumber * GFNumber).
 * @param other GFNumber instance.
 * @return The result GFNumber
 */
GFNumber GFNumber::operator*(const GFNumber &other) const
{
    _checkValidityField(other);
    GFNumber gfNum(_convertNumberToField(this->_n * other.getNumber()) , this->_field);
    return gfNum;
}

/**
 * Operator * on long number and gfNumber (GFNumber * long number).
 * @param rparam long numbr.
 * @return The result GFNumber
 */
GFNumber GFNumber::operator*(long rparam) const
{
    GFNumber gfNum(_convertNumberToField(this->_n * rparam) , this->_field);
    return gfNum;
}

/**
 * Operator %= on two gfNumbers (GFNumber %= GFNumber).
 * @param other GFNumber instance.
 * @return The result GFNumber
 */
GFNumber &GFNumber::operator%=(const GFNumber &other)
{
    _checkValidityField(other);
    this->_n = _convertNumberToField(_n % other.getNumber());
    return *this;
}

/**
 * Operator %= on one long number and a gfNumber (GFNumber %= long).
 * @param rparam long number.
 * @return The result GFNumber
 */
GFNumber &GFNumber::operator%=(long rparam)
{
    this->_n = _n % _convertNumberToField(rparam);
    return *this;
}

/**
 * Operator % on two gfNumbers (GFNumber % GFNumber).
 * @param other GFNumber instance.
 * @return The result GFNumber
 */
GFNumber GFNumber::operator%(const GFNumber &other) const
{
    _checkValidityField(other);
    GFNumber gfNum(_convertNumberToField(this->_n % other.getNumber()) , this->_field);
    return gfNum;
}

/**
 * Operator % on long number and gfNumber (GFNumber % long number).
 * @param rparam long number.
 * @return The result GFNumber
 */
GFNumber GFNumber::operator%(long rparam) const
{
    assert(rparam != 0); // modulo 0 is undefined
    GFNumber gfNum(this->_n % _convertNumberToField(rparam) , this->_field);
    return gfNum;
}

/**
 * Equal operator overloading. checks if both GFNumbers are the same.
 * @param other , another GFNumber instance.
 * @return true if they are the same, false otherwise.
 */
bool GFNumber::operator==(const GFNumber &other) const
{
    return (this->_n == other.getNumber() && this->_field.getChar() == other.getField().getChar());
}

/**
 * Not equal operator overloading.
 * @param other , another GFNumber instance.
 * @return true if they are not equal, false otherwise.
 * (Also it validates that the other is from the same field)
 */
bool GFNumber::operator!=(const GFNumber &other) const
{
    return (!(*this == other));
}

/**
 * Greater equal operator overloading.
 * @param other GFNumber.
 * @return true if the n of this is greater or equal to the n of the other GFNumber.
 * (Also it validates that the other is from the same field)
 */
bool GFNumber::operator>=(const GFNumber &other) const
{
    _checkValidityField(other);
    return (this->_n >= other.getNumber());
}

/**
 * Greater than operator overloading.
 * @param other GFNumber.
 * @return true if the number of this instance is greater than the number of the other
 * instance. (Also it validates that the other is from the same field)
 */
bool GFNumber::operator>(const GFNumber &other) const
{
    _checkValidityField(other);
    return (this->_n > other.getNumber());
}

/**
 * Less than and equal to operator overloading.
 * @param other GFNumber.
 * @return true if the number of this instance is less and equal to than the number of the
 * other instance.
 * (Also it validates that the other is from the same field)
 */
bool GFNumber::operator<=(const GFNumber &other) const
{
    _checkValidityField(other);
    return (this->_n <= other.getNumber());
}

/**
 * Less than operator overloading.
 * @param other GFNumber.
 * @return true if the number of this instance is less than the number of the other instance.
 * (Also it validates that the other is from the same field)
 */
bool GFNumber::operator<(const GFNumber &other) const
{
    _checkValidityField(other);
    return (this->_n < other.getNumber());
}

/**
* Operator overloading of "<<".
* @param out ostream reference.
* @param number some GFNumber reference.
* @return ostream reference with the desire output.
*/
std::ostream &operator<<(std::ostream &out , const GFNumber &number)
{
    return (out << number.getNumber() << " " << number.getField());
}

/**
 * Operator overloading of ">>".
 * @param in some istream input.
 * @param number GFNumber refernce.
 * @return istream reference with the desire input.
 */
std::istream &operator>>(std::istream &in , GFNumber &number)
{
    long n , p , l;
    in >> n >> p >> l;
    GField field(p , l);
    GFNumber newgf(n , field);
    number = newgf;
    return in;
}

// ------------ methods ------------

/**
 * This method adds a prime number to the _primeFactors array.
 * it does all the job of allocating memory to the new array and assigning the values of the
 * old array to the new one and then deleting the old array.
 */
void GFNumber::_addPrime(long num)
{
    _primeFactorsLength += 1;
    GFNumber *newPrimeArray = new GFNumber[_primeFactorsLength];
    for (int i = 0; i < _primeFactorsLength - 1; i++)
    {
        newPrimeArray[i] = _primeFactors[i];
    }
    newPrimeArray[_primeFactorsLength - 1] = GFNumber(num , _field);
    delete[] _primeFactors;
    _primeFactors = newPrimeArray;
}

/**
 * This method uses a brute force approach in order to get all the prime
 * factors of n, it uses a principal called "Trail Division"
 * @param n
 */
void GFNumber::_directSearchFactorization(long n)
{
    long i = 2;
    while (i <= floor(sqrt(n)))
    {
        if ((n % i) == 0)
        {
            _addPrime(i);
            n = n / i;
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

/**
 * This method returns a list of longs of all the prime
 * factors of the given GFNumber.
 * @return An array of long representing all the prime factors of the GFNumber.
 */
GFNumber *GFNumber::getPrimeFactors(int *pointer)
{
    // ------------------------ TRIVIAL -----------------------------
    if (getIsPrime() || _n == 0) // if the number is prime just create an array of size 0
    {
        _primeFactors = new GFNumber[0];
        *pointer = 0;
        return _primeFactors;
    }
    // --------------------------------------------------------------
    _primeFactors = new GFNumber[0];
    _primeFactorsLength = 0;
    // try to factor until the number is odd
    long currentNumber = _n;
    while (currentNumber % 2 == 0)
    {
        _addPrime(2); // adds 2 to the prime list
        currentNumber /= 2;
    }
    // try using "Pollard's Rho" algorithm until it gives -1
    long maybePrime = _pollardRho(currentNumber);
    while (GField::isPrime(maybePrime) || maybePrime != -1)
    {
        _addPrime(maybePrime);
        currentNumber /= maybePrime;
        maybePrime = _pollardRho(currentNumber);
    }
    if (currentNumber == 1)
    {
        *pointer = _primeFactorsLength;
        return _primeFactors;
    }
    else // we need to use the iterative method
    {
        _directSearchFactorization(currentNumber);
        *pointer = _primeFactorsLength;
        return _primeFactors;
    }
}

/**
 * Prints all the prime factors
 */
void GFNumber::printFactors()
{
    getPrimeFactors(&_primeFactorsLength);
    if (_primeFactorsLength == 0)
    {
        std::cout << (this->getNumber()) << "=" << (this->getNumber()) << "*1" << std::endl;
    }
    else
    {
        std::cout << this->getNumber() << "=";
        for (int i = 0; i < _primeFactorsLength - 1; i++)
        {
            std::cout << _primeFactors[i].getNumber() << "*";
        }
        std::cout << _primeFactors[_primeFactorsLength - 1].getNumber() << std::endl;
    }
    delete[] _primeFactors;
    _primeFactors = nullptr;
}

/**
 * This method checks if the GFNumber is prime or not.
 * @return True if prime, false otherwise.
 */
bool GFNumber::getIsPrime() const
{
    return GField::isPrime(this->_n);
}

/**
 * This method generates a long random number in the range of [0,supremum]
 * @param supremum A long number.
 * @return Random number uniformly distributed.
 */
long GFNumber::_generateRand(long supremum) const
{
    /* The seed of the random number */
    std::random_device rd;
    /* The random number generator */
    std::default_random_engine generator(rd());
    /* The generator will generate number uniformly distributed */
    std::uniform_int_distribution<long> distribution(1 , supremum - 1);
    return distribution(generator);
}

/**
 * Pollard's Rho Algorithm for factorizing a long number.
 * @param n the number to factorize
 * @return prime factor (or some number multiplying the prime), or -1 if fails
 */
long GFNumber::_pollardRho(long currentNumber) const
{
    if (currentNumber == 1)
    {
        return FAILED_POLARD;
    }
    long x = _generateRand(currentNumber);
    long y = x;
    long p = 1;
    while (p == 1)
    {
        x = _polynomialFunc(x , currentNumber);
        y = _polynomialFunc(_polynomialFunc(y , currentNumber) , currentNumber);
        p = _gcd(std::abs(x - y) , currentNumber);
    }
    if (p == currentNumber)
    {
        return FAILED_POLARD; // Faild to find p with the chosen polynomial
    }
    return p;
}

/**
 * this is the polynomial func f(x) = x^2 + 1 mod n
 * @param x long
 * @param num long
 * @return GFNumber result
 */
long GFNumber::_polynomialFunc(long x , long num) const
{
    return ((x * x) + 1) % num;
}

/**
 * GCD CALCULATOR
 * @param num1 first long num
 * @param num2 second long num
 * @return the gcd of them.
 */
long GFNumber::_gcd(long num1 , long num2) const
{
    while (num1 >= 0 && num2 >= 0)
    {
        if (num1 == 0)
        {
            return num2;
        }
        if (num2 == 0)
        {
            return num1;
        }
        if (num1 == num2)
        {
            return num1;
        }
        if (num1 > num2)
        {
            num1 = (num1 - num2);
        }
        else
        {
            num2 = (num2 - num1);
        }
    }
    return 0;
}