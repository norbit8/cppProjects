// GField.h

#ifndef PROJECT01_GFIELD_H
#define PROJECT01_GFIELD_H
#include <cmath>
#include <iosfwd>
#include "GFNumber.h"
/**
 *  A GField class.
 *  This class represents a galois field.
 */
class GField
{
private:
    long _l; /** The degree of the field. */
    long _p; /** The char of the field. */
public:

    /**
     * A constructor.
     * Default ctor.
     */
    GField():_p(2),_l(1){};

    /**
     * A constructor.
     * ctor with p and l is default 1.
     */
    GField(long p);

    /**
     * A constructor.
     * ctor with p and l.
     */
    GField(long p, long l);

    /**
     * A constructor.
     * copy ctor.
     */
    GField(const GField& field):GField(field._p, field._l){};

    /**
     * Getter for the char of the field.
     * @return the char of the field (long).
     */
    const long& getChar() const{return _p;}

    /**
     * Getter for the degree of the field.
     * @return the degree of the field (long).
     */
    const long& getDegree() const{return _l;}

    /**
     * Getter for the order of the field.
     * @return  the order of the field (long).
     */
    long getOrder() const{return (long)pow(_p, _l);}

    /**
     * This static method verifies that the number p is prime.
     * @param p is a long number.
     * @return True if p is a prime number, false otherwise.
     */
    static bool isPrime(long p);

    /**
     * This method calculates the gcd of two given numbers.
     * @param a GFNumber instance.
     * @param b GFNumber instance.
     * @return GFNumber instance which is the gcd of a and b.
     */
    GFNumber gcd(GFNumber a, GFNumber b) const;

    /**
     * This method creates a GFNumber from the GField.
     * @param k long number.
     * @return a GFNumber from GField.
     */
    GFNumber createNumber(long k) const;

    /**
     * Operator overloading of "=".
     * @param other GField instance.
     * @return GField instace
     */
    GField& operator= (const GField& other);

    /**
     * Operator overloading of "==".
     * @param other GField instance.
     * @return True if the objects are equal, false otherwise.
     * note that instances are equal if the have the same order.
     */
    const bool operator== (const GField& other);

    /**
     * Operator overloading of "==".
     * @param other GField instance.
     * @return True if the objects are equal, false otherwise.
     * note that instances are equal if the have the same order.
     */
    const bool operator!= (const GField& other);

    /**
     * Operator overloading of "<<".
     * @param out ostream reference.
     * @param field reference to a GField instance.
     * @return ostream reference with the desire output.
     */
    friend std::ostream& operator<< (std::ostream& out, const GField& field);

    /**
     * Operator overloading of ">>".
     * @param in some istream input.
     * @param field GField refernce.
     * @return istream reference with the desire input.
     */
    friend std::istream& operator>> (std::istream& in, GField& field);
};
#endif