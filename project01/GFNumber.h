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
class GFNumber {
private:
    long _n; /** Number representation of the field (after modulo). */
    GField _field; /** The degree of the field. */
    /**
     * This private method converts any number to a number from the field.
     * @param n long number.
     * @return
     */
    long convertNumberToField(long n);
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
    const GFNumber& operator+ (const GFNumber& other) const;
    const GFNumber& operator+= (const GFNumber& other) const;
    const GFNumber& operator-= (const GFNumber& other) const;
    const GFNumber& operator- (const GFNumber& other) const;
    const GFNumber& operator*= (const GFNumber& other) const;
    const GFNumber& operator* (const GFNumber& other) const;
    const GFNumber& operator%= (const GFNumber& other) const;
    const GFNumber& operator% (const GFNumber& other) const;

    const GFNumber& operator== (const GFNumber& other) const;
    const GFNumber& operator!= (const GFNumber& other) const;

    const GFNumber& operator>= (const GFNumber& other) const;
    const GFNumber& operator> (const GFNumber& other) const;
    const GFNumber& operator<= (const GFNumber& other) const;
    const GFNumber& operator< (const GFNumber& other) const;



     /**
     * Operator overloading of "<<".
     * @param out ostream reference.
     * @param number some GFNumber reference.
     * @return ostream reference with the desire output.
     */
    friend std::ostream& operator<< (std::ostream& out, const GFNumber& number);

    /**
     * Operator overloading of ">>".
     * @param in some istream input.
     * @param number GFNumber refernce.
     * @return istream reference with the desire input.
     */
    friend std::istream& operator>> (std::istream& in, GFNumber& number);
};

#endif //GFNUMBER_H