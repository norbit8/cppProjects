// GFNumber.h

#ifndef GFNUMBER_H
#define GFNUMBER_H
#define DEFAULT_INIT 0
#define DEFAULT_P 2
#define DEFAULT_L 1
#include "GField.h"

/**
 *  A GFNumber class.
 *  This class represents a number from some GField.
 */
class GFNumber
{
private:

    long _n; /** Number representation of the field (after modulo). */

    GField _field; /** The degree of the field. */

    /**
     * This private method converts any number to a number from the field.
     * @param n long number.
     * @return
     */
    long convertNumberToField(long n) const;

    /**
     * Private method for checking the validity of a given GFNumber by verifying that
     * it has the same field as the current instance.
     * @param other some GFNumber instance
     */
    void checkValidityField(const GFNumber& other) const;

public:

    /**
     * A constructor.
     * Default ctor.
     */
    GFNumber():_n(DEFAULT_INIT), _field(DEFAULT_P, DEFAULT_L){};


    /**
     * A constructor.
     * @param n A number.
     * @param field The field.
     */
    GFNumber(long n, GField field);


    /**
     * A constructor.
     * ctor with default field.
     * @param n A number from the field.
     */
    explicit GFNumber(long n):GFNumber(n,GField(DEFAULT_P, DEFAULT_L)){};


    /**
     * A constructor.
     * Copy ctor.
     * @param num GFNumber instance.
     */
    GFNumber(const GFNumber& num):GFNumber(num._n, num._field){};

    /**
     * Gets the number from the specific field.
     * @return _n the number.
     */
    long getNumber() const {return _n;}

    /**
     * Getter for the field of the number.
     * @return The field of the number.
     */
    GField getField() const {return _field;}

    /**
     * This method returns a list of longs of all the prime
     * factors of the given GFNumber.
     * @return An array of long representing all the prime factors of the GFNumber.
     */
    long* getPrimeFactors() const;

    /**
     * Prints all the prime factors
     */
    void printFactors() const;

    /**
     * This method checks if the GFNumber is prime or not.
     * @return True if prime, false otherwise.
     */
    bool getIsPrime() const;

    /**
     * Assignment operator.
     * @param other another GFNumber.
     * @return The result GFNumber
     */
    GFNumber& operator=(const GFNumber& other);

    /**
     * Operator +
     * @param other another GFNumber.
     * @return The result GFNumber
     */
    GFNumber operator+(const GFNumber& other) const;

    /**
     * Operator + on long number and gfNumber (GFNumber + long).
     * @param rparam long number.
     * @return The result GFNumber
     */
    GFNumber operator+(long rparam) const;

    /**
     * plus-assignment operator, for two GFNumbers.
     * @param other another GFNumber.
     * @return GFNumber instance.
     */
    GFNumber& operator+=(const GFNumber& other);

    /**
     * plus-assignment operator, for GFNumber and long number.
     * @param rparam long number.
     * @return GFNumber instance.
     */
    GFNumber& operator+=(long rparam);

    /**
     * minus-assignment operator, for two GFNumbers.
     * @param other another GFNumber.
     * @return GFNumber instance.
     */
    GFNumber& operator-=(const GFNumber& other);

    /**
     * minus-assignment operator, for GFNumber and long number.
     * @param rparam long number.
     * @return GFNumber instance.
     */
    GFNumber& operator-=(long rparam);

    /**
     * Operator - on long number and gfNumber (GFNumber - GFNumber).
     * @param other GFNumber.
     * @return The result GFNumber
     */
    GFNumber operator-(const GFNumber& other) const;

    /**
     * Operator - on long number and gfNumber (GFNumber - long).
     * @param rparam long number.
     * @return The result GFNumber
     */
    GFNumber operator-(long rparam) const;

    /**
     * multiply-assignment operator, for two GFNumbers.
     * @param other GFNumber instance.
     * @return GFNumber instance.
     */
    GFNumber& operator*=(const GFNumber& other);

    /**
     * multiply-assignment operator, for GFNumber and long number.
     * @param rparam long number.
     * @return GFNumber instance.
     */
    GFNumber& operator*=(long rparam);

    /**
     * Operator * on two gfNumber (GFNumber * GFNumber).
     * @param other GFNumber instance.
     * @return The result GFNumber
     */
    GFNumber operator*(const GFNumber& other) const;

    /**
     * Operator * on long number and gfNumber (GFNumber * long number).
     * @param rparam long numbr.
     * @return The result GFNumber
     */
    GFNumber operator*(long rparam) const;

    /**
     * Operator %= on two gfNumbers (GFNumber %= GFNumber).
     * @param other GFNumber instance.
     * @return The result GFNumber
     */
    GFNumber& operator%=(const GFNumber& other);

    /**
     * Operator %= on one long number and a gfNumber (GFNumber %= long).
     * @param rparam long number.
     * @return The result GFNumber
     */
    GFNumber& operator%=(long rparam);

    /**
     * Operator % on two gfNumbers (GFNumber % GFNumber).
     * @param other GFNumber instance.
     * @return The result GFNumber
     */
    GFNumber operator%(const GFNumber& other) const;

    /**
     * Operator % on long number and gfNumber (GFNumber % long number).
     * @param rparam long number.
     * @return The result GFNumber
     */
    GFNumber operator%(long rparam) const;

    /**
     * Equal operator overloading. checks if both GFNumbers are the same.
     * @param other , another GFNumber instance.
     * @return true if they are the same, false otherwise.
     */
    bool operator==(const GFNumber& other) const;

    /**
     * Not equal operator overloading.
     * @param other , another GFNumber instance.
     * @return true if they are not equal, false otherwise.
     * (Also it validates that the other is from the same field)
     */
    bool operator!=(const GFNumber& other) const;

    /**
     * Greater equal operator overloading.
     * @param other GFNumber.
     * @return true if the n of this is greater or equal to the n of the other GFNumber.
     * (Also it validates that the other is from the same field)
     */
    bool operator>=(const GFNumber& other) const;

    /**
     * Greater than operator overloading.
     * @param other GFNumber.
     * @return true if the number of this instance is greater than the number of the other
     * instance. (Also it validates that the other is from the same field)
     */
    bool operator>(const GFNumber& other) const;

    /**
     * Less than and equal to operator overloading.
     * @param other GFNumber.
     * @return true if the number of this instance is less and equal to than the number of the
     * other instance.
     * (Also it validates that the other is from the same field)
     */
    bool operator<=(const GFNumber& other) const;

    /**
     * Less than operator overloading.
     * @param other GFNumber.
     * @return true if the number of this instance is less than the number of the other instance.
     * (Also it validates that the other is from the same field)
     */
    bool operator<(const GFNumber& other) const;

     /**
     * Operator overloading of "<<".
     * @param out ostream reference.
     * @param number some GFNumber reference.
     * @return ostream reference with the desire output.
     */
    friend std::ostream& operator<<(std::ostream& out, const GFNumber& number);

    /**
     * Operator overloading of ">>".
     * @param in some istream input.
     * @param number GFNumber refernce.
     * @return istream reference with the desire input.
     */
    friend std::istream& operator>>(std::istream& in, GFNumber& number);
};

#endif //GFNUMBER_H