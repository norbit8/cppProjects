// FractalDrawer.cpp
// --------- includes ---------
#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include "Fractal.h"
#include <fstream>
// --------- constants ---------
#define USAGE "Usage: FractalDrawer <file path>" /** USAGE error message. */
#define SPACE ' ' /** Space char */
#define ALLOC_FAILED "Memory allocation failed" /** The message for failed mem alloc */
#define INVALID_INPUT "Invalid input" /** Invalid input error message */
/** The argument number that the files path should be located at */
static const int FILE_PATH = 1;
static const int INPUT_COUNT = 2; /** Number of input (-1) that the user should provide */
static const char COMMA = ','; /** Comma char */
static const int COLUMNS = 1; /** The number of commas which implies that the columns are 2 */
static const int SIERPINSKISIEVE = 1; /** Sierpinski Sieve code */
static const int SIERPINSKICARPET = 2; /** Sierpinski Carpet code*/
static const int CANTORDUST = 3; /** Cantor Dust code */
static const int FRACTAL_UPPER_BOUND = 6; /** Fractal height upper bound */
static const int FRACTAL_LOWER_BOUND = 1; /** Fractal height lower bound */
static const int MULTI_10 = 10; /** Multiply by 10 the number I construct from input */

/**
 * This method verifies the user input and return false if the program should exit (failure)
 * and true otherwise. (this method also prints the error if ones occur)
 * @param argc Number of arguments that the user provided (the first argument is
 * the name of the running file ("FractalDrawer.cpp")
 * @param argv Arguments "string" array.
 * @return false if the program should fail, true otherwise.
 */
bool checkValidity(int argc , char *argv[])
{
    if (argc != INPUT_COUNT) // Incorrect number of arguments
    {
        std::cerr << USAGE << std::endl;
        return false;
    }
    std::ifstream inFile(argv[FILE_PATH]);
    if (inFile.fail())
    {
        std::cerr << INVALID_INPUT << std::endl;
        return false;
    }
    return true;
}

/**
 * Checks if the file has a legal input, if it will return false.
 * The function also prints the error if one occures.
 * @param line A line from the given file.
 * @return false if the line is illegal, true otherwise.
 */
bool validLine(const std::string &line)
{
    int counter = 0;
    std::string strNum;
    for (char ch : line) // iterating char by char to search for illegal ones.
    {
        if (!isdigit(ch) && ch != COMMA)
        {
            std::cerr << INVALID_INPUT << std::endl;
            return false;
        }
        if (ch == COMMA)
        {
            counter++;
        }
        if (ch == SPACE)
        {
            std::cerr << INVALID_INPUT << std::endl;
            return false;
        }
    }
    if (counter != COLUMNS)
    {
        std::cerr << INVALID_INPUT << std::endl;
        return false;
    }
    return true;
}

/**
 * This method gets the users input for each row, and checks if it matches the given constraints.
 * @param fractalNum The number of the fractal (from 1-3)
 * @param height The height of the fractal (from 1-6)
 * @return true if the constraints are satisfied.
 */
bool verifyInput(int fractalNum , int height)
{
    if (fractalNum != SIERPINSKISIEVE &&
        fractalNum != SIERPINSKICARPET &&
        fractalNum != CANTORDUST)
    {
        std::cerr << INVALID_INPUT << std::endl;
        return false;
    }
    if (!(height >= FRACTAL_LOWER_BOUND && height <= FRACTAL_UPPER_BOUND))
    {
        std::cerr << INVALID_INPUT << std::endl;
        return false;
    }
    return true;
}

int convertStringToInt(std::string &str)
{
    int num = 0;
    for (char ch: str)
    {
        num *= MULTI_10;
        num += ch - '0';
    }
    return num;
}

/**
 * This function gets a line from the file and a refference to the fractals vector
 * and adds a new fractal to the vector.
 * also it check's if the user's input is valid and return true if so, false otherwise.
 * @param line String representing a line.
 * @param fracVec A reference to a vector of Fractals.
 * @return
 */
bool addToVec(const std::string &line , std::vector<Fractal *> &fracVec)
{
    std::string newStr;
    int fracNum = 0 , height = 0;
    for (char ch : line) // iterating char by char to search for illegal ones.
    {
        if (ch == COMMA)
        {
            try
            {
                fracNum = convertStringToInt(newStr);
            }
            catch (...)
            {
                std::cerr << INVALID_INPUT << std::endl;
                return false;
            }
            newStr = "";
        }
        else
        {
            newStr += ch;
        }
    }
    try
    {
        height = convertStringToInt(newStr);
    }
    catch (...)
    {
        std::cerr << INVALID_INPUT << std::endl;
        return false;
    }
    // verify that
    if (!verifyInput(fracNum , height))
    {
        return false;
    }
    Fractal *frac = Fractal::create(fracNum , height); // can throw bad alloc exception
    fracVec.push_back(frac);
    return true;
}

/**
 * Main function. here I load the file and check if its a valid one,
 * then I print all the fractals.
 * @param argc Number of arguments (including the files name)
 * @param argv Array of all the arguments as char*.
 * @return 0 on successful run 1 on failure.
 */
int main(int argc , char *argv[])
{
    if (!checkValidity(argc , argv)) // validity check
    {
        return EXIT_FAILURE;
    }
    // open the file and start loading the data...
    std::vector<Fractal *> fracVec;
    std::ifstream inFile(argv[FILE_PATH]);
    std::string line;
    std::deque<std::string> lst;

    while (std::getline(inFile , line))
    {
        if (!validLine(line))
        {
            return EXIT_FAILURE;
        }
        lst.push_front(line); // load line by line
    }
    for (const std::string &str: lst)
    {
        try
        {
            if (!addToVec(str , fracVec)) // addToVec creates a new vector which is on the heap
            {
                return EXIT_FAILURE;
            }
        }
        catch (std::bad_alloc &e)
        {
            std::cerr << ALLOC_FAILED << std::endl;
            return EXIT_FAILURE;
        }
        catch (...)
        {
            std::cerr << ALLOC_FAILED << std::endl;
            return EXIT_FAILURE;
        }
    }
    for (Fractal *frac: fracVec)
    {
        frac->draw();
        std::cout << std::endl;
        delete frac;
    }
    return 0;
}