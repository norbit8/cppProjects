// Fractal.h

#ifndef PROJECT02_FRACTAL_H
#define PROJECT02_FRACTAL_H

/**
 * Pure virtual (Abstract) class, representing a Fractal.
 */
class Fractal
{
public:
    /**
     * Pure virtual draw function.
     */
    virtual void draw() = 0;

    /**
     * default destructor.
     */
    virtual ~Fractal() = default;

    /**
     * Factory (Design pattern) of a fractal.
     * @param type Given the type it will construct the according fractal.
     * @param height The height of the fractal.
     * @return
     */
    static Fractal *create(int type , int height);
};

/**
 *  A Sierpinski Sieve type of fractal.
 */
class SierpinskiSieve : public Fractal
{
private:
    int _height; /** The height of the fractal */
public:
    /**
     * I deleted the default ctor because I don't want to allow a user
     * to create a fractal without specifying its height.
     */
    SierpinskiSieve() = delete;

    /**
     * Sierpinski Sieve constructor
     * @param height
     */
    SierpinskiSieve(int height) : _height(height)
    {}

    /**
     * Copy constructor.
     * @param other reference to another sierpinski sieve.
     */
    SierpinskiSieve(const SierpinskiSieve &other) : SierpinskiSieve(other._height)
    {}

    /**
     * Move ctor.
     * @param other rvalue-reference to another sierpinski sieve.
     */
    SierpinskiSieve(SierpinskiSieve && other) noexcept : SierpinskiSieve(other._height)
    {};

    /**
     * Move assignment.
     * @param other rvalue-reference to another sierpinski sieve.
     * @return this.
     */
    SierpinskiSieve &operator=(SierpinskiSieve && other) noexcept;

    /**
     * Assignment operator.
     * @param other reference to another sierpinski sieve.
     * @return this.
     */
    SierpinskiSieve &operator=(const SierpinskiSieve &other);

    /**
     * Virtual draw method which draws the fractal to the cout.
     */
    virtual void draw();

    /**
     * default destructor.
     */
    ~SierpinskiSieve() = default;
};

/**
 *  A Sierpinski Carpet type of fractal.
 */
class SierpinskiCarpet : public Fractal
{
private:
    int _height; /** The height of the fractal */
public:
    /**
     * I deleted the default ctor, because it does'nt make any sense to init a
     * fractal without specifying it's height.
     */
    SierpinskiCarpet() = delete;

    /**
     * Ctor.
     * @param height The height of the fractal
     */
    SierpinskiCarpet(int height) : _height(height)
    {}

    /**
     * Copy ctor.
     * @param other A reference to another instance of SierpinskiCarpet.
     */
    SierpinskiCarpet(const SierpinskiCarpet &other) : SierpinskiCarpet(other._height)
    {}

    /**
    * Move ctor.
    * @param other rvalue-reference to another SierpinskiCarpet.
    */
    SierpinskiCarpet(SierpinskiCarpet && other) noexcept : SierpinskiCarpet(other._height)
    {};

    /**
     * Move assignment.
     * @param other rvalue-reference to another SierpinskiCarpet.
     * @return this.
     */
    SierpinskiCarpet &operator=(SierpinskiCarpet && other) noexcept;

    /**
     * Assignment operator.
     * @param other reference to another SierpinskiCarpet.
     * @return this.
     */
    SierpinskiCarpet &operator=(const SierpinskiCarpet &other);

    /**
     * Virtual draw method which draws the fractal to the cout.
     */
    virtual void draw();

    /**
     * Default dtor.
     */
    ~SierpinskiCarpet() = default;
};

/**
 *  A Cantor Dust type of fractal.
 */
class CantorDust : public Fractal
{
private:
    int _height; /** The height of the fractal */
public:
    CantorDust() = delete;

    /**
     * Ctor.
     * @param height  The height of the fractal
     */
    CantorDust(int height) : _height(height)
    {};

    /**
     * Copy ctor.
     * @param other Reference to another cantor dust fractal.
     */
    CantorDust(const CantorDust &other) : CantorDust(other._height)
    {}

    /**
     * Move ctor.
     * @param other rvalue-reference to another CantorDust.
     */
    CantorDust(CantorDust && other) noexcept : CantorDust(other._height)
    {};

    /**
     * Move assignment.
     * @param other rvalue-reference to another CantorDust.
     * @return this.
     */
    CantorDust &operator=(CantorDust && other) noexcept;

    /**
     * Assignment operator.
     * @param other reference to another CantorDust.
     * @return this.
     */
    CantorDust &operator=(const CantorDust &other);

    /**
     * Virtual draw method which draws the fractal to the cout.
     */
    virtual void draw();

    /**
     * Default destructor.
     */
    ~CantorDust() = default;
};

#endif //PROJECT02_FRACTAL_H