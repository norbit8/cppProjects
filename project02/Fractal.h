// Fractal.h

#ifndef PROJECT02_FRACTAL_H
#define PROJECT02_FRACTAL_H

/**
 * Pure virtual (Abstract) class, representing a Fractal.
 */
class Fractal
{
public:
    virtual void draw() = 0;

    static Fractal *Create(int type , int height);
};

/**
 *  A Sierpinski Sieve type of fractal.
 */
class SierpinskiSieve : public Fractal
{
private:
    int _height;
public:
    SierpinskiSieve() = delete;

    SierpinskiSieve(int height) : _height(height){};

    virtual void draw();

    ~SierpinskiSieve() = default;
};

/**
 *  A Sierpinski Carpet type of fractal.
 */
class SierpinskiCarpet : public Fractal
{
private:
    int _height;
    SierpinskiSieve *_step[3][3];
public:
    SierpinskiCarpet() = delete;

    SierpinskiCarpet(int height) : _height(height){};

    virtual void draw();

    ~SierpinskiCarpet() = default;
};

/**
 *  A Cantor Dust type of fractal.
 */
class CantorDust : public Fractal
{
private:
    int _height;
public:
    CantorDust() = delete;

    CantorDust(int height) : _height(height){};

    virtual void draw();

    ~CantorDust() = default;
};

#endif //PROJECT02_FRACTAL_H